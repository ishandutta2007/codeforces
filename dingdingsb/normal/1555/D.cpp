// Problem: D. Say No to Palindromes
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=2e5+100;
int n,m;;char str[N];
char now[N];
void gen(char a,char b){
	now[1]=a,now[2]=b;
	for(int i=3;i<=n;i++){
		static int flag[3];memset(flag,0,sizeof flag);
		flag[now[i-1]-'a']=1;flag[now[i-2]-'a']=1;
		for(int j=0;j<3;j++)if(!flag[j])
			now[i]=j+'a';
	}
}
int sum[7][N];
signed main(){
	read(n,m);scanf("%s",str+1);
	gen('a','b');for(int i=1;i<=n;i++)sum[1][i]=sum[1][i-1]+(now[i]!=str[i]);
	gen('a','c');for(int i=1;i<=n;i++)sum[2][i]=sum[2][i-1]+(now[i]!=str[i]);
	gen('b','a');for(int i=1;i<=n;i++)sum[3][i]=sum[3][i-1]+(now[i]!=str[i]);
	gen('b','c');for(int i=1;i<=n;i++)sum[4][i]=sum[4][i-1]+(now[i]!=str[i]);
	gen('c','a');for(int i=1;i<=n;i++)sum[5][i]=sum[5][i-1]+(now[i]!=str[i]);
	gen('c','b');for(int i=1;i<=n;i++)sum[6][i]=sum[6][i-1]+(now[i]!=str[i]);
	while(m--){
		int l,r;read(l,r);int ans=0x3f3f3f3f;
		for(int i=1;i<=6;i++)chkmn(ans,sum[i][r]-sum[i][l-1]);
		write(ans);putchar('\n');
	}
	return 0;
	cout<<"ccfn***";;
}