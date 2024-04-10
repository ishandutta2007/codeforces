/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=200000,M=200000,S=200000;
int n,m,s;
int a[N+1],ca[N+1],b[M+1],cb[M+1],ac[S+1],bc[S+1],cc[S+1];
int orda[N+1],ord[S+1];
bool cmpa(int x,int y){return a[x]<a[y];}
bool cmp(int x,int y){return ac[x]<ac[y];}
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=1;i<=m;i++)b[i]=lower_bound(nums.begin(),nums.end(),b[i])-nums.begin();
	for(int i=1;i<=s;i++)bc[i]=lower_bound(nums.begin(),nums.end(),bc[i])-nums.begin();
}
int mn[M+S];
struct segtree{
	struct node{int l,r,mx,lz;}nd[M+S<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define mx(p) nd[p].mx
	#define lz(p) nd[p].lz
	void sprup(int p){mx(p)=max(mx(p<<1),mx(p<<1|1));}
	void bld(int l=0,int r=nums.size()-1,int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r)return mx(p)=-mn[l],void();
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
		sprup(p);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)){
			mx(p<<1)+=lz(p);lz(p<<1)+=lz(p);
			mx(p<<1|1)+=lz(p);lz(p<<1|1)+=lz(p);
			lz(p)=0;
		}
	}
	void add(int l,int r,int v,int p=1){
		if(l>r)return;
		if(l<=l(p)&&r>=r(p))return mx(p)+=v,lz(p)+=v,void();
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,v,p<<1);
		if(r>mid)add(l,r,v,p<<1|1);
		sprup(p);
	}
	int _mx(){return mx(1);}
}segt;
signed main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)scanf("%lld%lld",a+i,ca+i),orda[i]=i;
	for(int i=1;i<=m;i++)scanf("%lld%lld",b+i,cb+i),nums.pb(b[i]);
	for(int i=1;i<=s;i++)scanf("%lld%lld%lld",ac+i,bc+i,cc+i),nums.pb(bc[i]),ord[i]=i;
	sort(orda+1,orda+n+1,cmpa);sort(ord+1,ord+s+1,cmp);
	discrete();
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=m;i++)mn[b[i]]=min(mn[b[i]],cb[i]);
	for(int i=(int)(nums.size())-2;~i;i--)mn[i]=min(mn[i],mn[i+1]);
	segt.init();
	int now=0,ans=-inf;
	for(int i=1;i<=n;i++){
		int x=orda[i];
		while(now+1<=s&&ac[ord[now+1]]<a[x])now++/*,cout<<ord[now]<<" "*/,segt.add(bc[ord[now]]+1,nums.size()-1,cc[ord[now]]);
		ans=max(ans,segt._mx()-ca[x]);
//		puts("");
//		cout<<ans<<"!\n";
	}
	cout<<ans;
	return 0;
}