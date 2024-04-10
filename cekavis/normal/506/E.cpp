#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int L = 1005, N = L+5, M = 202, P = 10007;
int n, m, a[N], b[N], f[N][M][M];
char s[M];
namespace BM{
	int S, cnt, best, d[N], fail[N], f[N], ans[N][N];
	struct matrix{
		int a[L][L];
		int *operator[](int x){ return a[x];}
		const int *operator[](int x)const{ return a[x];}
		matrix operator*(const matrix &r)const{
			matrix ans;
			for(int i=0; i<S; ++i) for(int j=0; j<S; ++j){
				ans[i][j]=0;
				int k=0;
				for(; k<S-17; k+=18)
					ans[i][j]=(ans[i][j]+
						(unsigned ll)a[i][k]*r[k][j]+
						(unsigned ll)a[i][k+1]*r[k+1][j]+
						(unsigned ll)a[i][k+2]*r[k+2][j]+
						(unsigned ll)a[i][k+3]*r[k+3][j]+
						(unsigned ll)a[i][k+4]*r[k+4][j]+
						(unsigned ll)a[i][k+5]*r[k+5][j]+
						(unsigned ll)a[i][k+6]*r[k+6][j]+
						(unsigned ll)a[i][k+7]*r[k+7][j]+
						(unsigned ll)a[i][k+8]*r[k+8][j]+
						(unsigned ll)a[i][k+9]*r[k+9][j]+
						(unsigned ll)a[i][k+10]*r[k+10][j]+
						(unsigned ll)a[i][k+11]*r[k+11][j]+
						(unsigned ll)a[i][k+12]*r[k+12][j]+
						(unsigned ll)a[i][k+13]*r[k+13][j]+
						(unsigned ll)a[i][k+14]*r[k+14][j]+
						(unsigned ll)a[i][k+15]*r[k+15][j]+
						(unsigned ll)a[i][k+16]*r[k+16][j]+
						(unsigned ll)a[i][k+17]*r[k+17][j]
					)%P;
				for(; k<S; ++k)
					ans[i][j]=(ans[i][j]+(ll)a[i][k]*r[k][j])%P;
			}
			return ans;
		}
	} A;
	int Pow(ll x, int y=P-2){
		int ans=1;
		for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
		return ans;
	}
	matrix Pow(matrix x, int y){
		matrix ans;
		memset(ans.a, 0, sizeof ans);
		for(int i=0; i<S; ++i) ans[i][i]=1;
		for(; y; y>>=1, x=x*x) if(y&1) ans=ans*x;
		return ans;
	}
	vector<int> main(int n, int *a){
		cnt=best=0;
		memset(ans, 0, sizeof ans), memset(d, 0, sizeof d);
		for(int i=1; i<=n; ++i){
			int now=a[i];
			for(int j=0; j<d[cnt]; ++j)
				now=(now+(ll)(P-ans[cnt][j])*a[i-j-1])%P;
			if(!(f[i]=now)) continue;
			fail[cnt]=i;
			if(!cnt){ d[++cnt]=i; continue;}
			int k=(ll)f[i]*Pow(f[fail[best]])%P;
			++cnt, d[cnt]=i-fail[best]-1, ans[cnt][d[cnt]++]=k;
			for(int j=0; j<d[best]; ++j)
				ans[cnt][d[cnt]++]=(ll)(P-k)*ans[best][j]%P;
			d[cnt]=max(d[cnt], d[cnt-1]);
			for(int j=0; j<d[cnt-1]; ++j) (ans[cnt][j]+=ans[cnt-1][j])%=P;
			if(i-fail[best]+d[best]>=d[cnt-1]) best=cnt-1;
		}
		return vector<int>(ans[cnt], ans[cnt]+d[cnt]);
	}
	int solve(int n, int *a, int m){
		// if(m<=n) return a[m];
		auto g=main(n, a);
		S=g.size();
		// cerr<<S<<endl;
		memset(A.a, 0, sizeof A.a);
		for(int i=1; i<S; ++i) A[i][i-1]=1;
		for(int i=0; i<S; ++i) A[i][S-1]=g[S-i-1];
		A=Pow(A, m-1);
		int ans=0;
		for(int i=0; i<S; ++i) ans=(ans+(ll)a[i+1]*A[i][0])%P;
		return ans;
	}
}
int main() {
	// freopen("1.in", "r", stdin);
	scanf("%s%d", s+1, &n), m=strlen(s+1), n+=m;
	f[0][0][m+1]=1;
	for(int i=1; i<=L; ++i){
		for(int j=0; j<=m; ++j){
			for(int k=j+1; k<=m+1; ++k){
				if(s[j+1]==s[k-1])
					(f[i][j+1][max(k-1, j+2)]+=f[i-1][j][k])%=P,
					(f[i][j][k]+=f[i-1][j][k]*25)%=P;
				else{
					int tot=26;
					if(j<m) (f[i][j+1][max(k, j+2)]+=f[i-1][j][k])%=P, --tot;
					if(k>1) (f[i][j][max(k-1, j+1)]+=f[i-1][j][k])%=P, --tot;
					(f[i][j][k]+=f[i-1][j][k]*tot)%=P;
				}
			}
			(a[i]+=f[i][j][j+1])%=P;
			if(s[j+1]==s[j+2]) (b[i]+=f[i][j][j+3])%=P;
		}
	}
	// cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	printf("%d\n", (P+BM::solve(L, a, (n+1)/2)-(n&1?BM::solve(L, b, n/2):0))%P);
	// cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}