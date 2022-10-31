#include<bits/stdc++.h>
#define int long long
const int N=1000005,inf=1e18;
using namespace std;

int n,m,l[N],r[N],k[N];
int a[N],b[N],c[N]; 
int sa[N],sb[N],sc[N];
int s[N],f[N],dp[N];
vector<int> ps[N];

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    int mx[N<<2];
    sgt(){memset(mx,-2,sizeof(mx));}
    void pshup(int k){
        mx[k]=max(mx[ls],mx[rs]);
    }
    int qry(int k,int l,int r,int x,int y){
        if(y<l||x>r)return -1e18;
        if(y>=r&&x<=l)return mx[k];
        return max(qry(ls,l,mid,x,y),qry(rs,mid+1,r,x,y));
    }
    void updt(int k,int l,int r,int x,int p){
        if(l^r){
            if(x<=mid)updt(ls,l,mid,x,p);
            else updt(rs,mid+1,r,x,p);
            pshup(k);
        }else mx[k]=p;
    }
}T;

struct SGT{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    struct node{
    	int mx,md,mf;
    	node operator + (node b){
    		node ans;
    		ans.mx=max({mx,b.mx,md+b.mf});
    		ans.md=max(md,b.md);
    		ans.mf=max(mf,b.mf);
    		return ans;
		}
	}s[N<<2];
    void pshup(int k){
    	s[k]=s[ls]+s[rs]
;    }
    node qry(int k,int l,int r,int x,int y){
        if(y<l||x>r)return {-inf,-inf,-inf};
        if(y>=r&&x<=l)return s[k];
        return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
    }
    void updt(int k,int l,int r,int x){
        if(l^r){
            if(x<=mid)updt(ls,l,mid,x);
            else updt(rs,mid+1,r,x);
            pshup(k);
        }else s[k]={dp[l]+f[l],dp[l],f[l]};
    }
}S;

void solve(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=n;i>=1;i--)sb[i]=sb[i+1]+b[i];
	for(int i=n;i>=1;i--)sc[i]=sc[i+1]+c[i];
	for(int i=1;i<=n;i++)s[i]=sa[i]+sb[i];
	for(int i=1;i<=n;i++)f[i]=sc[i]-sb[i+1];
	for(int i=1;i<=m;i++)cin>>l[i]>>r[i]>>k[i],ps[r[i]].push_back(i);
	for(int i=1;i<=n;i++){
		dp[i]=s[i];
		for(auto x:ps[i-1])
			dp[i]=max(dp[i],T.qry(1,1,n,l[x],i-1)-k[x]);
		T.updt(1,1,n,i,dp[i]); 
	}
	for(int i=1;i<=n;i++)S.updt(1,1,n,i);
	int res=-1e18;
	for(int i=1;i<=m;i++)
		res=max(res,S.qry(1,1,n,l[i],r[i]).mx-k[i]);
	cout<<res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}