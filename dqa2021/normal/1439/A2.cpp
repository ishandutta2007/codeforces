#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
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
typedef pair<int,int> P;
#define fir first
#define sec second

int n,m,w[110][110];
char s[110];
struct C{
	int a,b,c,d,e,f;
}c[10010]; int top;
void work(int a,int b,int c,int d,int e,int f){
	w[a][b]^=1,w[c][d]^=1,w[e][f]^=1;
	::c[++top]=(C){a,b,c,d,e,f};
}
void init(){
	
}
void solve(){
	n=read(),m=read(); top=0;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) w[i][j]=s[j]^'0';
	}
	if (n&1){
		for (int i=1;i<=m;i++){
			if (w[n][i]){
				if (i<m) work(n,i,n-1,i,n-1,i+1);
				else work(n,i,n-1,i,n-1,i-1);
			}
		}
		n--;
	}
	if (m&1){
		for (int i=1;i<=n;i++)
			if (w[i][m]){
				if (i<n) work(i,m,i,m-1,i+1,m-1);
				else work(i,m,i,m-1,i-1,m-1);
			}
		m--;
	}
	for (int i=1;i<=n;i+=2){
		for (int j=1;j<=m;j+=2){
			while (1){
//				if (w[i][j]||w[i+1][j]||w[i][j+1]||w[i+1][j+1]);
//				else break;
				vector<P> A,B;
				for (int u=i;u<=i+1;u++)
					for (int v=j;v<=j+1;v++)
						if (w[u][v]) A.pb((P){u,v});
						else B.pb((P){u,v});
				if (B.size()==4) break;
				if (A.size()==4) work(A[0].fir,A[0].sec,A[1].fir,A[1].sec,A[2].fir,A[2].sec);
				else if (A.size()==3) work(A[0].fir,A[0].sec,A[1].fir,A[1].sec,A[2].fir,A[2].sec);
				else if (A.size()==2) work(A[0].fir,A[0].sec,B[0].fir,B[0].sec,B[1].fir,B[1].sec);
				else work(A[0].fir,A[0].sec,B[0].fir,B[0].sec,B[1].fir,B[1].sec);
			}
		}
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++) printf("%d %d %d %d %d %d\n",c[i].a,c[i].b,c[i].c,c[i].d,c[i].e,c[i].f);
}
int main()
{
	for (int T=read();T--;) init(),solve();
}