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
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,fa[2005],fl[2005],a[2005][2005];
int g[2005][2005];
int s[2005][2005];vector<int> bi[2005];
void gen_mat(vector<pair<int,int> > ans)
{
	int i,j;fz1(i,n)bi[i].clear();
	ff(ans,it){
		bi[it->first].push_back(it->second);
		bi[it->second].push_back(it->first);
	}
	fz1(i,n){
		int c=0;
		fz(j,i,n){
			c++;ff(bi[j],it)if(i<=*it&&*it<=j) c--;
			g[i][j]=(c==1);
		}
	}
}
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}
int fndl(int x){if(fl[x]==x)return x;return fl[x]=fndl(fl[x]);}
struct ii{int l,r;};
bool cmp(ii x,ii y){return x.r-x.l<y.r-y.l;}
vector<pair<int,int> > ans;
ii b[4000005];int cnt;
vector<pair<int,int> > tmp;
void link(int x,int y)
{
	ans.push_back(make_pair(x,y));
}
void merge(int x,int y)
{
	if(x>y) swap(x,y);
	fa[fnd(x)]=fnd(y);fl[fndl(y)]=fndl(x);
}
void solve(vector<int> v,int t1,int t2)
{
	if(v.size()==1) return;assert(a[t1][t2]);
	assert(v.size()!=3);
	vector<int> res;
	int i,j;
	if(v.size()%2==0){
		for(i=1;i<v.size();i+=2) res.push_back(fnd(v[i])==fnd(t1)?t1:(fnd(v[i])==fnd(t2)?t2:v[i]));
		for(i=0;i<v.size();i+=2) res.push_back(fnd(v[i])==fnd(t1)?t1:(fnd(v[i])==fnd(t2)?t2:v[i]));
	}
	else{
		for(i=v.size()-2;i>=0;i-=2) res.push_back(fnd(v[i])==fnd(t1)?t1:(fnd(v[i])==fnd(t2)?t2:v[i]));
		i=v.size()-1;res.push_back(fnd(v[i])==fnd(t1)?t1:(fnd(v[i])==fnd(t2)?t2:v[i]));
		for(i=0;i+2<v.size();i+=2) res.push_back(fnd(v[i])==fnd(t1)?t1:(fnd(v[i])==fnd(t2)?t2:v[i]));
	}
/*	for(j=fnd(t1);j>=fndl(t1);j--){
		fz(i,fndl(t2),fnd(t2))if(a[j][i]||(j==t1&&i==t2)) break;
		if(i<=fnd(t2)){t1=j;t2=i;break;}
	}*/
	for(i=0;i+1<v.size();i++){
		if(fnd(res[i])==fnd(t2)&&fnd(res[i+1])==fnd(t1)){
			link(t2,t1);
		}
		else{
			link(res[i],res[i+1]);
		}
	}
	for(i=0;i+1<v.size();i++) merge(v[i],v[i+1]);
}
void solve()
{
	read(n);//n=rand()%20+1;
	cnt=0;ans.clear();
/*	vector<pair<int,int> > _;
	vector<int> p;fz1(i,n)p.push_back(i);random_shuffle(p.begin(),p.end());
	fz1(i,n-1) _.push_back(make_pair(p[rand()%i],p[i]));
	fz1(i,n-1){
		int x,y;read(x);read(y);
		_.push_back(make_pair(x,y));
	}
	gen_mat(_);//ff(_,it) cerr<<it->first<<' '<<it->second<<endl;*/
	fz1(i,n)fz(j,i,n){
		char c;
		while(!isdigit(c=getchar()));
		a[i][j]=(c&15);
//		a[i][j]=g[i][j];
		if(i<j&&a[i][j])b[++cnt]=(ii){i,j};
	}
	fz1(i,n) fa[i]=fl[i]=i;
	sort(b+1,b+cnt+1,cmp);
/*	if(t==14){
		fz1(i,cnt) printf("%d %d\n",b[i].l,b[i].r);
		exit(0);
	}*/
	fz1(i,cnt){
		vector<int> v;
		for(j=fnd(b[i].l);j!=fnd(b[i].r);j=fnd(j+1)){
			v.push_back(j);
		}
		v.push_back(fnd(b[i].r));
		solve(v,b[i].l,b[i].r);
//		ff(v,it) fa[fnd(i)]=fnd(v.back());
	}
	ff(ans,it) printf("%d %d\n",it->first,it->second);
	gen_mat(ans);
	fz1(i,n)fz(j,i,n) assert(a[i][j]==g[i][j]);
}
int main()
{
	read(t);
	while(t--){
//		cerr<<"Case "<<t<<":\n";
		solve();
//		cerr<<endl;
	}
	return 0;
}