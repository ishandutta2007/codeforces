#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 1500000
int a[300001];
I L Max(L a,L b,L c,L d){
	a=a>c?a:c;
	b=b>d?b:d;
	return a>b?a:b;
}
struct SegmentNode{
	L NP,PN,PP,NN;
	I void Init(int x){
		NN=x;
		PP=-x;
		NP=PN=-1e18;
	}
	I friend SegmentNode operator+(SegmentNode A,SegmentNode B){
		SegmentNode res;
		res.NN=Max(A.NN+B.PN,A.NP+B.NN,A.NN,B.NN);
		res.NP=Max(A.NN+B.PP,A.NP+B.NP,A.NP,B.NP);
		res.PN=Max(A.PN+B.PN,A.PP+B.NN,A.PN,B.PN);
		res.PP=Max(A.PP+B.NP,A.PN+B.PP,A.PP,B.PP);
		return res;
	}
};
class SegmentTree{
	SegmentNode s[N];
	int lazy[N];
	public:
		I void Build(int p,int lf,int rt){
			if(lf==rt){
				s[p].Init(a[rt]);
			}else{
				int mid=lf+rt>>1;
				Build(p<<1,lf,mid);
				Build(p<<1|1,mid+1,rt);
				s[p]=s[p<<1]+s[p<<1|1];
			}
		}
		I void Modify(int p,int lf,int rt,int x){
			if(lf==rt){
				s[p].Init(a[lf]);
			}else{
				int mid=lf+rt>>1;
				if(x>mid){
					Modify(p<<1|1,mid+1,rt,x);
				}else{
					Modify(p<<1,lf,mid,x);
				}
				s[p]=s[p<<1]+s[p<<1|1];
			}
		}
		I L GetAns(){
			return s[1].NP>s[1].NN?s[1].NP:s[1].NN;
		}
}T;
I void Solve(){
	int n,q,x,y;
	scanf("%d%d",&n,&q);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	T.Build(1,1,n);
	printf("%lld\n",T.GetAns());
	for(R i=0;i!=q;i++){
		scanf("%d%d",&x,&y);
		int tem=a[x];
		a[x]=a[y];
		T.Modify(1,1,n,x);
		a[y]=tem;
		T.Modify(1,1,n,y);
		printf("%lld\n",T.GetAns());
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}