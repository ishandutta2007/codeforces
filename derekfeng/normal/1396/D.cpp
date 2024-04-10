#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
struct node{int x,y,col;}a[2003];
int L,n,m,ans;
int nx,ny;
vector<int>allx,ally;
vector<node>info[2003];
vector<pii>vec;
set<pii>ST;
multiset<int>mst[2003];
int tg[5003],mx[5003],sm[5003],D[2003],lst[2003];
void built(int i,int l,int r){
	if(l==r){
		tg[i]=mx[i]=D[l];
		sm[i]=(ll)(ally[tg[i]]+1)*(ally[r+1]-ally[l])%M;
		return;
	}
	int md=(l+r)>>1;
	built(i<<1,l,md),built(i<<1|1,md+1,r);
	tg[i]=-1,mx[i]=mx[i<<1|1];
	sm[i]=(sm[i<<1]+sm[i<<1|1])%M;
}
int qry(int i,int l,int r,int w){
	if(l==r){
		if(mx[i]<=w)return -1;
		return l;
	}
	int ls=i<<1,rs=i<<1|1,md=(l+r)>>1;
	if(tg[i]!=-1){
		mx[ls]=tg[ls]=tg[i],sm[ls]=(ll)(ally[tg[i]]+1)*(ally[md+1]-ally[l])%M;
		mx[rs]=tg[rs]=tg[i],sm[rs]=(ll)(ally[tg[i]]+1)*(ally[r+1]-ally[md+1])%M;
		tg[i]=-1;
	}
	if(mx[ls]>w)return qry(ls,l,md,w);
	return qry(rs,md+1,r,w);
}
void upd(int i,int l,int r,int a,int b,int w){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		mx[i]=tg[i]=w;
		sm[i]=(ll)(ally[tg[i]]+1)*(ally[r+1]-ally[l])%M;
		return;
	}
	int ls=i<<1,rs=i<<1|1,md=(l+r)>>1;
	if(tg[i]!=-1){
		mx[ls]=tg[ls]=tg[i],sm[ls]=(ll)(ally[tg[i]]+1)*(ally[md+1]-ally[l])%M;
		mx[rs]=tg[rs]=tg[i],sm[rs]=(ll)(ally[tg[i]]+1)*(ally[r+1]-ally[md+1])%M;
		tg[i]=-1;
	}
	upd(ls,l,md,a,b,w),upd(rs,md+1,r,a,b,w);
	mx[i]=mx[rs];
	sm[i]=(sm[ls]+sm[rs])%M;
}
bool cmp(node A,node B){
	return A.y<B.y;
}
int main(){
	scanf("%d%d%d",&n,&m,&L);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].col);
		allx.push_back(a[i].x),ally.push_back(a[i].y);
	}
	allx.push_back(-1),ally.push_back(-1);
	allx.push_back(L),ally.push_back(L);
	sort(allx.begin(),allx.end()),allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end()),ally.erase(unique(ally.begin(),ally.end()),ally.end());
	nx=allx.size()-2,ny=ally.size()-2;
	for(int i=1;i<=n;i++){
		a[i].x=lower_bound(allx.begin(),allx.end(),a[i].x)-allx.begin();
		a[i].y=lower_bound(ally.begin(),ally.end(),a[i].y)-ally.begin();
		info[a[i].x].push_back(a[i]);
	}
	for(int i=1;i<=nx;i++)sort(info[i].begin(),info[i].end(),cmp);
	for(int i=1;i<=m;i++)mst[i].insert(0),mst[i].insert(ny+1);
	for(int i=1;i<=nx;i++){
		vec.clear();
		for(int j=i;j<=nx;j++)
			for(auto it:info[j])
				vec.push_back({it.y,it.col});
		memset(lst,0,sizeof(lst)),ST.clear();
		for(int j=1;j<=m;j++)ST.insert({0,j});
		sort(vec.begin(),vec.end());
		int it=0;
		for(int j=1;j<=ny;j++){
			while(it<vec.size()&&vec[it].fi==j){
				int id=vec[it].se;
				ST.erase({lst[id],id});
				lst[id]=j,it++,ST.insert({j,id});
				mst[id].insert(j);
			}
			D[j]=(*ST.begin()).fi;
		}
		built(1,1,ny);
		for(int j=nx;j>=i;j--){
			(ans+=(ll)sm[1]*(allx[i]-allx[i-1])%M*(allx[j+1]-allx[j])%M)%=M;
			for(auto T:info[j]){
				int Y=T.y,C=T.col;
				auto it=mst[C].lower_bound(Y);
				int pre=*prev(it),nxt=*next(it);
				int pos=qry(1,1,ny,pre);
				mst[C].erase(it);
				if(pos<0||pos>=nxt)continue;
				upd(1,1,ny,pos,nxt-1,pre);
			}
		}
	}
	printf("%d",ans);
}