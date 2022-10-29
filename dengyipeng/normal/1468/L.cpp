using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#define N 1005
#define ll long long
ll mul(ll a,ll b,ll mo){
	a%=mo,b%=mo;
	ll c=a*b-(ll)((long double)a*b/mo)*mo;
	if (c<0) c+=mo;
	if (c>=mo) c-=mo;
	return c;
}
ll qpow(ll x,ll y,ll mo){
	ll r=1;
	for (;y;y>>=1,x=mul(x,x,mo))
		if (y&1)
			r=mul(r,x,mo);
	return r;
}
int n,k;
ll a[N];
ll p[N][100],np[N];
const int tst[10]={2,3,5,7,11,13,17,19,23,29};
bool mr(ll x){
	if (x==1 || x==0)
		return 0;
	for (int i=0;i<10;++i){
		if (x==tst[i])
			return 1;
		if (x%tst[i]==0)
			return 0;
	}
	ll z=x-1,y=0;
	while (z&1^1)
		z>>=1,++y;
	for (int i=0;i<10;++i){
		ll t=qpow(tst[i],z,x);
		if (t==1 || t==x-1)
			continue;
		for (int j=1;j<y;++j){
			t=mul(t,t,x);
			if (t==x-1)
				break;
		}
		if (t!=x-1)
			return 0;
	}
	return 1;
}
#define irand (rand()*RAND_MAX+rand())
ll gcd(ll a,ll b){
	ll k;
	while (b)
		k=a%b,a=b,b=k;
	return a;
}
ll pr(ll n){
	while (1){
		ll a=irand%n,c=irand%n,b=a,s=1;
		for (int i=1,k=2;1;++i){
			a=(mul(a,a,n)+c)%n;
			if (a==b)
				break;
			ll t=mul(s,abs(a-b),n);
			if (t==0)
				return gcd(s,n);
			s=t;
			if (i==k){
				ll g=gcd(s,n);
				if (g!=1)
					return g;
				b=a;
				k<<=1;
				continue;
			}
			if (!(i&127)){
				ll g=gcd(s,n);
				if (g!=1)
					return g;
			}
		}
	}
}
void divide(ll x,int id){
	if (x==1)
		return;
	if (mr(x)){
		p[id][np[id]++]=x;
		return;
	}
	ll d=pr(x);
	divide(d,id);
	divide(x/d,id);
}
map<int,pair<int,int> > S;
set<int> T;
bool legal[N];
bool b[N];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	srand(time(0)* *new(int));
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;++i){
		divide(a[i],i);
		sort(p[i],p[i]+np[i]);
		np[i]=unique(p[i],p[i]+np[i])-p[i];
		if (np[i]==1){
			auto q=S.find(p[i][0]);
			if (q==S.end())
				S[p[i][0]].first=i,b[i]=1;
			else if (q->second.second==0)
				q->second.second=i,b[i]=1;
		}
	}
	for (auto q=S.begin();q!=S.end();)
		if (q->second.second==0)
			q=S.erase(q);
		else
			++q;
	int mn=0;
	np[0]=77114514;
	int ex=0;
	for (int i=1;i<=n;++i){
		legal[i]=1;
		for (int j=0;j<np[i] && legal[i];++j){
			auto q=S.find(p[i][j]);
			if (q==S.end())
				legal[i]=0;
		}
		if (legal[i]){
			if (!b[i]){
				ex++;
				if (np[i]<np[mn])
					mn=i;
			}
		}
		else
			b[i]=0;
	}
	static int ls[N];
	if (k>=S.size()*2){
		k-=S.size()*2;
		if (k>ex){
			printf("0\n");
			return 0;
		}
		for (int i=1;i<=n;++i){
			if (!legal[i])
				continue;
			if (b[i])
				printf("%lld ",a[i]);
			else if (k){
				printf("%lld ",a[i]);
				k--;				
			}
		}
	}
	else if (k>=np[mn]*2+(mn!=0)){
		for (int i=0;i<np[mn];++i){
			T.insert(p[mn][i]);
			ls[i*2+1]=S[p[mn][i]].first;
			ls[i*2+2]=S[p[mn][i]].second;
		}
		int i=np[mn]*2;
		if (k&1)
			ls[++i]=mn;
		for (auto q=S.begin();q!=S.end() && i<k;++q)
			if (T.find(q->first)==T.end()){
				ls[i+1]=q->second.first;
				ls[i+2]=q->second.second;
				i+=2;
			}
		sort(ls+1,ls+k+1);
		for (int i=1;i<=k;++i)
			printf("%lld ",a[ls[i]]);
	}
	else{
		if (k&1)
			printf("0");
		else{
			int i=0;
			for (auto q=S.begin();q!=S.end() && i<k;++q,i+=2){
				ls[i+1]=q->second.first;
				ls[i+2]=q->second.second;
			}
			sort(ls+1,ls+k+1);
			for (int i=1;i<=k;++i)
				printf("%lld ",a[ls[i]]);
		}
	}
	return 0;
}