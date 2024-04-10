#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second 
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void noans(){
	puts("-1");exit(0);
}
int n,gg[1000004],vis[1000004];
vector<pii>v; 
int ans[1000004];
vector<int>now;
void dfs(int x,int num){
	vis[x]=1;num++;
	if (vis[gg[x]]){
		v.push_back(mkp(num,gg[x]));
		return;
	}
	dfs(gg[x],num);
}
void answers(int x,int cnt,int num){
	num++;now.push_back(x);
	if (num==cnt){
		ans[now[(cnt+1)/2]]=now[1];
		for (int i=1;i<(cnt+1)/2;i++)
			ans[now[i]]=now[(cnt+1)/2+i];
		for (int i=1;i<=cnt/2;i++)
			ans[now[i+(cnt+1)/2]]=now[i+1];
		return;
	}
	answers(gg[x],cnt,num);
}
void go(int x,int y,int cnt,int num){
	num++;now.push_back(x),now.push_back(y);
	if (num==cnt){
		ans[now[cnt*2]]=now[1];
		for (int i=1;i<cnt*2;i++) ans[now[i]]=now[i+1];
		return;
	}
	go(gg[x],gg[y],cnt,num);
}
int main(){
	read(n);for (int i=1;i<=n;i++) read(gg[i]);
	for (int i=1;i<=n;i++)if(!vis[i]) dfs(i,0);
	sort (v.begin(),v.end());
	for (int i=0;i<v.size();){
		if(v[i].fi%2==1){
			now.clear();now.push_back(0);
			answers(v[i].se,v[i].fi,0);
			i++;continue;
		}
		now.clear();now.push_back(0);
		if (i==v.size()-1) noans();
		if (v[i+1].fi!=v[i].fi) noans();
		go(v[i+1].se,v[i].se,v[i].fi,0);
		i+=2;
	}
	for (int i=1;i<=n;i++) write(ans[i]),putchar(' ');
}