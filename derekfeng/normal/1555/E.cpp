#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define fi first
#define se second
#define mkp make_pair
int n,m;
vector<piii>seg;
int lz[2097200],d[2097200];
void upd(int l,int r,int id,int a,int b,int x){
	if(r<=a||b<=l)return;
	if(a<=l&&r<=b){
		lz[id]+=x,d[id]+=x;
		return;
	}
	int mid=(l+r)>>1;
	upd(l,mid,id<<1,a,b,x),upd(mid,r,id<<1|1,a,b,x);
	d[id]=min(d[id<<1],d[id<<1|1])+lz[id];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		int l,r,w;scanf("%d%d%d",&l,&r,&w);
		seg.push_back(mkp(w,mkp(l,r)));
	}
	sort(seg.begin(),seg.end());
	int ans=1e6;
	int l=0,r=0;upd(1,m,1,seg[0].se.fi,seg[0].se.se,1);
	for(int i=0;i<n;i++){
		while(r<i)r++,upd(1,m,1,seg[r].se.fi,seg[r].se.se,1);
		while(l<i){
			upd(1,m,1,seg[l].se.fi,seg[l].se.se,-1);
			if(d[1])l++;
			else{
				upd(1,m,1,seg[l].se.fi,seg[l].se.se,1);
				break;
			}
		}
		if(d[1])ans=min(ans,seg[r].fi-seg[l].fi);
	}
	printf("%d",ans);
}