#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];a[i]+=a[i-1];
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>b[i];b[i]+=b[i-1];
	}
	if(a[n]!=b[m]){
		cout<<-1;
		return 0;
	}
	int pos=1;
	int ans=0;
	for(i=1;i<=n;i++){
		int k=lower_bound(b+1,b+m+1,a[i])-b;
		if(b[k]!=a[i]) continue;
		pos=k+1;
		ans++;
	}
	cout<<ans;
    return 0;
}