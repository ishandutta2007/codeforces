#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n/2;i++) cin>>b[i];
	a[1]=0;a[n]=b[1];
	for(i=2;i<=n/2;i++){
		if(b[i]-a[i-1]<=a[n-i+2]){
			a[i]=a[i-1];
			a[n-i+1]=b[i]-a[i-1];
		}
		else{
			a[n-i+1]=a[n-i+2];
			a[i]=b[i]-a[n-i+2];
		}
	}
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}