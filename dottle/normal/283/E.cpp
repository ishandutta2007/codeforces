#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

struct sgt{
	#define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    int s1[N<<2],s0[N<<2],tg[N<<2];
    void pshtg(int k){
    	tg[k]^=1;
    	swap(s1[k],s0[k]);
    }
    void pshdn(int k){
    	if(tg[k])pshtg(ls),pshtg(rs),tg[k]^=1; 
    }
    void pshup(int k){
        s1[k]=s1[ls]+s1[rs];
        s0[k]=s0[ls]+s0[rs];
    }
    void build(int k,int l,int r){
    	if(l^r)build(ls,l,mid),build(rs,mid+1,r),pshup(k);
    	else s0[k]=1;
	}
    void cg(int k,int l,int r,int x,int y){
        if(y<l||x>r)return ;
        if(y>=r&&x<=l)return pshtg(k);
        pshdn(k);
        cg(ls,l,mid,x,y),cg(rs,mid+1,r,x,y);
        pshup(k);
    }
    void set(int k,int l,int r,int x,int p){
    	if(l^r){
    		pshdn(k);
    		if(x<=mid)set(ls,l,mid,x,p);
    		else set(rs,mid+1,r,x,p);
    		pshup(k);
		}else s1[k]=!tg[k],s0[k]=tg[k];
	}
	int qry(int k,int l,int r,int x,int p){
		if(l^r){
    		pshdn(k);
    		if(x<=mid)return qry(ls,l,mid,x,p);
    		else return qry(rs,mid+1,r,x,p);
		}else return s1[k];
	} 
}T;

vector<int> l[N],r[N];
int n,q,s[N],b[N];

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i],b[i]=s[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int X=lower_bound(b+1,b+1+n,x)-b;
		int Y=upper_bound(b+1,b+1+n,y)-b-1;
		l[X].push_back(Y),r[Y].push_back(X);
	}
	int res=0;
	T.build(1,1,n); 
	for(int i=1;i<=n;i++){
		for(auto x:l[i])
			T.cg(1,1,n,i,x);
		if(i-1)T.set(1,1,n,i-1,1);
		int k=T.s1[1]-T.qry(1,1,n,i,i);
		res=res+k*(k-1)/2;
		for(auto x:r[i])
			T.cg(1,1,n,x,i);
	} 
	cout<<n*(n-1)*(n-2)/6-res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}