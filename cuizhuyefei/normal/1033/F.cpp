#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
const int N = 1001000;
int w,n,m,f[N],a[6666],mi[15],dy[6666],val[6666],res;
bool ok[15][3];
inline void dfs(int dep,int v){
	if(dep==w){res+=f[v];return;}
	rep(i,0,2)if(ok[dep][i])dfs(dep+1,v+mi[dep]*i);
}
int main(){
	scanf("%d%d%d",&w,&n,&m);
	mi[0]=1;rep(i,1,12)mi[i]=mi[i-1]*3,dy[1<<i]=i;
	rep(i,1,1<<12){int bit=i&-i;val[i]=val[i^bit]+mi[dy[bit]];}
	rep(i,1,n){int x;scanf("%d",&x);a[x]++;}//printf("input %d\n",val[x]);}
	rep(i,0,(1<<w)-1)if(a[i])rep(j,i+1,(1<<w)-1)f[val[i]+val[j]]+=a[i]*a[j]<<1;
	rep(i,0,(1<<w)-1)f[val[i]*2]+=a[i]*a[i];
	while(m--){
		char S[15];scanf("%s",S);rep(i,0,w-1)if(i<=w-1-i)swap(S[i],S[w-1-i]);
		memset(ok,0,sizeof(ok));
		rep(i,0,w-1)rep(j,0,2)
			if(S[i]=='A'||S[i]=='a')ok[i][j]=(S[i]=='A')^(j==2);
			else if(S[i]=='O'||S[i]=='o')ok[i][j]=(S[i]=='O')^(j>=1);
			else ok[i][j]=(S[i]=='X')^(j==1);
		res=0;dfs(0,0);printf("%d\n",res);
	}
	return 0;
}