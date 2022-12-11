#include<bits/stdc++.h>
using namespace std;
const int N=110;
int T,n,k,f[N][N],g[N][N],ans;bool fl[N];
struct node{int a,b,id;bool friend operator <(node a,node b){return a.b<b.b;}}p[N];
vector<int>v;
void solve(){
	scanf("%d%d",&n,&k);v.clear();
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].a,&p[i].b),p[i].id=i;
	sort(p+1,p+n+1);memset(fl,0,sizeof(fl));
	memset(f,0xcf,sizeof(f));for(int i=0;i<=n;i++)f[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=k;j;j--){
			f[i][j]=max(f[i-1][j],f[i-1][j-1]+p[i].a-p[i].b*(k-j));
			g[i][j]=f[i-1][j]^f[i][j];
		}
	for(int i=n,j=k;i;i--)if(g[i][j])fl[i]=1,j--;
	printf("%d\n",k+2*(n-k));
	for(int i=1,j=0;i<=n;i++){
		if(j==k-1){
			for(int l=1;l<=n;l++)if(!fl[l])
				printf("%d %d ",p[l].id,-p[l].id);
			j++;
		}
		if(fl[i])printf("%d ",p[i].id),j++;
	}
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
// 9

// 4 -4 2 -2 5 -5 3 -3 1 

// 9

// 1 -1 3 -3 4 -4 5 -5 2