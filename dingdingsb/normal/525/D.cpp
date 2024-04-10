#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
#define lowbit(x) ((x)&-(x))
const int N=2100;
int n,m;
char s[N][N];
int cnt(int x,int y){
	int cnt=0;
	for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)
		if(s[x+i][y+j]=='.')cnt++;
	return cnt;
}
void dfs(int x,int y){
	if(x<1||x>n||y<1||y>m)return;
	if(s[x][y]=='.')return;
	if(cnt(x-1,y-1)==3||cnt(x-1,y)==3||cnt(x,y-1)==3||cnt(x,y)==3){
		s[x][y]='.';
		for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)
			dfs(x+i,y+j);
	}
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		dfs(i,j);
	for(int i=1;i<=n;i++)puts(s[i]+1);
}