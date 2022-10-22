#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
struct SegmentTree{
	int dat[524300];
	void init(){
		memset(dat,0,sizeof(dat));
	}
	void upd(int l,int r,int id,int p,int x){
		if(l==r)dat[id]=x;
		else{
			int mid=(l+r)>>1;
			if(p<=mid)upd(l,mid,id<<1,p,x);
			else upd(mid+1,r,id<<1|1,p,x);
			dat[id]=max(dat[id<<1],dat[id<<1|1]);
		}
	}
	int qry(int l,int r,int id,int a,int b){
		if(r<a||b<l)return 0;
		if(a<=l&&r<=b)return dat[id];
		int mid=(l+r)>>1;
		return max(qry(l,mid,id<<1,a,b),qry(mid+1,r,id<<1|1,a,b));
	}
}tr1,tr2;
vector<int>all;
int n,m,op[200004],h[200004],p[200004],a[100004],res[100004],N;
set<pii>ans;
set<pii>pos1;
set<int>pos2;
vector<pii>v;
int main(){
	tr1.init(),tr2.init();
	ans.insert(mkp(0,0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&op[i]);
		if(op[i]==1)scanf("%d%d",&p[i],&h[i]),h[i]-=i,all.push_back(h[i]);
		if(op[i]==2)scanf("%d",&p[i]);
	}
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=m;i++)if(op[i]==1)h[i]=lower_bound(all.begin(),all.end(),h[i])-all.begin()+1;N=all.size();
	for(int i=1;i<=m;i++){
		if(op[i]==1){
			a[p[i]]=h[i];
			v.clear();
			while(!pos1.empty()){
				pii tmp=*pos1.begin();
				if(tmp.fi<h[i])v.push_back(tmp),pos1.erase(tmp),tr1.upd(1,n,1,tmp.se,0);
				else break;
			}
			v.push_back(mkp(h[i],p[i]));pos2.insert(p[i]);
			for(int j=v.size()-1;~j;j--){
				pii x=v[j];
				if(x.se!=p[i])ans.erase(mkp(res[x.se],x.se));
				res[x.se]=tr1.qry(1,n,1,x.se+1,n)+1;
				ans.insert(mkp(res[x.se],x.se));
				tr1.upd(1,n,1,x.se,res[x.se]),tr2.upd(1,N,1,x.fi,res[x.se]);
				pos1.insert(mkp(a[x.se],x.se));
			}
		}else{
			v.clear();
			int cnt=0,lst;
			while(!pos2.empty()){
				int tmp=*pos2.begin();
				pos2.erase(tmp);
				v.push_back(mkp(a[tmp],tmp));
				++cnt;
				tr2.upd(1,N,1,a[tmp],0);
				if(cnt==p[i]){
					lst=tmp;
					break;
				}
			}
			pos1.erase(mkp(a[lst],lst)),tr1.upd(1,n,1,lst,0);
			for(int j=v.size()-1;~j;j--){
				pii x=v[j];
				ans.erase(mkp(res[x.se],x.se));
				if(x.se!=lst){
					res[x.se]=tr2.qry(1,N,1,x.fi+1,N)+1;
					ans.insert(mkp(res[x.se],x.se));
					tr1.upd(1,n,1,x.se,res[x.se]),tr2.upd(1,N,1,x.fi,res[x.se]);
					pos2.insert(x.se);
				}
			}
		}
		printf("%d\n",(*ans.rbegin()).fi);
	}
}