#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N];
ll s1[N],s2[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) s1[i]=s1[i-1]+a[i];
	for(i=n;i;i--) s2[i]=s2[i+1]+a[i];
	cin>>m;
	while(m--){
		int x;cin>>x;
		cout<<s1[n-x]+s2[n-x+2]<<endl;
	}
	return 0;
}