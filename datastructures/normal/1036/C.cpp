#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,l,r;
int f[2][25][15][5];
int a[25],tot;
inline int dfs(int limit,int now,int last,int num){
	if (num>3)return 0;
	if (f[limit][now][last][num]!=-1)return f[limit][now][last][num];
	if (now==0)return 1;
	int s=0,up=limit?a[now]:9;
	for (int i=0;i<=up;i++){
		s+=dfs(limit&&(i==up),now-1,i,num+(i>0));
	}
	return f[limit][now][last][num]=s;
}
int work(int x){
	if (x==0)return 1;
	tot=0;
	while(x)a[++tot]=x%10,x/=10;
	memset(f,-1,sizeof(f));
	return dfs(1,tot,0,0);
}
signed main(){
//	freopen("1036C.in","r",stdin);
//	freopen("1036C.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>l>>r;
		cout<<work(r)-work(l-1)<<endl;
	}
	return 0;
}