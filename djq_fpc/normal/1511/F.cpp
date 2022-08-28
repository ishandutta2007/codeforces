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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
const int mod=998244353;
const long long mod2=1ll*mod*mod;
int n,m,i,j,k,cnt=1,ch[45][26],ed[45];
int a[1005][1005],b[1005][1005];
long long c[1005][1005];
string st;
int id[45][45],cid;
void dfs(int x,int y)
{
	if(id[x][y]) return;
	if(x>y) id[x][y]=-1; else id[x][y]=++cid;
	if(ed[x]) dfs(1,y);
	if(ed[y]) dfs(x,1);
	int i;
	fz0k(i,26)if(ch[x][i]&&ch[y][i])dfs(ch[x][i],ch[y][i]);
}
int main()
{
	cin>>n>>m;
	while(n--){
		cin>>st;
		int x=1;
		fz0k(i,st.size()){
			if(!ch[x][st[i]-'a']){
				ch[x][st[i]-'a']=++cnt;
			}
			x=ch[x][st[i]-'a'];
		}
		ed[x]++;
	}
	dfs(1,1);
	int x,y;
	fz1(x,cnt)fz1(y,cnt)if(x>y) id[x][y]=id[y][x];
	fz1(x,cnt)fz1(y,cnt)if(x<=y&&id[x][y]){
		fz0k(i,26)if(ch[x][i]&&ch[y][i]){
			a[id[x][y]][id[ch[x][i]][ch[y][i]]]+=1;
			a[id[x][y]][id[ch[x][i]][1]]+=ed[ch[y][i]];
			a[id[x][y]][id[1][ch[y][i]]]+=ed[ch[x][i]];
			a[id[x][y]][id[1][1]]+=ed[ch[x][i]]*ed[ch[y][i]];
		}
	}
	cerr<<cid<<endl;
//	fz1(x,cnt)fz1(y,cnt)fz1(i,cnt)fz1(j,cnt)if(a[id[x][y]][id[i][j]]){
//		cerr<<x<<' '<<y<<' '<<i<<' '<<j<<' '<<a[id[x][y]][id[i][j]]<<endl;
//	}
	fz1(i,cid) b[i][i]=1;
	while(m){
		if(m&1){
			fz1(i,cid)fz1(j,cid){
				c[i][j]=0;
				fz1(k,cid){
					c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j]);
					if(c[i][j]>=mod2)c[i][j]-=mod2;
				}
			}
			fz1(i,cid)fz1(j,cid){
				b[i][j]=c[i][j]%mod;
			}
		}
		m/=2;
		fz1(i,cid)fz1(j,cid){
			c[i][j]=0;
			fz1(k,cid){
				c[i][j]=(c[i][j]+1ll*a[i][k]*a[k][j]);
				if(c[i][j]>=mod2)c[i][j]-=mod2;
			}
		}
		fz1(i,cid)fz1(j,cid){
			a[i][j]=c[i][j]%mod;
		}
	}
	cout<<b[id[1][1]][id[1][1]]<<endl;
	return 0;
}