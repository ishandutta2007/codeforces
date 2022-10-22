#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5,TP=100;
typedef long long ll;
vector<int> pos;
char s[MAX_N];
int n;
ll ans=0;
int solve(int x,int y){
	return max(0,x/y-TP);
}
void solve1(){
	for(int i=1;i<=(int)pos.size()-2;++i)
		for(int t=pos[i-1]+1;t<=pos[i];++t)
			for(int j=i;j<=(int)pos.size()-2&&j<=i+n/TP+1;++j){
				int key=solve(pos[j+1]-t,j-i+1)-solve(pos[j]-t,j-i+1);
				ans+=key;
		//		if(key>0) printf("(%d %d %d)",t,pos[j],key);
//				printf("<%d %d %d>",pos[j+1]-t,pos[j]-t+1,j-i+1);
			}
//	printf("|%lld|",ans);
}
int mp[(int)2e7+5];
void solve2(){
	memset(mp,0,sizeof(mp));
	for(int k=1;k<=TP;++k){
		ll sum=0;
		mp[sum+n]++;
		for(int i=1;i<=n;++i){
			if(s[i]=='0') sum--;
			else sum+=k-1;
			ans+=mp[sum+n]; 
			mp[sum+n]++;
		}
		sum=0; mp[sum+n]=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0') sum--;
			else sum+=k-1;
			mp[sum+n]=0;
		}
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1); pos.push_back(0);
	for(int i=1;i<=n;++i)
		if(s[i]=='1') pos.push_back(i);
	pos.push_back(n+1);
	solve1();
	solve2();
	printf("%lld\n",ans);
	return 0;
}