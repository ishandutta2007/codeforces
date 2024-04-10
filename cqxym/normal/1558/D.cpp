#include<iostream>
#include<set>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 400000
#define P 998244353
I int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int opt[N][2],fac[N],invf[N];
struct SegmentNode{
	int Sum,lazy;
}t[800000];
const int Lim=200002;
I void PutDown(int p,int len){
	if(t[p].lazy!=0){
		if(t[p].lazy==1){
			t[p].Sum=0;
		}else{
			t[p].Sum=len;
		}
		if(len!=1){
			t[p<<1].lazy=t[p<<1|1].lazy=t[p].lazy;
		}
		t[p].lazy=0;
	}
}
I void Cover(int p,int lf,int rt,const int l,const int r,const int d){
	if(l<=lf&&rt<=r){
		t[p].lazy=d;
	}else{
		PutDown(p,rt-lf+1);
		int mid=lf+rt>>1;
		if(l<=mid){
			Cover(p<<1,lf,mid,l,r,d);
		}
		if(r>mid){
			Cover(p<<1|1,mid+1,rt,l,r,d);
		}
		PutDown(p<<1,mid-lf+1);
		PutDown(p<<1|1,rt-mid);
		t[p].Sum=t[p<<1].Sum+t[p<<1|1].Sum;
	}
}
I void Modify(int p,int lf,int rt,const int x){
	PutDown(p,rt-lf+1);
	if(lf==rt){
		t[p].Sum=0;
	}else{
		int mid=lf+rt>>1;
		if(x>mid){
			Modify(p<<1|1,mid+1,rt,x);
		}else{
			Modify(p<<1,lf,mid,x);
		}
		PutDown(p<<1,mid-lf+1);
		PutDown(p<<1|1,rt-mid);
		t[p].Sum=t[p<<1].Sum+t[p<<1|1].Sum;
	}
}
I int Find(int p,int lf,int rt,int x){
	//printf("L%d %d %d %d %d\n",p,lf,rt,t[p].Sum,t[p].lazy);
	PutDown(p,rt-lf+1);
	if(lf==rt){
		return lf;
	}
	int mid=lf+rt>>1;
	PutDown(p<<1,mid-lf+1);
	if(x>t[p<<1].Sum){
		return Find(p<<1|1,mid+1,rt,x-t[p<<1].Sum);
	}
	return Find(p<<1,lf,mid,x);
}
I void Clear(int x){
	int pos=Find(1,1,Lim,x);
	Cover(1,1,Lim,pos+1,Lim,1);
}
I int GetC(int n,int m){
	return(L)fac[n]*invf[m]%P*invf[n-m]%P;
}
I void Solve(){
	int n,m,Last;
	cin>>n>>m;
	Last=n;
	Cover(1,1,Lim,1,Lim,1);
	Cover(1,1,Lim,1,n,2);
	set<int>S;
	for(R i=1;i<=m;i++){
		cin>>opt[i][0]>>opt[i][1];
	}
	for(R i=m;i!=0;i--){
		if(opt[i][0]!=Last){
			Clear(opt[i][0]);
		}
		int x=Find(1,1,Lim,opt[i][1]);
		//printf("I%d %d\n",i,x);
		Modify(1,1,Lim,x);
		x=Find(1,1,Lim,opt[i][1]);
		//printf("P%d\n",x);
		S.insert(x);
		Last=opt[i][0]-1;
	}
	cout<<GetC((n<<1)-S.size()-1,n)<<endl;
}
int main(){
	fac[0]=1;
	for(R i=1;i!=N;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invf[N-1]=GetInv(fac[N-1]);
	for(R i=N-1;i!=0;i--){
		invf[i-1]=(L)invf[i]*i%P;
	}
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}