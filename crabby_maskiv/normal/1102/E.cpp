#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const int mod=998244353;
int n,m,k;
int a[N],x[N];
int pos[N];
int f[N],mn[N];
int rt(int u){
	if(f[u]==u) return u;
	return f[u]=rt(f[u]);
}
int merge(int x,int y){
	x=rt(x),y=rt(y);
	f[x]=y;
	mn[y]=min(mn[y],mn[x]);
	return mn[y];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];x[i]=a[i];
	}
	sort(x+1,x+n+1);
	int len=unique(x+1,x+n+1)-(x+1);
	for(i=1;i<=n;i++)
		a[i]=lower_bound(x+1,x+len+1,a[i])-x;
	for(i=1;i<=n;i++) f[i]=mn[i]=i;
	for(i=1;i<=n;i++){
		if(pos[a[i]]){
			for(j=mn[rt(i)];j>pos[a[i]];j=mn[rt(j)])
				merge(j,j-1);
		}
		pos[a[i]]=i;
	}
	int cnt=0;
	for(i=1;i<=n;i++)
		if(f[i]==i) cnt++;
	cnt--;
	int ans=1;
	while(cnt--){
		ans=(ans+ans)%mod;
	}
	cout<<ans;
	return 0;
}