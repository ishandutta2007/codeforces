#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn=100005;

struct line{
	int l,r;
};
int n,m;
int v[maxn];
line h[maxn];
int r[maxn];
int rc;
long long ans;

signed main(){
	int _;
	cin>>n>>m;
	ans=n+m;
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+1+n);
	for(int i=1;i<=m;i++) cin>>h[i].l>>h[i].r>>_;
	for(int i=1;i<=m;i++){
		if(h[i].l==1){
			rc++;
			r[rc]=h[i].r;
		}
	}
	sort(r+1,r+1+rc);
	int chp=rc;
	int crp=1000000000;
	long long cans=n;
	for(int i=n+1;i>=1;i--){
		while(r[chp]>=crp&&chp!=0){
			chp--;
			cans++;
		}
		if(cans<ans) ans=cans;
		cans--;
		crp=v[i-1];
	}
	cout<<ans;
	return 0;
}