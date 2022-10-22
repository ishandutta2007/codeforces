// LUOGU_RID: 90486441
#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 50
#define K 100000
using namespace std;
int n,m,c,X[K+5],Y[K+5],c_,X_[K+5],Y_[K+5];
typedef char Arr[N+5][N+5];Arr A,B,S;
void Swap(int x,int y)
{
	X[++c]=x,Y[c]=y,S[x][y]=='U'?(S[x][y]=S[x+1][y]='L',S[x][y+1]=S[x+1][y+1]='R')
	:(S[x][y]=S[x][y+1]='U',S[x+1][y]=S[x+1][y+1]='D');
}
void R(int x,int y) {S[x][y]=='U'?S[x][y+1]=='L'&&(R(x,y+1),0):S[x+1][y]=='U'&&(R(x+1,y),0),Swap(x,y);}
void Solve() {for(int i=1;i<=n;++i) for(int j=1;j<=m;j+=2) S[i][j]=='U'&&(R(i,j),0);}
int main()
{
	int i,j;for(scanf("%d%d",&n,&m),i=1;i<=n;++i) scanf("%s",A[i]+1);for(i=1;i<=n;++i) scanf("%s",B[i]+1);
	int op=0;if(m&1)
	{
		for(swap(n,m),op=i=1;i<=max(n,m);++i) for(j=1;j<i;++j) swap(A[i][j],A[j][i]),swap(B[i][j],B[j][i]);
		for(i=1;i<=n;++i) for(j=1;j<=m;++j) A[i][j]=A[i][j]=='U'?'L':(A[i][j]=='D'?'R':(A[i][j]=='L'?'U':'D')),B[i][j]=B[i][j]=='U'?'L':(B[i][j]=='D'?'R':(B[i][j]=='L'?'U':'D'));
	}
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) S[i][j]=A[i][j];Solve();for(i=1;i<=c;++i) X_[i]=X[i],Y_[i]=Y[i];c_=c,c=0;
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) S[i][j]=B[i][j];Solve();printf("%d\n",c_+c);
	if(op) {for(i=1;i<=c_;++i) swap(X_[i],Y_[i]);for(i=1;i<=c;++i) swap(X[i],Y[i]);}
	for(i=1;i<=c_;++i) printf("%d %d\n",X_[i],Y_[i]);for(i=c;i;--i) printf("%d %d\n",X[i],Y[i]);return 0;
}