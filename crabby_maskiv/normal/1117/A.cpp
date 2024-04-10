#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int mx;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	memset(a,-1,sizeof(a));
	for(i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	int cnt=0,ans=0;
	for(i=1;i<=n+1;i++){
		if(a[i]==mx) cnt++;
		else{
			ans=max(ans,cnt);
			cnt=0;
		}
	}
	cout<<ans;
	return 0;
}