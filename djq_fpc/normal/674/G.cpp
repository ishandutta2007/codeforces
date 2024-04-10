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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
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
int n,m,p,t,i,j,a[150005],len[600005],tag[6000005];
vector<pair<int,int> > s[600005];
vector<pair<int,int> > mrg(vector<pair<int,int> > x,vector<pair<int,int> > y)
{
	vector<pair<int,int> > res=x;
	ff(y,it){
		bool f=0;
		ff(res,it2){
			if(it2->first==it->first){
				it2->second+=it->second;
				f=1;
				break;
			}
		}
		if(!f) res.push_back(*it);
	}
	while(res.size()>=t){
		int s=0x3f3f3f3f;
		fz0k(i,t){
			s=min(s,res[i].second);
		}
		fz0k(i,t){
			res[i].second-=s;
		}
		while(!res.empty()&&res.back().second==0) res.pop_back();
		fz0k(i,res.size()){
			if(res[i].second==0){
				swap(res[i],res[res.size()-1]);
				while(!res.empty()&&res.back().second==0) res.pop_back();
			}
		}
	}
	return res;
}
void pushup(int x)
{
	s[x]=mrg(s[x+x],s[x+x+1]);
}
void build(int x,int l,int r)
{
	len[x]=r-l+1;
	if(l==r){
		s[x].push_back(make_pair(a[l],1));
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	pushup(x);
//	cerr<<"("<<l<<","<<r<<"):  ";
//	ff(s[x],it) cerr<<it->first<<' '<<it->second<<"    ";
//	cerr<<endl; 
}
void upd(int x,int y)
{
	s[x].clear();tag[x]=y;
	s[x].push_back(make_pair(y,len[x]));
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){
		upd(x,c);
		return;
	}
	int mid=(l+r)/2;
	pushdo(x);
	if(ql<=mid) update(x+x,l,mid,ql,qr,c);
	if(qr>mid) update(x+x+1,mid+1,r,ql,qr,c);
	pushup(x);
}
vector<pair<int,int> > query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){
		return s[x];
	}
	int mid=(l+r)/2;
	pushdo(x);
	if(qr<=mid) return query(x+x,l,mid,ql,qr);
	if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
	return mrg(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main()
{
	read(n);read(m);read(p);
	t=floor(1/(p/100.0))+1;
	fz1(i,n){
		read(a[i]);
	}
	build(1,1,n);
	while(m--){
		int op;
		read(op);
		if(op==1){
			int l,r,x; 
			read(l);read(r);read(x);
			update(1,1,n,l,r,x);
		}
		else{
			int l,r;
			read(l);read(r);
			vector<pair<int,int> > ans=query(1,1,n,l,r);
			printf("%d",ans.size());
			ff(ans,it)printf(" %d",it->first);
			puts("");
		}
	}
	return 0;
}