#include <bits/stdc++.h>
using namespace std;
typedef double db;
void read(int &x){
	register char ch=getchar();register int res=1;x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	if(ch=='-')res=-1,ch=getchar();
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=res;
}
int n,m,cur,X,s,t;
db T[200004],now,dp[2][200004],a[200004],z[200004];
db S[200004],k[200004],b[200004];
db f(int j,db x){return k[j]*x+b[j];}
bool check(db k1,db b1,db k2,db b2,db k3,db b3){return (b3-b2)/(k2-k3)<=(b2-b1)/(k1-k2);}
void Init(){s=t=0;}
void Push(db A,db B){
	while(s+1<t&&check(k[t-2],b[t-2],k[t-1],b[t-1],A,B))t--;
	k[t]=A,b[t++]=B;
}
db Pop(db x){while(s+1<t&&f(s,x)>=f(s+1,x))s++;return f(s,x);}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(X),T[i]=X,now+=T[i],S[i]=dp[0][i]=dp[0][i-1]+now/T[i],z[i]=z[i-1]+T[i],a[i]=a[i-1]+1.0/T[i];
	for(int i=2;i<=m;i++){
		cur^=1;
		for(int j=1;j<=n;j++)dp[cur][j]=9e18;
		Init();
		for(int j=1;j<=n;j++){
			if(j>=i)dp[cur][j]=S[j]+Pop(a[j]);
			if(dp[cur^1][j]==9e18)continue;
			db A=-z[j],B=dp[cur^1][j]-S[j]+a[j]*z[j];
			Push(A,B);
		}
	}
	printf("%.4lf",dp[cur][n]);
}