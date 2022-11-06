#include<bits/stdc++.h>
#define N 300005
#define INF 1000000000
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
int a[N],b[N],n;
int L[N],R[N],fa[N],f[N],pre[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
queue<int>Q;
void out(int x){
	if(x==n)return;
	out(pre[x]);
	printf("%d ",x);
}
int main(){
	int i,j,h,t;
	read(n);
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=n;++i)read(b[i]);
	for(i=1;i<=n;++i){
		fa[i]=i;
		f[i]=INF;
		L[i]=i+b[i]-a[i+b[i]];
		R[i]=i+b[i];
	}
	f[0]=INF;
	Q.push(n);
	fa[n]=n-1;
	f[n]=0;
	bool flg=0;
	while(!Q.empty()&&!flg){
		h=Q.front();
		Q.pop();
		for(i=find(R[h]);i>=L[h];i=find(i-1)){
			if(f[i]<=f[h]+1)continue;
			f[i]=f[h]+1;
			fa[i]=find(i-1);
			pre[i]=h;
			if(i==0){
				flg=1;
				break;
			}
			Q.push(i);
		}
	}
	if(f[0]==INF){
		puts("-1");
		return 0;
	}
	printf("%d\n",f[0]);
	out(0);
	return 0;
}