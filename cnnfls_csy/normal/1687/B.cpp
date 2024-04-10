#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
/*#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif*/
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j;
pair<int,int> seq[505];
string cur;
void solve()
{
	cur.clear();scanf("%d",&n);scanf("%d",&m);
	fz1(i,m) cur.push_back('0');
	fz0k(i,m){
		cur[i]='1';
		printf("? %s\n",cur.c_str());
		fflush(stdout);
		int x;scanf("%d",&x);
		seq[i]=make_pair(x,i);
		cur[i]='0';
	}
	sort(seq,seq+m);
	int lst=0;
	fz0k(i,m){
		cur[seq[i].second]='1';
		printf("? %s\n",cur.c_str());
		fflush(stdout);
		int x;scanf("%d",&x);
		if(x==lst+seq[i].first) lst=x;
		else cur[seq[i].second]='0';
	}
	printf("! %d\n",lst);fflush(stdout);
}
int main()
{
	int t;t=1;
	while(t--) solve();
	return 0;
}