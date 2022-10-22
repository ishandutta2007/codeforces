#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m,k;
int a[N],b[N];
int main(){
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	int mn=0x3f3f3f3f,mx=0;
	for(i=1;i<=m;i++) mx=max(mx,b[i]);
	for(i=1;i<=n;i++) mn=min(mn,a[i]);
	cout<<max(k,k/mn*mx+k-k/mn*mn);
	return 0;
}