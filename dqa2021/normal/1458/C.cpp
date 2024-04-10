#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m;
int a[1010][1010],b[1010][1010];
char s[100010];
struct M{
	int s[4][4];  // j i a[i][j]
	void clear(){
		memset(s,0,sizeof s);
	}
}R,L,D,U,I,C,E;
M operator*(const M &x,const M &y){
	static M z;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++){
			int &t=z.s[i][j]; t=0;
			for (int k=0;k<4;k++)
				t+=x.s[i][k]*y.s[k][j];
		}
	return z;
}
void init(){
	E.s[0][0]=E.s[1][1]=E.s[2][2]=E.s[3][3]=1;
	R.s[0][0]=R.s[1][1]=R.s[2][2]=R.s[3][3]=1; R.s[3][0]=1;
	L.s[0][0]=L.s[1][1]=L.s[2][2]=L.s[3][3]=1; L.s[3][0]=-1;
	D.s[0][0]=D.s[1][1]=D.s[2][2]=D.s[3][3]=1; D.s[3][1]=1;
	U.s[0][0]=U.s[1][1]=U.s[2][2]=U.s[3][3]=1; U.s[3][1]=-1;
	I.s[0][2]=I.s[1][1]=I.s[2][0]=I.s[3][3]=1;
	C.s[0][0]=C.s[1][2]=C.s[2][1]=C.s[3][3]=1;
}
void solve(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i-1][j-1]=read();
	M S,T=E; S.clear();
	scanf("%s",s+1);
	for (int i=1;i<=m;i++){
		if (s[i]=='R') T=T*R;
		if (s[i]=='L') T=T*L;
		if (s[i]=='D') T=T*D;
		if (s[i]=='U') T=T*U;
		if (s[i]=='I') T=T*I;
		if (s[i]=='C') T=T*C;
	}
//	for (int i=0;i<4;i++)
//		for (int j=0;j<4;j++)
//			printf("T.s %d %d = %d\n",i,j,T.s[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
//			S.clear();
			S.s[0][0]=j-1,S.s[0][1]=i-1;
			S.s[0][2]=a[i-1][j-1]-1,S.s[0][3]=1;
//			printf("  %d %d %d %d -> ",S.s[0][0],S.s[0][1],S.s[0][2],S.s[0][3]);
			S=S*T;
//			printf("%d %d %d %d\n",S.s[0][0],S.s[0][1],S.s[0][2],S.s[0][3]);
			int x=S.s[0][1],y=S.s[0][0],v=S.s[0][2];
//			printf(  "%d %d %d\n",x,y,v);
			x=(x%n+n)%n,y=(y%n+n)%n,v=(v%n+n)%n;
//			printf("%d %d %d -> %d %d %d\n",i-1,j-1,a[i-1][j-1]-1,x,y,v);
			b[x][y]=v;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			printf("%d%c",b[i-1][j-1]+1," \n"[j==n]);
}
int main()
{
	for (int T=read();T--;) init(),solve();
}