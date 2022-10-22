#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=1000000007ll;
int n,m;
int a[N],b[N];
int c[N];
int main(){
    ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>b[i];
		c[b[i]]=i;
	}
	int mx=0,ans=0;
	for(i=1;i<=n;i++){
		mx=max(mx,c[a[i]]);
		if(mx>c[a[i]]) ans++;
	}
	cout<<ans;
    return 0;
}
//2 4 3 5 1