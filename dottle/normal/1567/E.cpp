#include<bits/stdc++.h>
#define int long long
const int N=200050;
using namespace std;

struct node{
    int l,r,L,R,fl,sum,len;
    node operator + (node b){
    	node ans=(node){l,b.r,L,b.R,fl&&b.fl&&(r<=b.l),sum+b.sum,len+b.len};
    	if(r<=b.l){
			ans.sum+=R*b.L;
			if(fl)ans.L=len+b.L;
			if(b.fl)ans.R=b.len+R;
    	}
    	return ans;
	}
};
struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    node s[N<<2];
    void pshup(int k){s[k]=s[ls]+s[rs];}
    node qry(int k,int l,int r,int x,int y){
        if(y>=r&&x<=l)return s[k];
        if(y<=mid)return qry(ls,l,mid,x,y);
        if(x>mid)return qry(rs,mid+1,r,x,y);
        return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
    }
    void chg(int k,int l,int r,int x,int p){
        if(l^r){
            if(x<=mid)chg(ls,l,mid,x,p);
            else chg(rs,mid+1,r,x,p);
            pshup(k);
        }else s[k]=(node){p,p,1,1,1,1,1};
    }
}T;

int n,q;

main(){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1,x;i<=n;i++)cin>>x,T.chg(1,1,n,i,x);
	for(int i=1,x,y,z;i<=q;i++){
		cin>>x>>y>>z;
		if(x==1)T.chg(1,1,n,y,z);
		else cout<<T.qry(1,1,n,y,z).sum<<endl;
	}
}