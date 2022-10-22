// Problem: C. Omkar and Determination
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e6+100;
int n,m,q;
int nxt[N];
signed main(){
	read(n,m);
	auto M=vector<vector<char>>(n+1,vector<char>(m+1));
	memset(nxt,0x3f,sizeof nxt);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			M[i][j]=getchar();
			while(M[i][j]!='.'&&M[i][j]!='X')
				M[i][j]=getchar();
		}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			if(M[i-1][j]=='X'&&M[i][j-1]=='X')
				nxt[j]=j;
	for(int j=m;j;j--)chkmn(nxt[j],nxt[j+1]);
	read(q);
	while(q--){
		int l,r;read(l,r);
		if(nxt[l+1]>r)puts("YES");
		else puts("NO");
	}
}