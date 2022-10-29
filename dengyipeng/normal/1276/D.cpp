#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200005
#define mo 998244353
#define ll long long 
using namespace std;

int n,i,j,k,x,y;
vector<int> e[maxn];
ll f[maxn][4],pre[maxn],nex[maxn];

void DFS(int x,int p){
	int fi=0,y,k;
	for(int i=0;i<e[x].size();i++) if (e[x][i]==p)
		{fi=i;break;}
	for(int i=0;i<e[x].size();i++) if (e[x][i]!=p)
		DFS(e[x][i],x);
	f[x][0]=f[x][2]=pre[0]=1;
	for(int i=0;i<e[x].size();i++) if (e[x][i]!=p){
		y=e[x][i];
		(f[x][0]*=(f[y][1]+f[y][2])%mo)%=mo;
		if (i<fi) (f[x][2]*=(f[y][1]+f[y][2])%mo)%=mo; 
		if (i>fi) (f[x][2]*=(f[y][0]+f[y][1]+f[y][3])%mo)%=mo;
		pre[i+1]=((f[y][1]+f[y][2])%mo*pre[i])%mo;
	} else pre[i+1]=pre[i];
	nex[e[x].size()]=1;
	for(int i=e[x].size()-1;i>=0;i--) if (e[x][i]!=p){
		y=e[x][i];
		nex[i]=((f[y][0]+f[y][1]+f[y][3])%mo*nex[i+1])%mo;
	} else nex[i]=nex[i+1];
	for(int i=0;i<e[x].size();i++) if (e[x][i]!=p){
		y=e[x][i],k=(i<fi)?1:3;
		f[x][k]+=(f[y][0]+f[y][3])%mo*pre[i]%mo*nex[i+1]%mo;
	}
	f[x][1]%=mo,f[x][3]%=mo;
}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	DFS(1,0);
	printf("%lld",(f[1][0]+f[1][1]+f[1][3])%mo);
}