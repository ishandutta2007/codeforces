#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, ans[N];
ll a[N], s[N];
void modify(int x, int y){
	while(x<=n) s[x]+=y, x+=x&-x;
}
ll query(int x){
	ll ans=0;
	while(x) ans+=s[x], x-=x&-x;
	return ans;
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), modify(i, i);
	for(int i=n; i; --i){
		int l=1, r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(mid-1)<=a[i]) ans[i]=mid, l=mid+1; else r=mid-1;
		}
		modify(ans[i], -ans[i]);
	}
	for(int i=1; i<=n; ++i) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}