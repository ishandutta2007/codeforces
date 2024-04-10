#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,dsu[105][105];
char s[105][105][105];
int dsu_find(int id,int x){
	if (x==dsu[id][x])return x;
	return dsu[id][x]=dsu_find(id,dsu[id][x]); 
}
int c[105],head,tail,q[105];
int totm,u[205],v[205],first[205],nxt[205];
void add_edge(int a,int b){
	int i=++totm;
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]],first[u[i]]=i;
	u[i+n]=v[i],v[i+n]=u[i];
	nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	return;
}
int dfsfg,book[105],d[105][105];
void dfs(int now,int fa,int s,int x){
	if (book[now]==1){
		dfsfg=0;
		return;
	}
	book[now]=1;
	d[now][x]=s;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)dfs(v[i],now,s+1,x);
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				scanf("%s",s[i][j]+1);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)dsu[i][j]=j;
			for (int j=1;j<n;j++)
				for (int k=j+1;k<=n;k++){
					if (s[j][k][i]!='1')continue; 
					int x=dsu_find(i,j),y=dsu_find(i,k);
					if (x!=y)dsu[i][x]=y;
				}
			for (int j=1;j<=n;j++)dsu[i][j]=dsu_find(i,j);
		}
		int fg=0;
		for (int i=2;i<=n;i++){
			memset(c,0,sizeof(c));
			totm=0;
			memset(first,0,sizeof(first));
			memset(nxt,0,sizeof(nxt));
			c[1]=i,c[i]=1;
			add_edge(1,i);
			head=1,tail=2;
			q[1]=1,q[2]=i;
			while(head<=tail){
				int now=q[head];
				head++;
				for (int j=1;j<=n&&totm<n;j++)
					if (j!=c[now]&&dsu[now][j]==dsu[now][c[now]]){
						if (c[j]!=0){
							totm=n+1;
							break;
						}
						c[j]=now;
						add_edge(now,j);
						q[++tail]=j;
					}
			}
			if (totm==n-1){
				int qwqfg=1;
				for (int i=1;i<=n;i++){
					dfsfg=1;
					memset(book,0,sizeof(book));
					dfs(i,0,0,i);
					if (dfsfg==0){
						qwqfg=0;
						break;
					}
				}
				if (qwqfg==0)continue;
				for (int i=1;i<n;i++)
					for (int j=i+1;j<=n;j++)
						for (int k=1;k<=n;k++){
							if (d[k][i]==d[k][j]&&s[i][j][k]=='0')qwqfg=0;
							if (d[k][i]!=d[k][j]&&s[i][j][k]=='1')qwqfg=0;
						}
				if (qwqfg==1){
					fg=1;
					puts("YES");
					for (int i=1;i<n;i++)cout<<u[i]<<' '<<v[i]<<endl;
					break;
				}
			}
		}
		if (fg==0)puts("NO");
	}
	return 0;
}