#include<bits/stdc++.h>
#define pb push_back
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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e2+100;
int t,n,m,k;
char ans[N][N];
char can(int x1,int y1,int x2,int y2){
	for(char i='a';i<='z';i++)
		if(
		ans[x1][y1-1]!=i&&ans[x1][y1+1]!=i&&
		ans[x1-1][y1]!=i&&ans[x1+1][y1]!=i&&
		ans[x2][y2-1]!=i&&ans[x2][y2+1]!=i&&
		ans[x2-1][y2]!=i&&ans[x2+1][y2]!=i)
			return i;
	exit(-1);
}
void solve(int n,int m,int k){
	// n  m  k 
	//n k 
	//
	memset(ans,0,sizeof ans);
	for(int j=1;j<=m-1;j+=2)
		for(int i=1;i<=n-1;i+=2)
			if(k)
			ans[i][j]=ans[i][j+1]=can(i,j,i,j+1),
			ans[i+1][j]=ans[i+1][j+1]=can(i+1,j,i+1,j+1),
			k-=2;
	assert(k==0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]==0)
				ans[i][j]=ans[i+1][j]=can(i,j,i+1,j);
}
void print(){
	puts("YES");
	for(int i=1;i<=n;i++)
		puts(ans[i]+1);
}
signed main(){
	read(t);
	while(t--){
		read(n,m,k);
		if(n%2==0){
			int up=((m/2))*n;
			if(k<=up&&k%2==0){
				solve(n,m,k);
				print();
			}
			else puts("NO");
		}else{
			if(k>=m/2&&(k-m/2)%2==0){
				solve(n-1,m,k-m/2);
				for(int j=1;j<=m-1;j+=2)
					ans[n][j]=ans[n][j+1]=can(n,j,n,j+1);
				print();
			}
			else puts("NO");
		}
	}
}