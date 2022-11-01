#include<iostream>
using namespace std;
#define C const int
#define I inline
#define INF 9999999
I int Min(int x,int y){
	return x<y?x:y;
}
struct SegmentNode{
	int MinF,Lazy;
}t[500000];
int a[100001];
I void Init(int p,int lf,int rt){
	if(lf==rt){
		if(lf!=0){
			t[p].MinF=INF;
		}
	}else{
		int mid=lf+rt>>1;
		Init(p<<1,lf,mid);
		Init(p<<1|1,mid+1,rt);
	}
}
I void PutDown(int p,bool tag){
	t[p].MinF+=t[p].Lazy;
	if(tag==true){
		t[p<<1].Lazy+=t[p].Lazy;
		t[p<<1|1].Lazy+=t[p].Lazy;
	}
	t[p].Lazy=0;
}
I int GetMin(int p,int lf,int rt,C l,C r){
	PutDown(p,lf!=rt);
	if(l<=lf&&rt<=r){
		return t[p].MinF;
	}
	int mid=lf+rt>>1,q=INF;
	if(l<=mid){
		q=GetMin(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		q=Min(q,GetMin(p<<1|1,mid+1,rt,l,r));
	}
	return q;
}
I void AddF(int p,int lf,int rt,C l,C r){
	if(l<=lf&&rt<=r){
		t[p].Lazy++;
		return;
	}
	int mid=lf+rt>>1;
	if(l<=mid){
		AddF(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		AddF(p<<1|1,mid+1,rt,l,r);
	}
	PutDown(p<<1,lf!=mid);
	PutDown(p<<1|1,mid+1!=rt);
	t[p].MinF=Min(t[p<<1].MinF,t[p<<1|1].MinF);
}
I void Modify(int p,int lf,int rt,C x,C f){
	PutDown(p,lf!=rt);
	if(lf==rt){
		t[p].MinF=Min(t[p].MinF,f);
		return;
	}
	int mid=lf+rt>>1;
	if(x>mid){
		Modify(p<<1|1,mid+1,rt,x,f);
	}else{
		Modify(p<<1,lf,mid,x,f);
	}
	PutDown(p<<1,lf!=mid);
	PutDown(p<<1|1,mid+1!=rt);
	t[p].MinF=Min(t[p<<1].MinF,t[p<<1|1].MinF);
}
int main(){
	int n;
	cin>>n;
	n++;
	Init(1,0,n);
	for(register int i=1;i!=n;i++){
		cin>>a[i];
		int f=Min(Min(GetMin(1,0,n,0,a[i]-1),GetMin(1,0,n,a[i]+1,n))+1,GetMin(1,0,n,a[i],a[i]));
		if(a[i]!=a[i-1]){
			AddF(1,0,n,0,n-1);
		}
		Modify(1,0,n,a[i-1],f);
	}
	printf("%d",GetMin(1,0,n,0,n-1));
	return 0;
}