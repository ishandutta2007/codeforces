#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

const int N=10,P=998244353;

int n,m;
int a[N],b[N],c[N][N];
int A[1<<6],B[1<<6],s[N][1<<6],bin[1<<6];
int C[1<<6];

int st[N];
int ans=1e9;
void dfs(int p,int s){
	if(s>=ans) return;
	if(p==n) { ans=s; return; }
	rep(S,0,(1<<m)-1) {
		int fl=1;
		if(s+::s[p][S]>=ans) continue;
		st[p]=S;
		drep(T,(1<<(p+1))-1,1<<p) {
			C[T]=C[T^(1<<p)]|st[p];
			if(A[T]>B[C[T]]) {
				fl=0;
				break;
			}
		}
		if(fl) dfs(p+1,s+::s[p][S]);
	}
}

int main(){
    int ti=clock();
	scanf("%d%d",&n,&m);
	rep(i,0,max(n,m)-1) bin[1<<i]=i;
	rep(i,0,n-1) scanf("%d",a+i);
	rep(i,0,m-1) scanf("%d",b+i);
	rep(i,0,n-1) rep(j,0,m-1) scanf("%d",c[i]+j);
	rep(i,0,n-1) rep(j,i+1,n-1) if(a[j]>a[i]) swap(a[i],a[j]),swap(c[i],c[j]);
	rep(S,1,(1<<n)-1) A[S]=A[S&(S-1)]+a[bin[S&-S]];
	rep(S,1,(1<<m)-1) B[S]=B[S&(S-1)]+b[bin[S&-S]];
	rep(i,0,n-1) rep(S,1,(1<<m)-1) s[i][S]=s[i][S&(S-1)]+c[i][bin[S&-S]];
	int s=0;
	rep(i,0,n-1) s+=a[i];
	rep(i,0,m-1) s-=b[i];
	if(s>0) return puts("-1"),0;
	dfs(0,0);
	printf("%d\n",ans==1e9?-1:ans);
}