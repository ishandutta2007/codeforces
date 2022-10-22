#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int T,n,q,a[o],st[o],tp,bl[o][10];long long sm[10][o];bool vis[o];multiset<long long> s;
int main(){
	for(scanf("%d",&T);T--;tp=0,s.clear()){
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=2;i<=n;++i) for(int j=2*i;j<=n;j+=i) vis[j]=1;
		for(int i=2;i<=n;++i) if(!vis[i]&&n%i==0){
			st[++tp]=i;
			for(int j=0;j<n/i;++j) sm[tp][j]=0;
			for(int j=1;j<=n;++j) sm[tp][bl[j][tp]=j%(n/i)]+=a[j];
			for(int j=0;j<n/i;++j) s.insert(sm[tp][j]*(n/i));
		}
		printf("%lld\n",*s.rbegin());
		for(int p,x;q--;printf("%lld\n",*s.rbegin())){
			scanf("%d%d",&p,&x);
			for(int i=1;i<=tp;++i)
				s.erase(s.find(sm[i][bl[p][i]]*(n/st[i]))),s.insert((sm[i][bl[p][i]]+=x-a[p])*(n/st[i]));
			a[p]=x;
		}
	}
	return 0;
}