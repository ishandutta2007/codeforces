#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6,INF=1e9;
typedef long long ll;
struct BIT{
	vector<int> c;
	BIT(int n){ c=vector<int>(n+1,-INF); }
	inline void add(int x,int k){
		for(;x<c.size();x+=x&-x) c[x]=max(c[x],k);
	}
	inline int query(int x){
		int ret=-INF;
		for(;x;x-=x&-x) ret=max(ret,c[x]);
		return ret;
	}
};
int id[N],rid[N],val[N],f[N];
ll a[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		a[0]=0;
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]),a[i]+=a[i-1];
//		for(int i=0;i<=n;++i) printf("{%lld}",a[i]); puts("");
		vector<ll> data;
		for(int i=0;i<=n;++i) data.push_back(a[i]);
		sort(data.begin(),data.end());
		data.erase(unique(data.begin(),data.end()),data.end());
		for(int i=0;i<=n;++i){
			id[i]=lower_bound(data.begin(),data.end(),a[i])-data.begin()+1;
			rid[i]=data.size()-id[i]+1;
//			printf("<%d %d>",id[i],rid[i]);
		}
		BIT bit0(data.size()),bit1(data.size());
		for(int i=0;i<=data.size();++i) val[i]=-INF;
		for(int i=0;i<=n;++i){
			if(i>0) f[i]=max({bit0.query(id[i]-1)+i,bit1.query(rid[i]-1)-i,val[id[i]]});
			else f[i]=0;
			bit0.add(id[i],f[i]-i);
			bit1.add(rid[i],f[i]+i);
			val[id[i]]=max(val[id[i]],f[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}