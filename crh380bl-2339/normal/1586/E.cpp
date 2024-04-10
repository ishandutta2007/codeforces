#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int fa[N],f[N],d[N];
int q1[N],q2[N],cnt1,cnt2;
vector<int>e[N];
bool bo[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct path{
	int s,t;
}a[N];
void DFS(int x,int F){
	int i;
	f[x]=F;
	d[x]=d[F]+1;
	for(i=0;i<e[x].size();++i){
		if(e[x][i]!=F){
			DFS(e[x][i],x);
		}
	}
}
void work(int s,int t){
	cnt1=cnt2=0;int i;
	q1[++cnt1]=s;
	q2[++cnt2]=t;
	while(d[s]>d[t]){
		q1[++cnt1]=f[s];
		s=f[s];
	}
	while(d[t]>d[s]){
		q2[++cnt2]=f[t];
		t=f[t];
	}
	while(s!=t){
		q1[++cnt1]=f[s];
		q2[++cnt2]=f[t];
		s=f[s];
		t=f[t];
	}
	printf("%d\n",cnt1+cnt2-1);
	for(i=1;i<=cnt1;++i)printf("%d ",q1[i]);
	for(i=cnt2-1;i>=1;--i)printf("%d ",q2[i]);
	puts("");
}
int main(){
	int i,n,m,x,y,f1,f2,q,sum=0;
	read(n);read(m);
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i){
		read(x);read(y);
		f1=find(x);f2=find(y);
		if(f1!=f2){
			fa[f2]=f1;
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	read(q);
	for(i=1;i<=q;++i){
		read(a[i].s);
		read(a[i].t);
		bo[a[i].s]^=1;
		bo[a[i].t]^=1;
	}
	for(i=1;i<=n;++i){
		if(bo[i])++sum;
	}
	if(sum){
		puts("NO");
		printf("%d\n",sum/2);
		return 0;
	}
	DFS(1,0);
	puts("YES");
	for(i=1;i<=q;++i){
		work(a[i].s,a[i].t);
	}
	return 0;
}