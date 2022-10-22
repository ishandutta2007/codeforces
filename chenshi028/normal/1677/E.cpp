#include<utility>
#include<iostream>
#include<vector>
using namespace std;
const int o=1e6+10;
int n,q,p[o],mn[o],cnt[o],flg[o],st[o][20],lg[o],tim[o],asd,fmn[o],tmn[o],lft[o],rgt[o];long long ans[o],s[o],s2[o];
vector<pair<pair<int,int>,int> > chg[o/3];vector<pair<pair<int,int>,int> > ask[o/3];
void build(int id,int l,int r){
	cnt[id]=r-l+1;tim[id]=1;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void ad(int id,int val,int v,int tm){
	if(v+flg[id]<fmn[id]) fmn[id]=v+flg[id],tmn[id]=tm;
	else if(v+flg[id]==fmn[id]) tmn[id]+=tm;
	s[id]+=cnt[id]*!(mn[id]+v)*1ll*tm;tim[id]=asd;mn[id]+=val;flg[id]+=val;
}
inline void pushdown(int id){
	tmn[id]+=(asd-tim[id])*(flg[id]==fmn[id]);s[id]+=cnt[id]*!mn[id]*1ll*(asd-tim[id]);
	ad(id<<1,flg[id],fmn[id],tmn[id]);ad((id<<1)|1,flg[id],fmn[id],tmn[id]);flg[id]=fmn[id]=tmn[id]=0;tim[id]=asd;
}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){
		if(val<0) ad(id,val,val,0);
		else ad(id,val,0,asd-tim[id]);
		return;
	}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);cnt[id]=cnt[id<<1]*(mn[id]==mn[id<<1])+cnt[(id<<1)|1]*(mn[id]==mn[(id<<1)|1]);
}
inline int Query(int l,int r){int t=lg[r-l+1];return max(st[l][t],st[r-(1<<t)+1][t]);}
long long query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return s[id]+cnt[id]*!mn[id]*(asd-tim[id]+1ll);
	pushdown(id);
	int md=l+r>>1;
	return (ql<=md?query(id<<1,ql,qr,l,md):0)+(md<qr?query((id<<1)|1,ql,qr,md+1,r):0);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;lg[0]=-1;
	for(int i=1;i<=n;++i) cin>>st[i][0],lg[p[st[i][0]]=i]=lg[i>>1]+1;
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) st[j][i]=max(st[j][i-1],(j+(1<<i-1)<=n)?st[j+(1<<i-1)][i-1]:0);
	for(int i=1,l,r,md;i<=n;++i){
		for(l=1,r=p[i];l<r;) if(Query(md=l+r>>1,p[i])==i) r=md;else l=md+1;
		lft[i]=l;
		for(l=p[i],r=n;l<r;) if(Query(p[i],md=(l+r>>1)+1)==i) l=md;else r=md-1;
		rgt[i]=r;
	}
	for(int i=1,L,R,l1,r1,l2,r2,l,r,md;i<=n;++i) for(int j=1;i*j<=n;++j) if(i^j){
		if((L=p[i])>(R=p[j])) swap(L,R);
		if(Query(L=min(L,p[i*j]),max(R,p[i*j]))>i*j) continue;
		l1=lft[i*j];r1=min(p[i*j],L);l2=max(p[i*j],R);r2=rgt[i*j];
		chg[r1].push_back(make_pair(make_pair(l2,r2),1));chg[l1-1].push_back(make_pair(make_pair(l2,r2),-1));
	}
	for(int i=1,l,r;i<=q;++i)
		cin>>l>>r,ask[l].push_back(make_pair(make_pair(l,r),i)),ans[i]=(r-l+1ll)*(n-l+1);
	build(1,1,n);
	bool yny=(n==200000);
	for(int i=1;i<=n;++i) yny&=(p[i]==i);
	for(int i=n;i;--i){
		asd=n-i+1;
		for(int j=chg[i].size();j--;) modify(1,chg[i][j].first.first,chg[i][j].first.second,chg[i][j].second);
		for(int j=ask[i].size();j--;) ans[ask[i][j].second]-=query(1,ask[i][j].first.first,ask[i][j].first.second);
	}
	for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
	return 0;
}