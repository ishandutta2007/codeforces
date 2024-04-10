#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1000000007ll;
int n,m,k;
int fa[N];
int size[N];
int cnt[N];
bool flag=0;
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
void merge(int u,int v){
	u=rt(u);v=rt(v);
	if(u==v) return;
	cnt[size[u]]--;
	cnt[size[v]]--;
	size[v]+=size[u];
	fa[u]=v;
	cnt[size[v]]++;
	if(cnt[size[v]]==k) flag=1;
	else flag=0;
}
pair<int,int> p[N];
bool vis[N];
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>p[i].first,p[i].second=i;
	for(i=1;i<=n;i++) fa[i]=i,size[i]=1;
	sort(p+1,p+n+1);
	int ans=0,ansk=0;
	for(i=1;i<=n;i++){
		int a=p[i].first,b=p[i].second;
		vis[b]=1;
		if(vis[b-1]&&vis[b+1]) k--;
		else if(!vis[b-1]&&!vis[b+1]){
			k++;
			cnt[1]++;
			flag=(cnt[1]==k);
		}
		if(b-1&&vis[b-1]) merge(b,b-1);
		if(b+1<=n&&vis[b+1]) merge(b,b+1);
		if(flag){
			if(k>ansk){
				ansk=k;
				ans=a+1;
			}
		}
	}
	cout<<ans;
    return 0;
}