#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int n,a[300005],pos[300005],u[600005],v[600005],first[600005],nxt[600005];
vector<int> e[300005];
int fa[300005],num[300005],idx,dfn[300005],dfo[300005],ans[300005],ans_id,sta[300005],tot;
int path[300005],len;
ll cnt;
bool cmp(int a,int b){
	return ans[a]<ans[b];
}
bool in(int a,int b){//whether a is in b
	if (dfn[a]>=dfn[b]&&dfn[a]<=dfo[b])return 1;
	return 0;
} 
void dfs1(int now,int f){
	dfn[now]=++idx;
	fa[now]=f;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		num[now]++;
		e[now].push_back(v[i]);
		dfs1(v[i],now);
	}
	dfo[now]=idx;
	return;
}
int fg,_idx;
void check(int x){
	for (int i=1;i<=tot;i++)
		if (pos[x+i]!=sta[i])fg=0;
	return;
}
void dfs2(int now){
	++_idx;
	if (_idx!=ans[now])fg=0;
	for (int i=0;i<(int)e[now].size();i++)dfs2(e[now][i]);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0);
	dfn[0]=0,dfo[0]=n+1;
	sta[tot]=0;
	fg=1;
	for (int i=1;i<=n;i++){
		int x=pos[i];
		int _num=num[x],_fa=fa[x];
		if (!in(x,sta[tot])){
			int pos=-1;
			for (int j=1;j<=tot;j++)
				if (sta[j]==x)pos=j;
			cnt+=pos-1;
			for (int j=pos;j<tot;j++)sta[j]=sta[j+1];
			tot--;
			check(i);
			break;
		}
		len=0;
		while(x!=sta[tot])path[++len]=x,x=fa[x];
		reverse(path+1,path+1+len);
		for (int j=1;j<=len;j++){
			int now=path[j];
			sta[++tot]=now;
			if (ans[now]!=0){
				fg=0;
				break;
			}
			ans[now]=++ans_id;
		}
		tot--;
		cnt+=tot;
		num[_fa]--;
		if (_num>0){
			check(i);
			break;
		}
	}
	for (int i=1;i<=n;i++)
		if (ans[i]==0)ans[i]=a[i];
	_idx=0;
	for (int i=1;i<=n;i++)sort(e[i].begin(),e[i].end(),cmp);
	dfs2(1);
	if (fg==1){
		puts("YES");
		printf("%lld\n",cnt);
		for (int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	else puts("NO");
	return 0;
}//qwq