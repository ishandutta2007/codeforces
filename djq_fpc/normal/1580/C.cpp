#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
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
int n,m,i,j,k,px[200005],py[200005],t[200005],ans[400005];
struct ii
{
	int mod,x,l,v;
};
vector<ii> v;
bool cmp(ii x,ii y)
{
	if(x.mod!=y.mod)return x.mod<y.mod;
	if(x.x!=y.x)return x.x<y.x;
	return x.l<y.l;
}
void push(int mod,int x,int l,int val)
{
//	assert(1<=mod&&mod<=m);
	if(mod==7787){
		int a;a++;
	}
	if(l>m)return;
	v.push_back((ii){mod,x,l,val});
}
int main()
{
//	freopen("data.txt","r",stdin);
	read(n);read(m);
	fz1(i,n)read(px[i]),read(py[i]);
	fz1(i,m){
		int op,x;
		read(op);read(x);
		if(op==1){
			t[x]=i;
			if(t[x]+px[x]+py[x]>m){
				if(t[x]+px[x]<=m){
					ans[t[x]+px[x]]++;
				}
				continue;
			}
			push(px[x]+py[x],(t[x]+px[x])%(px[x]+py[x]),t[x]+px[x],1);
			push(px[x]+py[x],(t[x]+px[x]+py[x])%(px[x]+py[x]),t[x]+px[x]+py[x],-1);
		}
		else{
			if(t[x]+px[x]+py[x]>m){
				if(t[x]+px[x]<=i){
					ans[i]--;
				}
				else if(t[x]+px[x]<=m){
					ans[t[x]+px[x]]--;
				} 
				continue;
			}
			push(px[x]+py[x],(t[x]+px[x])%(px[x]+py[x]),i,-1);
			push(px[x]+py[x],(t[x]+px[x]+py[x])%(px[x]+py[x]),i+py[x],1);
			if((i-t[x])%(px[x]+py[x])>=px[x]+1){
				ans[i]--;
				ans[t[x]+(1+(i-t[x])/(px[x]+py[x]))*(px[x]+py[x])]++;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
//	ff(v,it){
//		cerr<<it->mod<<' '<<it->x<<' '<<it->l<<' '<<it->v<<endl;
//	}
	j=0;
	while(j<v.size()){
		i=v[j].mod;
		int t=v[j].x,s=0;
		for(k=t;k<=m;k+=i){
			while(j<v.size()&&v[j].mod==i&&v[j].x==t&&v[j].l<=k){
				s+=v[j++].v;
			}
			ans[k]+=s;
		}
		while(j<v.size()&&v[j].mod==i&&v[j].x==t)j++;
	}
	fz1(i,m){
		ans[i]+=ans[i-1];
		printf("%d\n",ans[i]);
	}
	return 0;
}