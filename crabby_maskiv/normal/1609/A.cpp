#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,m;
ll a[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		int c=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]%2==0){
				a[i]/=2;
				c++;
			}
		}
		ll sum=0,mx=0;
		for(i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		sum-=mx;
		while(c--) mx*=2;
		sum+=mx;
		cout<<sum<<endl;
	}
	return 0;
}