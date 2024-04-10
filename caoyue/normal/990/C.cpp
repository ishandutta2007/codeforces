#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
const ll N=3e5+7;
ll f[N],b[N];
ll n,maxn=0;
char s[N];
int main(){
	ll ans=0;
	scanf("%I64d",&n);
	rep(i,n){
		scanf("%s",s+1);
		ll now=0,k=strlen(s+1);
		maxn=max(maxn,k);
		bool flag=1;
		rep(i,k){
			if(s[i]=='(')now++;
			else now--;
			if(now<0){
				flag=0;
				break;
			}
		}
		if(flag)f[now]++;
		now=0;
		flag=1;
		for(ll i=k;i;i--){
			if(s[i]==')')now++;
			else now--;
			if(now<0){
				flag=0;
				break;
			}
		}
		if(flag)b[now]++;
	}
	rep0(i,maxn+1)ans=ans+f[i]*b[i];
	printf("%I64d\n",ans);
	return 0;
}