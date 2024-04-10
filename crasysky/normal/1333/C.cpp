#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5;
ll s[N]; int pre[N],q[N]; map<ll,int> mp;
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n){ int x; scanf("%d",&x); s[i]=s[i-1]+x; }
	mp[0]=0; 
	rep(i,1,n) pre[i]=mp.count(s[i])?mp[s[i]]:-1,mp[s[i]]=i;
	int l=1,r=0; ll ans=0;
	for (int i=1,j=0;i<=n;++i){
		while (l<=r&&pre[q[r]]<=pre[i]) --r;
		q[++r]=i;
		while (j<=pre[q[l]]){
			++j; if (l<=r&&q[l]<j) ++l;
		}
		ans+=i-j;
	}
	printf("%lld\n",ans);
	return 0;
}