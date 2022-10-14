#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    int getto[s.size()]={};
	int gettorever[s.size()+1]={};
    int getm=-1;
    for(int i=0;i<s.size();i++){
    	if(getm+1<t.size()&&s[i]==t[getm+1]){
    		getm++;
    	}
    	getto[i]=getm;
    }
	getm=(int)t.size();
	for(int i=(int)s.size()-1;i>=0;i--){
		if(getm>0&&s[i]==t[getm-1]){
			getm--;
		}
		gettorever[i]=getm;
	}
	gettorever[s.size()]=t.size();
	int ma=0;
	int loc=0;
	for(int i=0;i<s.size();i++){
		int curget=(i==0?-1:getto[i-1]);
		while(loc<s.size()&&gettorever[loc+1]<=curget+1)loc++;
		ma=max(ma,loc-i);
	}
	printf("%d\n",ma);
    return 0;
}