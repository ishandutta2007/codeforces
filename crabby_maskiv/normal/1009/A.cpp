#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N],c[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=m;i++) cin>>a[i];
	int pos=1,ans=0;
	for(i=1;i<=m;i++){
		while(pos<=n&&c[pos]>a[i]) pos++;
		if(pos>n) break;
		ans++;
		pos++;
	}
	cout<<ans;
	return 0;
}