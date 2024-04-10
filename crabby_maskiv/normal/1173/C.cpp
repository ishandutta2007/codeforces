#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int a[N],b[N];
int k[N*3];
bool vis[N];
bool check(int key){
	int i,j;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++) vis[a[i]]=1;
	for(i=1;i<=key;i++) vis[b[i]]=1;
	for(i=1;i<=n;i++){
		if(!vis[i]) return 0;
		vis[i]=0;
		vis[b[key+i]]=1;
	}
	return 1;
}
int tp(){
	int i;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++) vis[a[i]]=1;
	if(!b[n]) return -1;
	for(i=1;i<=b[n];i++)
		if(b[n-b[n]+i]!=i) return -1;
	for(i=1;i<=n-b[n];i++){
		if(!vis[b[n]+i]) return -1;
		vis[b[n]+i]=0;
		vis[b[i]]=1;
	}
	return n-b[n];
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) cin>>b[i];
	int t=tp();
	if(t>=0){
		cout<<t;
		return 0;
	}
	int l=0,r=n;
	while(r-l>5){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	for(i=l;i<=r;i++){
		if(check(i)){
			cout<<i+n;
			return 0;
		}
	}
	return 0;
}