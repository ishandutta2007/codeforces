//

// Problem: CF512E Fox And Polygon
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF512E
// Memory Limit: 250 MB
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
const int N=1e3+10;
int n;
bitset<N>e[N];
vector<pair<int,int>>kk(bool inv){
	for(int i=1;i<=n;i++)e[i].reset();
	for(int i=1;i<=n;i++)
		e[i][i%n+1]=e[i%n+1][i]=1;
	for(int i=1,a,b;i<=n-3;i++)
		read(a,b),e[a][b]=e[b][a]=1;
	vector<pair<int,int>>res;
	auto flip=[&](int x,int y){
		assert(e[x][y]&&e[y][x]);
		bitset<N>tmp=e[x]&e[y];tmp[x]=tmp[y]=0;
		int a=tmp._Find_first();tmp[a]=0;
		int b=tmp._Find_first();tmp[b]=0;
		e[a][b]=e[b][a]=1;e[x][y]=e[y][x]=0;
		return inv?mp(a,b):mp(x,y);
	};
	for(int i=2;i<n;i++)while(!e[1][i]){
		int j=i;while(e[1][j]==0)j++;
		res.pb(flip(i-1,j));
	}
	return res;
}
signed main(){
	read(n);
	auto A=kk(0);
	auto B=kk(1);
	reverse(B.begin(),B.end());
	write(A.size()+B.size());pc('\n');
	for(auto [x,y]:A)write(x),pc(' '),write(y),pc('\n');
	for(auto [x,y]:B)write(x),pc(' '),write(y),pc('\n');
}