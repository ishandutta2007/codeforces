#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int mod=10;
int make(int a){
	while(a<0)a+=mod;
	return a%mod;
}
lli die[10];
void how(lli a){
	set<int> mods;
	int b=a;
	lli am=0;
	die[b]=min(die[b],am);
	while(!mods.count(b)){
		mods.insert(b);
		b=(b+a)%10;
		am+=1;
		die[b]=min(die[b],am);
	}
}
lli mindie[10][10][10];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int made[s.size()];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)for(int k=0;k<10;k++)mindie[i][j][k]=LLONG_MAX;
    for(int i=0;i<=9;i++){
	    for(int j=0;j<=9;j++) {
		    for(int kek=0;kek<10;kek++)die[kek]=INT_MAX;
		    how(i);
		    how(j);
		    for(int x=0;x<10;x++){
		    	for(int y=0;y<10;y++) {
		    		if(die[x]!=INT_MAX&&die[y]!=INT_MAX) {
						mindie[i][j][(x+y)%10]=min(mindie[i][j][(x+y)%10],die[x]+die[y]+1);
				    }
				}
		    	if(die[x]!=INT_MAX) {
				    mindie[i][j][x] = min(mindie[i][j][x], die[x]);
			    }
		    }
		    }
	    }
	for (int i = 1; i < s.size(); i++)made[i]=make(s[i]-s[i-1]);
    for(int x=0;x<=9;x++) {
    	for(int y=0;y<=9;y++) {
    		lli am=0;
    		bool bad=false;
		    for (int i = 1; i < s.size(); i++) {
				lli te=mindie[x][y][made[i]];
				if(te==LLONG_MAX){
					printf("-1 ");
					bad=true;
					break;
				}
				assert(te>=0);
				am+=te;
		    }
		    if(!bad)printf("%lli ",am);
	    }
    	printf("\n");
    }
    return 0;
}