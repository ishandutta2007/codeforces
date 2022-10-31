#include<bits/stdc++.h>
//#define int long long
const int N=1005005; 
using namespace std;

int a[N],n,l,h,b[N],ans;

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    int s[N<<2],mx[N<<2];
    void pshup(int k){
        s[k]=s[ls]+s[rs];
        mx[k]=max(mx[ls],s[ls]+mx[rs]);
    }
    void upd(int k,int l,int r,int x,int y){
        if(l^r){
            if(x<=mid)upd(ls,l,mid,x,y);
            else upd(rs,mid+1,r,x,y);
            pshup(k);
    	}else s[k]+=y,mx[k]=s[k]; 
    }
}T;

void add(int x,int y){
	int p=upper_bound(b+1,b+1+l,h-x)-b;
	T.upd(1,1,l+1,p,y);
}
void print(){
	ans+=T.mx[1]<=0;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>l>>h;h=-h;
	for(int i=1;i<=l;i++)cin>>b[i],b[i]=-b[i];
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=-a[i];
	sort(b+1,b+1+l);
	for(int i=1;i<=l;i++)T.upd(1,1,l+1,i+1,-1);
	for(int i=1;i<=l;i++)
		add(a[i],1);
	print();
	for(int i=l+1;i<=n;i++){
		add(a[i-l],-1);
		add(a[i],1);
		print();
	}
	cout<<ans;
}