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
const int mod=998244353,inv2=(mod+1)/2;
int n,m,i,j,inv[35],c[35][35],a[35];
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1){
			z=1ll*x*z%mod;
		}
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
struct func
{
	int l,r;
	vector<int> xs;
};
bool operator <(func x,func y)
{
	return x.l<y.l;
}
vector<func> s,nxt;
vector<int> intg(int l,int r)
{
	vector<int> ans,tmp;
	int i,j,k;
	for(i=0;i<s.size();i++){
		tmp.clear();
		tmp.resize(s[i].xs.size()+1);
		if(s[i].l<=l-1000000){
			if(s[i].r<=l-1000000){
				continue;
			}
			else if(l-1000000<s[i].r&&s[i].r<=r-1000000||r-1000000<s[i].r&&s[i].r<=l){
				for(j=1;j<=s[i].xs.size();j++){
					for(k=0;k<=j;k++){
						dec(tmp[k],1ll*inv[j]*s[i].xs[j-1]%mod*c[j][k]%mod*qp(mod-1000000,j-k)%mod)
					}
					inc(tmp[0],1ll*inv[j]*s[i].xs[j-1]%mod*qp(s[i].r,j)%mod)
				}
			}
			else exit(-1);
		}
		else if(l-1000000<s[i].l&&s[i].l<=r-1000000||r-1000000<s[i].l&&s[i].l<=l){
			if(l-1000000<s[i].r&&s[i].r<=r-1000000){
				exit(-1);
			}
			else if(r-1000000<s[i].r&&s[i].r<=l){
				for(j=1;j<=s[i].xs.size();j++){
					dec(tmp[0],1ll*inv[j]*s[i].xs[j-1]%mod*qp(s[i].l,j)%mod)
					inc(tmp[0],1ll*inv[j]*s[i].xs[j-1]%mod*qp(s[i].r,j)%mod)
				}
			}
			else if(l<s[i].r){
				for(j=1;j<=s[i].xs.size();j++){
					dec(tmp[0],1ll*inv[j]*s[i].xs[j-1]%mod*qp(s[i].l,j)%mod)
					inc(tmp[j],1ll*inv[j]*s[i].xs[j-1]%mod)
				}
			}
		}
		else continue;
		while(ans.size()<tmp.size()) ans.push_back(0);
		fz0k(j,tmp.size()) inc(ans[j],tmp[j])
	}
	return ans;
}
int main()
{
	inv[1]=1;
	fz(i,2,32){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	c[0][0]=1;
	fz1(i,32){
		c[i][0]=1;
		fz1(j,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n;
	fz1(i,n){
		double x;
		cin>>x;
		a[i]=x*1000000+0.5;
		if(a[i]==0){
			puts("0");
			return 0;
		}
		a[i]=min(a[i],a[i-1]+1000000);
	}
	vector<int> tmp;tmp.push_back(1);
	s.push_back((func){0,a[1],tmp});
	fz(i,2,n){
		vector<int> all;
		nxt.clear();
		ff(s,it){
			all.push_back(it->l);
			all.push_back(it->r);
			all.push_back(it->l+1000000);
			all.push_back(it->r+1000000);
		}
		sort(all.begin(),all.end());
		all.resize(unique(all.begin(),all.end())-all.begin());
		while(all.back()>a[i]) all.pop_back();
		if(all.back()!=a[i]) all.push_back(a[i]);
		for(j=1;j<all.size();j++){
			nxt.push_back((func){all[j-1],all[j],intg(all[j-1],all[j])});
		}
		s=nxt;
/*		cerr<<i<<":\n";
		ff(s,it){
			cerr<<it->l<<' '<<it->r<<"      ";
			ff(it->xs,it2) cerr<<*it2<<' ';
			cerr<<endl;
		}
		cerr<<endl;*/
	}
	int ans=0;
	ff(s,it){
		fz1(i,it->xs.size()){
			inc(ans,1ll*inv[i]*it->xs[i-1]%mod*qp(it->r,i)%mod)
			dec(ans,1ll*inv[i]*it->xs[i-1]%mod*qp(it->l,i)%mod)
		}
	}
	printf("%d\n",1ll*ans*qp(qp(1000000,mod-2),n)%mod);
	return 0;
}