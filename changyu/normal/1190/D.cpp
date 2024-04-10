#include<cstdio>
#include<algorithm>
#include<vector>
typedef long long ll;
using namespace std;
const int N=2e5+1;
int n,x[N],y[N],tmp[N],ky,kx,bt[N];ll ans;
vector<int>p[N];
inline void Add(int k,int a){for(;k&&k<=n;k+=k&-k)bt[k]+=a;}
inline int Sum(int k){int s=0;for(;k;k-=k&-k)s+=bt[k];return s;}
inline void Lisan(int*x,int&k){
	for(int i=1;i<=n;i++)tmp[i]=x[i];
	sort(tmp+1,tmp+n+1);
	k=0;
	for(int i=1;i<=n;i++)
	  if(tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=1;i<=n;i++)
	  x[i]=std::lower_bound(tmp+1,tmp+1+k,x[i])-tmp;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	Lisan(x,kx);Lisan(y,ky);
	for(int i=1;i<=n;i++)p[y[i]].push_back(x[i]);
	for(int i=ky;i;i--){
	  std::sort(p[i].begin(),p[i].end());
	  for(int k=0,j;k<p[i].size();k++){
		j=p[i][k];
		if(Sum(j)==Sum(j-1))Add(j,1);
	  }
	  for(int k=0,j,la=0;k<p[i].size();k++){
		j=p[i][k];
		ans+=1ll*(Sum(j)-Sum(la))*(Sum(kx)-Sum(j-1));
		la=j;
	  }
	}printf("%I64d",ans);
	return 0;
}