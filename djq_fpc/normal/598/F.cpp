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
const long double eps=1e-6;
int n,m,i,j,cnt[4005];
struct ii
{
	long double x,y;
	long double dis()
	{
		return sqrt(x*x+y*y);
	}
}a[1005],b[105];
struct lne
{
	ii x,v;
}c[1005],t;
ii operator +(ii x,ii y)
{
	return (ii){x.x+y.x,x.y+y.y};
}
ii operator *(ii x,long double y)
{
	return (ii){x.x*y,x.y*y};
}
ii operator -(ii x,ii y)
{
	return (ii){x.x-y.x,x.y-y.y};
}
long double crs(ii x,ii y)
{
	return x.x*y.y-x.y*y.x;
}
vector<pair<long double,int> > res;
int sgn(long double x)
{
	if(x>eps) return 1;
	if(x<-eps) return -1;
	return 0;
}
pair<long double,int> tmp;
vector<pair<pair<long double,long double>,int> > ss;
bool ins(lne x,lne y,bool f=0)
{
	if(abs(crs(x.v,y.v))<eps){
		if(abs(crs(x.v,y.x-x.x))<eps&&abs(crs(x.v,y.x+y.v-x.x))<eps){
			tmp=make_pair(0,0);
			ii t=y.x;
			long double len1=(t-x.x).dis();
			t=y.x+y.v;
			long double len2=(t-x.x).dis();
			ss.push_back(make_pair(make_pair(min(len1,len2),max(len1,len2)),12345));
			return 0;
		}
		return 0;
	}
	long double t=crs(y.x-x.x,y.x+y.v-x.x)/crs(x.v,y.v);
	ii p=x.x+x.v*t;
	if(p.x>y.x.x+eps&&p.x>y.x.x+y.v.x+eps) return 0;
	if(p.y>y.x.y+eps&&p.y>y.x.y+y.v.y+eps) return 0;
	if(p.x<y.x.x-eps&&p.x<y.x.x+y.v.x-eps) return 0;
	if(p.y<y.x.y-eps&&p.y<y.x.y+y.v.y-eps) return 0;
	tmp=(make_pair(t*x.v.dis(),sgn(crs(x.v,y.v))));
	return 1;
}
int main()
{
	cin>>n>>m;
	fz1(i,n){cin>>a[i].x>>a[i].y;/*a[i].x+=(rand()-RAND_MAX/2)/RAND_MAX*1e-9;a[i].y+=(rand()-RAND_MAX/2)/RAND_MAX*1e-9;*/}
	a[n+1]=a[1];fz1(i,n) c[i]=(lne){a[i],a[i+1]-a[i]};
	while(m--){
		cin>>t.x.x>>t.x.y>>t.v.x>>t.v.y;
		t.v=t.v-t.x;
		long double dlt=1e18;
		if(abs(t.v.x)>eps){
			dlt=min(dlt,240000/abs(t.v.x));
		}
		if(abs(t.v.y)>eps){
			dlt=min(dlt,240000/abs(t.v.y));
		}
		t.x=t.x+t.v*dlt;
		fz1(i,n){
			if(ins(t,c[i]))if(tmp.second==1) break;
		}
		if(i>n){
			puts("0");
			continue;
		}
		j=i;ss.clear();
		long double ans=0,ans2=0;
		long double lst;bool f=0;
		do{
			if(ins(t,c[j],f)){
				if(tmp.second==1){
					if(!f){
						f=1;
						lst=tmp.first;
					}
				}
				else if(tmp.second==-1){
					if(f){
						f=0;
						ss.push_back(make_pair(make_pair(min(abs(tmp.first),abs(lst)),max(abs(tmp.first),abs(lst))),(abs(tmp.first)<abs(lst)?1:-1)));
					}
				}
			}
			j=(j==n?1:j+1);
		}
		while(j!=i);
		vector<long double> all;
		ff(ss,it){
			all.push_back(it->first.first);
			all.push_back(it->first.second);
		}
		sort(all.begin(),all.end());
		all.resize(unique(all.begin(),all.end())-all.begin());
		fz1(i,all.size()) cnt[i]=0;
		ff(ss,it){
//			cerr<<it->first.first<<' '<<it->first.second<<' '<<it->second<<endl;
			int l=upper_bound(all.begin(),all.end(),it->first.first)-all.begin();
			int r=upper_bound(all.begin(),all.end(),it->first.second)-all.begin();
			cnt[l]+=it->second;cnt[r]-=it->second;
		}
		fz1(i,all.size()) cnt[i]+=cnt[i-1];
		fz1(i,all.size()) if(cnt[i]) ans+=(all[i]-all[i-1]);
		printf("%.10Lf\n",ans);
	}
	return 0;
}