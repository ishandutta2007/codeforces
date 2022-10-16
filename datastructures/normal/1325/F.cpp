#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm> 
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,B;
vector<int> e[100005];
int depth[100005],fa[100005],mx,id1,id2;
int c[100005],book[100005];
void dfs(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	for (int i=0,len=e[now].size();i<len;i++){
		if (e[now][i]==f)continue;
		if (depth[e[now][i]]==0)dfs(e[now][i],now,d+1);
		else{
			if (depth[now]-depth[e[now][i]]+1>mx){
				mx=depth[now]-depth[e[now][i]]+1;
				id1=now,id2=e[now][i];
			}
		}
	}
	return;
}
bool cmp(int a,int b){
	return depth[a]>depth[b];
}
int main(){
	cin>>n>>m;
	while(B*B<n)B++;
	for (int i=1;i<=m;i++){
		int x,y;
		x=read(),y=read();
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0,1);
	if (mx>=B){
		cout<<2<<endl;
		cout<<mx<<endl;
		int now=id1;
		while(now!=id2){
			printf("%d ",now);
			now=fa[now];
		}
		printf("%d\n",now);
		return 0;
	}
	for (int i=1;i<=n;i++)c[i]=i;
	sort(c+1,c+1+n,cmp);
	cout<<1<<endl;
	int num=0;
	for (int i=1;i<=n&&num<B;i++){
		int now=c[i];
		if (book[now]==1)continue;
		printf("%d ",now);
		num++;
		book[now]=1;
		for (int j=0,len=e[now].size();j<len;j++)book[e[now][j]]=1;
	}
	puts("");
	return 0;
}