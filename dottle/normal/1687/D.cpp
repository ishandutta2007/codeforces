#include<bits/stdc++.h>
#define int long long
const int N=3e6;
using namespace std;
int n,a[N],nxt[N];
main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++)nxt[a[i]-1]=i;
	nxt[N-1]=n+1;
	for(int i=N-1;i;i--)if(!nxt[i])nxt[i]=nxt[i+1];
	for(int i=1;i<=a[n];i++){
		int l=max(0ll,i*i-a[1]);
		int nl=l,nr=i*i+i-a[1];
		for(int j=2;j<=n;){
			int k=ceil((-1+sqrt(1+4*a[j]+4*l))/2);
			int nowR=k*k+k-l;
			int nx=nowR<N?nxt[nowR]:n+1;
			nl=max(nl,k*k-a[j]);
			nr=min(nr,k*k+k-a[nx-1]);
			j=nx;
		}
		if(nl<=nr)cout<<nl,exit(0);
	}
}