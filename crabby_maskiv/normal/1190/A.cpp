#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
ll n,k;int m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>a[i];
	int cnt=0;ll pos=1;
	int ans=0;
	for(i=1;i<=m;){
		for(j=i;a[j]<pos+cnt&&j<=m;j++);
		if(j>i){
			pos+=j-i;
			i=j;
			ans++;
			continue;
		}
		pos+=(a[i]-pos)/k*k;
		pos+=k;
		while(a[i]<pos&&i<=m){
			i++;
			cnt++;
		}
		pos+=cnt;
		ans++;
		cnt=0;
	}
	cout<<ans;
	return 0;
}