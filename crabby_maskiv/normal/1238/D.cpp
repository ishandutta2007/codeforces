#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m,k;
int l[N],r[N],len;
char a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>(a+1);
	ll ans=ll(n)*(n-1)/2;
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]) continue;
		int pos=i+1;ans--;
		while(a[pos]==a[pos+1]){
			pos++;
			ans--;
		}
	}
	for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]) continue;
		int pos=i+1;
		while(a[pos]==a[pos+1]){
			pos++;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}