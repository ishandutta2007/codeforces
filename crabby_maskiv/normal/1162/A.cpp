#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=19260817;
int n,m,h;
int a[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>h>>m;
	for(i=1;i<=n;i++) a[i]=h;
	while(m--){
		int l,r,x;cin>>l>>r>>x;
		for(i=l;i<=r;i++) a[i]=min(a[i],x);
	}
	for(i=1;i<=n;i++) ans+=a[i]*a[i];
	cout<<ans;
	return 0;
}