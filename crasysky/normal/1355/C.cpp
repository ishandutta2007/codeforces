#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6;
ll S(int l,int r){ return l>r?0:(ll)(l+r)*(r-l+1)/2; }
int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	ll ans=0;
	rep(z,c,d){
		int t=max(z-(a+b),0);//max(min(z-y,b),a-1) y=b..c
		ans+=(ll)(c-b+1)*b;
		int p=min(max(z-b,b-1),c),q=min(max(z-a,p),c);
		ans-=(ll)(p-b+1)*b+S(z-q,z-(p+1))+(ll)(c-q)*(a-1);
	}
	cout<<ans<<endl;
	return 0;
}