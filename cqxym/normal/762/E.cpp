#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
#define N 100000
#define M 10011
struct Station{
	int F,x,r;
	I friend bool operator<(Station x,Station y){
		return x.r>y.r;
	}
}p[N];
struct Node{
	int ordx,ordy,newx,newy,sum;
}A[N],B[N],C[N],D[N];
I bool Com1(Node x,Node y){
	return x.ordx<y.ordx;
}
I bool Com2(Node x,Node y){
	return x.newx<y.newx;
}
int c[M];
stack<int>S;
I void Add(int x){
	S.push(x);
	for(R i=x;i<M;i+=i&-i){
		c[i]++;
	}
}
I int GetSum(int x){
	int s=0;
	for(R i=x;i>0;i-=i&-i){
		s+=c[i];
	}
	return s;
}
I void Clear(){
	while(S.empty()==false){
		int x=S.top();
		S.pop();
		for(R i=x;i<M;i+=i&-i){
			if(c[i]==0){
				break;
			}
			c[i]=0;
		}
	}
}
I void Solve(Node*v,int l,int r){
	if(l!=r){
		int mid=l+r>>1,p1=l,p2;
		p2=mid+1;
		Solve(v,l,mid);
		Solve(v,p2,r);
		sort(v+l,v+p2,Com1);
		sort(v+p2,v+r+1,Com2);
		Clear();
		for(R i=l;i<=r;i++){
			if(p2>r||(p1<=mid&&v[p1].ordx<=v[p2].newx)){
				Add(v[p1].ordy);
				p1++;
			}else{
				v[p2].sum+=GetSum(v[p2].newy);
				p2++;
			}
		}
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(R i=0;i!=n;i++){
		scanf("%d%d%d",&p[i].x,&p[i].r,&p[i].F);
	}
	sort(p,p+n);
	for(R i=0;i!=n;i++){
		A[i].ordx=B[i].ordx=C[i].ordx=D[i].ordx=p[i].x;
		A[i].ordy=B[i].ordy=C[i].ordy=D[i].ordy=p[i].F;
		A[i].newx=B[i].newx=p[i].x+p[i].r;
		C[i].newx=D[i].newx=p[i].x-p[i].r-1;
		A[i].newy=C[i].newy=p[i].F+k;
		B[i].newy=D[i].newy=p[i].F-k-1;
	}
	Solve(A,0,n-1);
	Solve(B,0,n-1);
	Solve(C,0,n-1);
	Solve(D,0,n-1);
	long long ans=0;
	for(R i=0;i!=n;i++){
		ans+=A[i].sum-B[i].sum-C[i].sum+D[i].sum;
	}
	printf("%lld",ans);
	return 0;
}