#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; int a[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	ll ans=0; int t=0,k=0;
	rep(i,1,n){
		int b=k==0?a[i]:a[i]-(2*k-t);
		if (b%2==0){
			ans+=b/2;
			if (t==1&&k) --k;
			if (k) t^=1; else t=0;
		} 
		else{
			ans+=(b-1)/2;
			if (t==0) ++k;
			t^=1;
		}
		k=min(k,(a[i+1]+t)/2),ans+=k;
	}
	printf("%lld\n",ans);
	return 0;
}