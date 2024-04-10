#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
const int o=2e5+10;
int n,cnt,ans,mn[o*4],f[o];pair<int,int> p[o];vector<int> vec[o];
inline bool cmp(pair<int,int> A,pair<int,int> B){return A.second<B.second;}
void build(int id,int l,int r){
	mn[id]=o;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify(int id,int pos,int val,int l=1,int r=n){
	if(l==r){mn[id]=val;return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
int query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mn[id];
	int md=l+r>>1;
	return min((ql<=md)?query(id<<1,ql,qr,l,md):o,(md<qr)?query((id<<1)|1,ql,qr,md+1,r):o);
}
int main(){
	scanf("%d",&n);ans=n+1;
	for(int i=1,a;i<=n;f[i++]=o) scanf("%d",&a),vec[a].push_back(i);
	for(int i=1;i<=n;++i) if(vec[i].size()) p[++cnt]=make_pair(vec[i][0],vec[i][vec[i].size()-1]);
	sort(p+1,p+cnt+1);build(1,1,n);
	for(int i=1,r=0;i<=cnt;r=max(r,p[i++].second)) if(p[i].first>r) modify(1,p[i].first,f[p[i].first]=0);
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;++i) if(f[p[i].second])
		modify(1,p[i].second,f[p[i].second]=query(1,p[i].first,p[i].second)+1);
	for(int i=0;i<=n;++i) if(!f[i+1]) ans-=f[i]+1;
	printf("%d",ans);
	return 0;
}