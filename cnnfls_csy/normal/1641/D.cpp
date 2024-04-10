/////
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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,k,ans=2147483647,vis[500005],id[500005],typ[500005];
vector<int> all;
struct ii
{
	int val;vector<int> v;int id;
	bool count(int x){ff(v,it)if(*it==x)return 1;return 0;}
	void erase(int x){ff(v,it)if(*it==x){v.erase(it);return;}}
}a[100005];
bool cmp(ii x,ii y){return x.val<y.val;}
bool check(ii x,ii y)
{
	int i,j,ans=1;
	fz0k(i,x.v.size())vis[x.v[i]]=1;
	fz0k(j,y.v.size())if(vis[y.v[j]]) {ans=0;break;}
	fz0k(i,x.v.size())vis[x.v[i]]=0;
	return ans;
}
void solve(vector<ii> v1,vector<ii> v2)
{
//	ff(v1,it) cerr<<it->id<<' ';cerr<<endl; 
//	ff(v2,it) cerr<<it->id<<' ';cerr<<endl;
	if(v1.empty()||v2.empty()) return;
	if(v1[0].val+v2[0].val>=ans) return;
	if(check(v1[0],v2[0])){/*cerr<<v1[0].id<<' '<<v2[0].id<<endl;*/ans=min(ans,v1[0].val+v2[0].val);return;}
	int i,j;
	fz1(i,v1.size()-1){
		if(check(v1[i],v2[0])){
//			cerr<<v1[i].id<<' '<<v2[0].id<<endl;
			ans=min(ans,v1[i].val+v2[0].val);
			while(v1.size()>i) v1.pop_back();
			break;
		}
	}
	fz1(i,v2.size()-1){
		if(check(v2[i],v1[0])){
//			cerr<<v2[i].id<<' '<<v1[0].id<<endl;
			ans=min(ans,v2[i].val+v1[0].val);
			while(v2.size()>i) v2.pop_back();
			break;
		}
	}
	fz0k(i,v2[0].v.size()){
		vector<ii> nv1,nv2;
		fz1(j,v1.size()-1){
			if(v1[j].count(v2[0].v[i])){
				nv1.push_back(v1[j]);
				nv1.back().erase(v2[0].v[i]);
			}
		}
		fz1(j,v2.size()-1){
			if(!v2[j].count(v2[0].v[i])){
				nv2.push_back(v2[j]);
			}
		}
		solve(nv1,nv2);
	}
}
int main()
{
	read(n);read(m);
	fz1(i,n){
		fz1(j,m){
			int x;read(x);
			a[i].v.push_back(x);
			all.push_back(x);
		}
		read(a[i].val);
		a[i].id=i;
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	fz1(i,n){
		ff(a[i].v,it) *it=upper_bound(all.begin(),all.end(),*it)-all.begin();
	}
	sort(a+1,a+n+1,cmp);
	fz(i,2,n){
		if(check(a[1],a[i])){
			ans=a[1].val+a[i].val;
			n=i-1;
			break;
		}
	}
	fz0k(i,a[1].v.size()){
		vector<ii> v1,v2;
		fz(j,2,n){
			if(a[j].count(a[1].v[i])) v1.push_back(a[j]); else v2.push_back(a[j]);
		}
		ff(v1,it){
			it->erase(a[1].v[i]);
		}
		solve(v1,v2);
	}
/*	fz1(i,(1<<a[1].v.size())-1){
		vector<ii> v1,v2;
		fz(j,2,n){
			int ck1=0,ck2=1;
			fz0k(k,a[1].v.size())if((i>>k)&1){
				if(a[j].v.count(a[1].v[k])) ck1++,ck2=0;
			}
			if(ck1==__builtin_popcount(i)) v1.push_back(a[j]);
			if(ck2) v2.push_back(a[j]);
		}
		ff(v1,it){
			fz0k(k,a[1].v.size())if((i>>k)&1) *it->erase(a[1].v[k]);
		}
		solve(v1,v2);
	}*/
	if(ans==2147483647) puts("-1"); else printf("%d\n",ans);
	return 0;
}