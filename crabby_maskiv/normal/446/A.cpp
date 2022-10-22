#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int a[N];
int pre[N],nxt[N];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		if(a[i]>a[i-1]) pre[i]=pre[i-1]+1;
		else pre[i]=1;
	}
	for(i=n;i>0;i--){
		if(a[i]<a[i+1]) nxt[i]=nxt[i+1]+1;
		else nxt[i]=1;
	}
	int mx=-1;
	for(i=1;i<=n;i++){
		mx=max(mx,pre[i-1]+1);
		mx=max(mx,nxt[i+1]+1);
		if(i>1&&i<n&&a[i-1]<a[i+1]-1) mx=max(mx,pre[i-1]+nxt[i+1]+1);
	}
	cout<<mx;
	return 0;
}