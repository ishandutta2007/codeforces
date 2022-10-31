#include<bits/stdc++.h>
#define int long long
const int N=200005,P=32;
using namespace std;

int n,m,k,mx;
int a[N];

struct node{
	vector<int> a;
	node(){a.resize(P);}
	node operator +(node b){
		node ans;
		for(int i=0;i<1<<m;i++)
			ans.a[i]=a[b.a[i]];
		return ans;
	}
	void print(){for(int i=0;i<=mx;i++)cout<<a[i]<<endl;} 
}A,B,I;
void init(){
	mx=(1<<m)-1;
	for(int i=0;i<=mx;i++){
		A.a[i]=(i<<1|(i!=mx))&mx;
		B.a[i]=(i<<1|1)&mx;
		I.a[i]=i;
	}
}

struct sgt{
    #define ls k<<1
    #define rs k<<1|1
    #define mid ((l+r)>>1)
    node s1[N<<2],s2[N<<2];bool tg[N<<2];
    void pshtg(int k){
    	swap(s1[k],s2[k]);tg[k]^=1;
    }
    void pshdn(int k){
    	if(tg[k])pshtg(ls),pshtg(rs),tg[k]=0;
    }
    void pshup(int k){
        s1[k]=s1[ls]+s1[rs];
        s2[k]=s2[ls]+s2[rs];
    }
    void build(int k,int l,int r){
    	if(l^r)build(ls,l,mid),build(rs,mid+1,r),pshup(k);
    	else {
    		s1[k]=B,s2[k]=A;if(a[l]&1)swap(s1[k],s2[k]);
		}
	}
    void rev(int k,int l,int r,int x,int y){
        if(y<l||x>r)return ;
        if(y>=r&&x<=l)return pshtg(k);
        pshdn(k);
        rev(ls,l,mid,x,y),rev(rs,mid+1,r,x,y);
        pshup(k);
    }
    auto qry(int k,int l,int r,int x,int y){
        if(y<l||x>r)return I;
        if(y>=r&&x<=l)return s1[k];
        pshdn(k);
        return qry(ls,l,mid,x,y)+qry(rs,mid+1,r,x,y);
    }
    bool get(int k,int l,int r,int x){
    	if(l^r){
    		pshdn(k);
    		if(x<=mid)return get(ls,l,mid,x);
    		else return get(rs,mid+1,r,x);
		}else return (tg[k]^a[l])&1;
	}
}T;

void solve(){
	cin>>n>>m>>k;
	init();
//	A.print();
//	B.print();
//	I.print();
//	A.print();
//	(A+A+A).print();
	for(int i=1;i<=n;i++)cin>>a[i];
	T.build(1,1,n);
//	T.s1[2].print();
	for(int i=1;i<=k;i++){
		int x,y,z,w;
		cin>>x;
		if(x==1){
			cin>>y>>z>>w;
			if(w&1)T.rev(1,1,n,y,z);
		}else{
			cin>>y>>z;
			auto nw=T.qry(1,1,n,y,z-1);
			int p=T.get(1,1,n,z);
		//	nw.print();
			cout<<2-((nw.a[mx-p]&1))<<'\n';
		}
	}
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}