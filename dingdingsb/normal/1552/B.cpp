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
const int N=5e5+100;
int t,n,r[N][5],p[N];
bool cmp(int x,int y){
	int cnt=0;
	for(int i=0;i<5;i++)
		if(r[x][i]<r[y][i])cnt++;
	return cnt>=3;
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<5;j++)
				read(r[i][j]);
		for(int i=1;i<=n;i++)p[i]=i;
		sort(p+1,p+1+n,cmp);
		for(int i=2;i<=n;i++)
			if(!cmp(p[1],p[i])){
				puts("-1");
				goto loop;
			}
		write(p[1]);putchar('\n');
		loop:;
	}
}