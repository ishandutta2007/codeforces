#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int F_I=10000,N=100000,LOG_N=17;
int n,m;
int root[F_I+1],lson[4*N*LOG_N],rson[4*N*LOG_N],sum[4*N*LOG_N],sz = 1;
int nwnd(){return lson[sz+1]=rson[sz+1]=sum[sz+1]=0,++sz;}
void sprup(int p){sum[p]=(lson[p]?sum[lson[p]]:0)+(rson[p]?sum[rson[p]]:0);}
void add(int p,int tl,int tr,int x){
	if(tl==tr){sum[p]++;return;}
	int mid=tl+tr>>1;
	if(x<=mid){
		if(!lson[p])lson[p]=nwnd();
		add(lson[p],tl,mid,x);
	}
	else{
		if(!rson[p])rson[p]=nwnd();
		add(rson[p],mid+1,tr,x);
	}
	sprup(p);
}
int qry(int p,int tl,int tr,int l,int r){
	if(l<=tl&&tr<=r)return sum[p];
	int mid=tl+tr>>1,res=0;
	if(l<=mid&&lson[p])res+=qry(lson[p],tl,mid,l,r);
	if(r>mid&&rson[p])res+=qry(rson[p],mid+1,tr,l,r);
	return res;
}
struct object{int x,r,f;}obj[N];
bool operator<(object x,object y){return x.r>y.r;}
signed main(){
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&obj[i].x,&obj[i].r,&obj[i].f);
		mx=max(mx,obj[i].x);
		root[obj[i].f]=nwnd();
	}
	sort(obj+1,obj+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=obj[i].f-m;j<=obj[i].f+m;j++)if(1<=j&&j<=F_I&&root[j])
			ans+=qry(root[j],1,mx,obj[i].x-obj[i].r,obj[i].x+obj[i].r);
		add(root[obj[i].f],1,mx,obj[i].x);
	}
	cout<<ans;
	return 0;
}