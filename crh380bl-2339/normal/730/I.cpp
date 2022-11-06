#include<bits/stdc++.h>
#define ll long long
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
struct node{
	int a,b,id;
	bool operator <(const node t)const{
		return a>t.a;
	}
}c[3002];
int f[3002][3002];
int g[3002][3002];
int arr[3][3002],tot[3];
void work(int n,int s){
	assert(n>=s);
	if(n==0)return;
	int t=g[n][s];
	arr[t][++tot[t]]=c[n].id;
	if(t!=2)work(n-1,s);
	else work(n-1,s-1);
}
int main(){
	int n,p,s,i,j,k;
	scanf("%d%d%d",&n,&p,&s);
	for(i=1;i<=n;++i){
		c[i].id=i;
		scanf("%d",&c[i].a);
	}
	for(i=1;i<=n;++i){
		scanf("%d",&c[i].b);
	}
	sort(c+1,c+1+n);
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(i=1;i<=n;++i){
		for(j=0;j<=min(i,s);++j){
			int tmp2;
			if(j)tmp2=f[i-1][j-1]+c[i].b;
			else tmp2=-1;
			int tmp1=f[i-1][j]+c[i].a;
			int tmp0=f[i-1][j];
			if(i-j>p)tmp1=-1;
			if(i==j)tmp0=tmp1=-1;
			if(tmp0>max(tmp1,tmp2)){
				f[i][j]=tmp0;
				g[i][j]=0;
			}
			else if(tmp1>max(tmp2,tmp0)){
				f[i][j]=tmp1;
				g[i][j]=1;
			}
			else{
				f[i][j]=tmp2;
				g[i][j]=2;
			}
		}
	}
	printf("%d\n",f[n][s]);
	work(n,s);
	for(i=1;i<=p;++i)printf("%d ",arr[1][i]);puts("");
	for(i=1;i<=s;++i)printf("%d ",arr[2][i]);puts("");
	return 0;
}