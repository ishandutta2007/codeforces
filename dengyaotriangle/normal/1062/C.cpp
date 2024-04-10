#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
const long long mdl=1000000007;

int d[maxn];
int pfx[maxn];
int n,q;

long long sq2[maxn];

int main(){
	cin>>n>>q;
	char _[maxn];
	cin>>_;
	for(int i=1;i<=n;i++) d[i]=_[i-1]-'0';
	for(int i=1;i<=n;i++) pfx[i]=pfx[i-1]+d[i];
	sq2[0]=1;
	for(int i=1;i<maxn;i++) sq2[i]=(sq2[i-1]*2ll)%mdl;
	while(q--){
		int l,r;
		cin>>l>>r;
		long long ans=0;
		long long c1=pfx[r]-pfx[l-1];
		long long c0=r-l+1-c1;
		ans=((sq2[c1]-1+mdl)%mdl+(((sq2[c1]-1ll+mdl)%mdl)*((sq2[c0]-1ll+mdl)%mdl))%mdl)%mdl;
		cout<<ans<<endl;
	}
	return 0;
}