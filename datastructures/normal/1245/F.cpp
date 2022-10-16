#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define n 50
using namespace std;
int t,l,r,a[105],b[105];
int f[105][2][2];
inline int dfs(int now,int limita,int limitb){
	if (now>n)return 1;
	if (f[now][limita][limitb]!=-1)return f[now][limita][limitb];
	int s=0;
	if (a[now]==1||limita==0)s+=dfs(now+1,limita&&(a[now]==1),limitb&&(b[now]==0));
	s+=dfs(now+1,limita&&(a[now]==0),limitb&&(b[now]==0));
	if (b[now]==1||limitb==0)s+=dfs(now+1,limita&&(a[now]==0),limitb&&(b[now]==1));
	return f[now][limita][limitb]=s;
}
inline int work(int x,int y){
	if (x<0||y<0)return 0;
	int xx=x,yy=y;
	int tot=0;
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	memset(f,-1,sizeof(f));
	while(x)tot++,a[n-tot+1]=x%2,x/=2;
	tot=0;
	while(y)tot++,b[n-tot+1]=y%2,y/=2;
	return dfs(1,1,1);
}
signed main(){
	cin>>t;
	while(t--){
		cin>>l>>r;
		cout<<work(r,r)-work(l-1,r)*2+work(l-1,l-1)<<endl;
	}
	return 0;
}