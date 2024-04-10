#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
ll k;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>k>>n;
	ll sum=0;
	for(i=1;i<=n;i++){
		sum+=i;a[i]=i;
	}
	if(sum>k){
		cout<<"NO";
		return 0;
	}
	ll x=k-sum;
	if(x>=n){
		for(i=1;i<=n;i++) a[i]+=x/n;
		x%=n;
	}
	while(x>0){
		ll _x=x;
		for(i=n;i;i--){
			if(a[i]+1<=a[i-1]*2){
				a[i]++;
				_x--;
				if(!_x) break;
			}
		}
		if(_x==x){
			cout<<"NO";
			return 0;
		}
		x=_x;
	}
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}