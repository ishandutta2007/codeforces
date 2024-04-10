//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;

#define N 700040
int us[N],w,op[N],n,k,h,ch[N],u,v,_u,_v,g[N],fl[N],fa[N],sz[N],Ans,ss[N];
char s[N];
vi V[N];

int lxy;

int fid(int p)
{
	if(p==fa[p])return p;
	return fa[p]=fid(fa[p]);
}


inline void mer(int u, int v)
{
	u=fid(u); v=fid(v);
	_u=ch[u]; _v=ch[v];
	if(!u||!v)return;
	if(u==v)return;
	
	if(!_v){
		swap(u,v);swap(_u,_v);
	}
	//           6  1 0 2
//	if(lxy)cout<<sz[u]<<'*'<<sz[v]<<'*'<<sz[_u]<<'*'<<sz[_v]<<' ';
//                 0           1         0                0
//    if(lxy)cout<<ss[u]<<'*'<<ss[v]<<'*'<<ss[_u]<<'*'<<ss[_v]<<' ';

//                0            1           0           0
//	if(lxy)cout<<fl[u]<<'*'<<fl[v]<<'*'<<fl[_u]<<'*'<<fl[_v]<<' ';
//               0     0   0   0
//	if(lxy)cout<<g[u]<<'*'<<g[v]<<'*'<<g[_u]<<'*'<<g[_v]<<' ';

//	assert(!sz[0]);


//	if(lxy)F(i,1,k)if(fid(i)==u)cout<<i<<'*';


	
	if(ss[u])Ans-=sz[u];else Ans-=sz[_u];
	if(ss[v])Ans-=sz[v];else Ans-=sz[_v];
	
	fa[u]=v;sz[v]+=sz[u];fl[v]|=fl[u];g[v]|=g[u]; if(g[v]&&ch[v])fl[ch[v]]=1;
	if(_u)fa[_u]=_v,sz[_v]+=sz[_u],fl[_v]|=fl[_u],g[_v]|=g[_u];if(g[_v]&&ch[_v])fl[ch[_v]]=1;
	
	if(fl[v]){
		ss[v]=1;
		Ans+=sz[v];
		ss[ch[v]]=0;
	}
	else {
		if(fl[ch[v]]){
			Ans+=sz[ch[v]];
			ss[v]=0;
			ss[ch[v]]=1;
		} else {
			if(sz[v]>sz[ch[v]]){
				Ans+=sz[ch[v]];
				ss[v]=0;
				if(ch[v])ss[ch[v]]=1;
			}else {
				ss[v]=1;
				Ans+=sz[v];
				ss[ch[v]]=0;
			}
		}
	}
}

inline void _Sol_()
{
	read(n);read(k);
	scanf("%s",s+1);F(i,1,n)op[i]=s[i]-48;
	F(i,1,k){
		fa[i]=i;
		read(h);
		F(j,1,h){
			read(w);
			V[w].push_back(i);
		}
	}
	
	F(i,1,n){
		
		if (i==36883)lxy=1; else lxy=0;
		
		if(!op[i]){
		//                 2               16439
		//	if(lxy)cout<<V[i].size()<<'*'<<Ans<<' ';
			
			if(V[i].size()==1){
				u=V[i][0];
				if(!us[u]){
					us[u]=1;
					++Ans;
					fl[u]=1;  // 
					ss[u]=1; // 
					sz[u]=1; 
				} else {
					u=fid(u);
					if(fl[u])goto lll;
					fl[u]=1;
					if(!ss[u]){
						Ans+=sz[u]-sz[ch[u]];
						ss[u]=1;
						ss[ch[u]]=0;
					}
				}
				goto lll;
			}
			
			
			
			u=V[i][0];v=V[i][1];
			u=fid(u);v=fid(v);
			_u=ch[u];_v=ch[v];
			
			if(!_v){
				swap(u,v);swap(_u,_v);
			}
			//         42103 53652	0 34917
//			if(lxy)cout<<u<<'*'<<v<<'*'<<_u<<'*'<<_v<<' ';
			
			if(!us[u]){
				us[u]=1;
				sz[u]=1;
			}
			if(!us[v]){
				us[v]=1;
				sz[v]=1;
			}
			if(_v){
				mer(u,_v);
				goto lll;
			}
			if(ss[u])Ans-=sz[u];
			if(ss[v])Ans-=sz[v];
			ch[u]=v;
			ch[v]=u;
			if(g[u])fl[v]=1; 
			if(g[v])fl[u]=1; 
			if(fl[u]||(!fl[v]&&sz[u]<sz[v])){
				ss[u]=1;Ans+=sz[u];ss[v]=0;
			} else {
				ss[v]=1;Ans+=sz[v];ss[u]=0;
			}
			goto lll;
		}
		if(V[i].size()==0)goto lll;
		if(V[i].size()==1){
			u=V[i][0]; u=fid(u);
			if(!us[u]){
				us[u]=1;
				g[u]=1;
				sz[u]=1;
				goto lll;
			}else {
				g[u]=1;
				if(ch[u]){
					fl[ch[u]]=1;
					if(ss[u]){
						ss[u]=0;
						ss[ch[u]]=1;
						Ans+=sz[ch[u]]-sz[u];
					}
				}
				goto lll;
			}
		}
		u=V[i][0];v=V[i][1];
		if(!us[u]){
			us[u]=1;
			sz[u]=1;
		}
		if(!us[v]){
			us[v]=1;
			sz[v]=1;
		}
		mer(u,v);
		lll:;
		priE(Ans);
	}
}

int main()
{
	int T=1; //read(T);
	while(T--)_Sol_();
}