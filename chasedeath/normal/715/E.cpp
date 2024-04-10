#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
enum{N=300,P=998244353};
int n;
int p[N],q[N],pre[N],nxt[N],A,B,E,D;
int F[N],G[N],H[N],V[N];
int S[N][N],T[N][N],C[N][N];
int main(){
	scanf("%d",&n);
	rep(i,1,n) pre[i]=nxt[i]=-1;
	rep(i,**S=1,n) rep(j,1,i) S[i][j]=(S[i-1][j-1]+1ll*(i-1)*S[i-1][j])%P;
	rep(i,0,n) rep(j,*T[i]=1,n) T[i][j]=1ll*T[i][j-1]*(i+j-1)%P;
	rep(i,0,n) rep(j,*C[i]=1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	rep(i,1,n) scanf("%d",p+i);
	rep(i,1,n) {
		scanf("%d",q+i);
		if(p[i] && q[i]) nxt[p[i]]=q[i],pre[q[i]]=p[i];
		else if(p[i]) nxt[p[i]]=0;
		else if(q[i]) pre[q[i]]=0;
	}
	rep(i,1,n) if(pre[i]<=0) {
		int j=i;
		for(;nxt[j]>0;j=nxt[j]) V[j]=1;
		V[j]=1;
		if(pre[i]==nxt[j]) A+=pre[i]==-1; // ==0 || ==-1 ,but we can't count 0 in 
		else if(~pre[i]) B++;
		else E++;
	}
	rep(i,1,n) if(!V[i]) {
		for(int j=i;!V[j];j=nxt[j]) V[j]=1;
		D++;
	}
	int c=1;
	rep(i,1,A) c=1ll*c*i%P;
	rep(i,0,A) F[i]=1ll*c*S[A][i]%P;
	rep(i,0,B) rep(j,0,i) G[j]=(G[j]+1ll*S[i][j]*T[A][B-i]%P*C[B][i])%P;
	rep(i,0,E) rep(j,0,i) H[j]=(H[j]+1ll*S[i][j]*T[A][E-i]%P*C[E][i])%P;
	
	rep(i,0,n) V[i]=0;
	rep(i,0,A) rep(j,0,B) V[i+j+D]=(V[i+j+D]+1ll*F[i]*G[j])%P;
	rep(i,0,n) F[i]=0;
	rep(i,0,A+B+D) rep(j,0,E) F[n-i-j]=(F[n-i-j]+1ll*V[i]*H[j])%P;
	rep(i,0,n-1) printf("%d ",F[i]);
}