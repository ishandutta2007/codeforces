#include<bits/stdc++.h>
//#define int long long
const int N=500005;
using namespace std;

int n,a[N],b[N],k,ans; 

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(a+1,a+1+n);
	int fl=1;
	for(int i=n-k+1;i<=k;i++)
		if(a[i]!=b[i])
			fl=0;
	cout<<(fl?"YES":"NO")<<endl;
} 

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}