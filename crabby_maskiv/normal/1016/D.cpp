#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll a[N],b[N];
ll c[N][N];
bool a1[N],a2[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	ll k;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(j=1;j<=m;j++) cin>>b[j];
	for(i=2;i<=n;i++) c[i][1]=a[i];
	for(j=2;j<=m;j++) c[1][j]=b[j];
	for(k=0;k<=30;k++){
		for(i=1;i<=n;i++) a1[i]=a[i]&(1<<k);
		for(i=1;i<=m;i++) a2[i]=b[i]&(1<<k);
		bool p1=0,p2=0;
		for(i=2;i<=n;i++) p1^=a1[i];
		for(i=2;i<=m;i++) p2^=a2[i];
		if((a2[1]^p1)^(a1[1]^p2)){
			cout<<"NO";
			return 0;
		}
		if(a2[1]^p1) c[1][1]+=(1<<k);
	}
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}