#include<cstdio>
#include<algorithm>
#include<cctype>
#include<iostream>
using namespace std;
typedef long long ll;
#define G getchar()
inline ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const ll INF=1e18;

int n,k;
ll L[64],R[64],c[64];
ll dp[4][4][64][64][64];
ll S[2][2][64][64];
int e[64];
ll ans=INF;
inline void checkmin(ll &x,ll y){if (y<x) x=y;}
ll getval(int a,int b,int i,int l,int r){
	if (l==1||r==n) return 0;
	if ((a^b)&1) return c[i];
	return 0;
}
ll getval2(int a,int b,int i,int l,int r){
	if (l==1||r==n) return 0;
	ll res=(a^b)&1?c[i]:0;
	ll C=(a&2?R[l-1]:L[l-1])^(b&2?R[r+1]:L[r+1]);
	for (i++;i<k;i++)
		if (C>>i&1) res+=c[i];
	return res;
}
int getnxtl(int a,int b,int p){
	if (p==1) return 0;
	int t=a&2;
	return t+((t?R[p-1]:L[p-1])>>b&1);
}
int getnxtr(int a,int b,int p){
	if (p==n) return 0;
	int t=a&2;
	return t+((t?R[p+1]:L[p+1])>>b&1);
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++){
		L[i]=read(),R[i]=read();
		int &t=e[i];
		for (t=k;t&&(L[i]>>t-1&1)==(R[i]>>t-1&1);t--);
	}
	for (int i=0;i<k;i++) c[i]=read();
	for (int i=0;i<=k;i++)
		for (int a=0;a<4;a++)
			for (int b=0;b<4;b++){
				for (int l=1;l<=n;l++)
					for (int r=l;r<=n;r++)
						dp[a][b][i][l][r]=INF;
				for (int l=1,r=0;r<=n;l++,r++)
					dp[a][b][i][l][r]=INF;
			}
	for (int i=k-1;~i;i--){
		for (int l=1,r=0;r<=n;l++,r++){
			for (int a=0;a<4;a++)
				for (int b=0;b<4;b++){
					dp[a][b][i][l][r]=getval2(a,b,i,l,r);
					//printf("dp %d %d %d %d %d: %lld\n",a,b,i,l,r,dp[a][b][i][l][r]);
				}
		}
		for (int l=n;l;l--)
			for (int r=l;r<=n;r++){
				for (int a=0;a<4;a++)
					for (int b=0;b<4;b++){
						ll &C=dp[a][b][i][l][r];
						bool flg=1;
						for (int m=l;m<=r;m++) if (/*L[m]==R[m]||*/e[m]-1<=i) {flg=0; break;}
						if (!flg) continue;
						/*if (i+1<k) */checkmin(C,dp[getnxtl(a,i+1,l)][getnxtr(b,i+1,r)][i+1][l][r]+getval(a,b,i,l,r));
						for (int m=l;m<=r;m++){
							if (R[m]>>i&1){
								checkmin(C,dp[a][2][i][l][m-1]+dp[2][b][i][m+1][r]);
							}
							if (!(L[m]>>i&1)){
								checkmin(C,dp[a][1][i][l][m-1]+dp[1][b][i][m+1][r]);
							}
						}
						//printf("dp %d %d %d %d %d: %lld\n",a,b,i,l,r,dp[a][b][i][l][r]);
					}
			}
	}
	for (int l=1,r=0;r<=n;l++,r++){
		for (int a=0;a<2;a++)
			for (int b=0;b<2;b++){
				int aa=a?2+(R[l-1]&1):(L[l-1]&1);
				int bb=b?2+(R[r+1]&1):(L[r+1]&1);
				S[a][b][l][r]=dp[aa][bb][0][l][r];
				//printf("S %d %d %d %d: %lld\n",a,b,l,r,S[a][b][l][r]);
			}
	}
	for (int l=n;l;l--)
		for (int r=l;r<=n;r++){
			for (int a=0;a<2;a++)
				for (int b=0;b<2;b++){
					ll &C=S[a][b][l][r];
					int aa=a?2+(R[l-1]&1):(L[l-1]&1);
					int bb=b?2+(R[r+1]&1):(L[r+1]&1);
					C=dp[aa][bb][0][l][r];
					for (int m=l;m<=r;m++){
						for (int c=0;c<2;c++)
							checkmin(C,S[a][c][l][m-1]+S[c][b][m+1][r]);
					}
					//printf("S %d %d %d %d: %lld\n",a,b,l,r,S[a][b][l][r]);
				}
		}
	ll ans=S[0][0][1][n];
	cout<<ans<<endl;
	return 0;
}