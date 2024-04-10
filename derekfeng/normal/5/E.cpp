#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
map<int,int>mp;
int n,a[2000004],cnt;
ll ans;
vector<int>v[1000004];
int g[1000004];
int d[2000004],t,rig[1000004],lft[1000004];
bool vis[1000004];
int dfs(int x){
	vis[x]=1;
	if (g[x]==-1 || vis[g[x]]) return 1;
	return dfs(g[x])+1;
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),mp[a[i]]++;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	for (int i=1;i<=n;i++)
		a[i]=mp[a[i]],v[a[i]].push_back(i);
	for (int i=1;i<=n;i++) a[n+i]=a[i];
	for (int i=1;i<=2*n;i++){
		while (t>0 && a[i]>a[d[t-1]]) rig[d[--t]]=i; 
		if (i<=n) d[t++]=i;
	}
	t=0;
	for (int i=2*n;i>0;i--){
		while (t>0 && a[i]>a[d[t-1]]) lft[d[--t]-n]=i;
		if (i>n) d[t++]=i;
	}
	for (int i=1;i<=n;i++){
		if (lft[i]>n) lft[i]-=n;
		if (rig[i]>n) rig[i]-=n;
	}
	ans=1ll*v[cnt].size()*(v[cnt].size()-1)/2;
	memset (g,-1,sizeof(g));
	for (int i=cnt-1;i>0;i--){
		for (int j=0;j<v[i].size();j++){
			if (lft[v[i][j]]!=rig[v[i][j]]) ans+=2;
			else ans++;
			if (rig[v[i][j]]==rig[v[i][(j+1)%v[i].size()]]) g[v[i][j]]=v[i][(j+1)%v[i].size()];
		}
		bool al=1;
		int st;
		for (int j=0;j<v[i].size();j++)
			if (g[v[i][j]]==-1){al=0,st=(j+1)%v[i].size();break;}
		if (al){
			ans+=1ll*v[i].size()*(v[i].size()-1)/2;
			continue;
		}
		for (int j=0;j<v[i].size();j++){
			int val=dfs(v[i][(j+st)%v[i].size()]);
			ans+=1ll*val*(val-1)/2;
		}
	}
	write(ans);
}