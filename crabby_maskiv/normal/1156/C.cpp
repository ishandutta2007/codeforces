#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
ll n,m;
ll a[N];
bool check(int key){
	int i;
	for(i=1;i<=key;i++){
		if(a[n-key+i]-a[i]<m) return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n/2;
	while(r-l>5){
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	for(i=r;i>=l;i--){
		if(check(i)){
			cout<<i;
			return 0;
		}
	}
	return 0;
}