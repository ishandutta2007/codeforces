#include<bits/stdc++.h>
#define int long long
const int N=1000005,inf=N;
using namespace std;

int n,a[N],fst[N],mx[N];

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
        if(y<l||x>r)return -inf;
        if(y>=r&&x<=l)return mx[k];
        return max(qry(ls,l,mid,x,y),qry(rs,mid+1,r,x,y));
    }
    void upd(int k,int l,int r,int x,int p){
        if(l^r){
            if(x<=mid)upd(ls,l,mid,x,p);
            else upd(rs,mid+1,r,x,p);
            pshup(k);
        }else mx[k]=max(mx[k],p);
    }
}T;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!fst[a[i]]){mx[i]=max(mx[i],mx[i-1]);T.upd(1,1,n,i,mx[i]-i);fst[a[i]]=i;continue;}
		mx[i]=T.qry(1,1,n,fst[a[i]],i)+i-1;
		mx[i]=max(mx[i],mx[i-1]);
		ans=max(ans,mx[i]);
		T.upd(1,1,n,i,mx[i]-i);
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}