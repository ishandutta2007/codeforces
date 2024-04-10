#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
int popcnt[N],cnt[N];
ll a[N],ret=0;
int popcount(ll x){
	if(x==0) return 0;
	return 1+popcount(x-(x&-x));
}
void solve(vector<pair<ll,int> >& f,vector<pair<ll,int> >& g){
	vector<pair<ll,int> > mxf(f.size()),mif(f.size()),mxg(g.size()),mig(g.size());
	mxf[0]=mif[0]=f[0];
	for(int i=1;i<f.size();++i){
		mxf[i]=max(mxf[i-1],f[i]);
		mif[i]=min(mif[i-1],f[i]);
	}
	mxg[0]=mig[0]=g[0];
	for(int i=1;i<g.size();++i){
		mxg[i]=max(mxg[i-1],g[i]);
		mig[i]=min(mig[i-1],g[i]);
	}
	int p1=0,p2=0,p=0; 	
	for(int i=0;i<f.size();++i){
		for(;p1<g.size()&&mif[i]<mig[p1];++p1){
			if(p2>p1)
				cnt[popcnt[mig[p1].second]]--;
		}
		for(;p2<g.size()&&mxf[i]>mxg[p2];++p2){
			if(p2>=p1)
				cnt[popcnt[mig[p2].second]]++;	
		}
		for(;p<g.size()&&(mxg[p]<mxf[i]&&mig[p]>mif[i]);++p);
		if(popcnt[mxf[i].second]==popcnt[mif[i].second])
			ret+=p;
		ret+=cnt[popcnt[mxf[i].second]];	
	}
	for(int i=0;i<g.size();++i) cnt[popcnt[g[i].second]]=0;
	swap(f,g); swap(mxf,mxg); swap(mif,mig);
	p1=0,p2=0,p=0; 	
	for(int i=0;i<f.size();++i){
		for(;p1<g.size()&&mif[i]<mig[p1];++p1){
			if(p2>p1)
				cnt[popcnt[mig[p1].second]]--;
		}
		for(;p2<g.size()&&mxf[i]>mxg[p2];++p2){
			if(p2>=p1)
				cnt[popcnt[mig[p2].second]]++;	
		}
		for(;p<g.size()&&(mxg[p]<mxf[i]&&mig[p]>mif[i]);++p);
		if(popcnt[mxf[i].second]==popcnt[mif[i].second])
			ret+=p;
		ret+=cnt[popcnt[mxf[i].second]];	
	}
	for(int i=0;i<g.size();++i) cnt[popcnt[g[i].second]]=0;
}
void dc(int l,int r){
	if(l==r){
		ret++;
		return;
	}
	int m=l+r>>1;
	vector<pair<ll,int> > f,g; f.reserve(m-l+1); g.reserve(r-m);
	for(int i=m;i>=l;--i) f.push_back(make_pair(a[i],i));
	for(int i=m+1;i<=r;++i) g.push_back(make_pair(a[i],i));
	solve(f,g); 
	dc(l,m); dc(m+1,r);
}
int main(){
//	freopen("1.in","r",stdin);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),popcnt[i]=popcount(a[i]);
	dc(1,n);
	printf("%lld\n",ret);
//	cerr<<ret<<" "<<ret2<<endl;
//	assert(ret==ret2);
	return 0;
}