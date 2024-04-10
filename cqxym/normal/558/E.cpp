#include<stdio.h>
#define R register int
#define I inline
const int N=500000;
char S[100001];
struct SegmentTree{
	int l[N],r[N],lazy[N],sum[N];
	I void Build(int p,int lf,int rt){
		l[p]=lf;
		r[p]=rt;
		if(lf!=rt){
			Build(p<<1,lf,lf+rt>>1);
			Build(p<<1|1,lf+rt+2>>1,rt);
		}
	}
	I void PutDown(int p){
		if(lazy[p]==2){
			sum[p]=0;
		}else if(lazy[p]==1){
			sum[p]=r[p]-l[p]+1;
		}else{
			return;
		}
		if(l[p]!=r[p]){
			lazy[p<<1]=lazy[p<<1|1]=lazy[p];
		}
		lazy[p]=0;
	}
	I int GetSum(int p,int &lf,int &rt){
		PutDown(p);
		if(l[p]>=lf&&r[p]<=rt){
			return sum[p];
		}
		int mid=l[p]+r[p]>>1,q=0;
		if(lf<=mid){
			q=GetSum(p<<1,lf,rt);
		}
		if(rt>mid){
			q+=GetSum(p<<1|1,lf,rt); 
		}
		return q;
	}
	I void Modify(int p,int lf,int rt,short d){
		PutDown(p);
		if(l[p]>=lf&&r[p]<=rt){
			lazy[p]=d;
			return;
		}
		int mid=l[p]+r[p]>>1;
		if(lf<=mid){
			Modify(p<<1,lf,rt,d);
		}
		if(rt>mid){
			Modify(p<<1|1,lf,rt,d);
		}
		PutDown(p<<1);
		PutDown(p<<1|1);
		sum[p]=sum[p<<1]+sum[p<<1|1];
	}
	I void GetAns(int p,char d){
		PutDown(p);
		if(l[p]!=r[p]){
			GetAns(p<<1,d);
			GetAns(p<<1|1,d);
		}else{
			if(sum[p]==1){
				S[r[p]]=d;
			}
		}
	}
}T[26];
int main(){
	int n,q,x,y,k,tem[26];
	scanf("%d%d\n",&n,&q);
	char c;
	for(R i=0;i!=26;i++){
		T[i].Build(1,1,n);
	}
	for(R i=1;i<=n;i++){
		c=getchar();
		T[c-'a'].Modify(1,i,i,1);
	}
	for(R i=0;i!=q;i++){
		scanf("%d%d%d",&x,&y,&k);
		for(R j=0;j!=26;j++){
			tem[j]=T[j].GetSum(1,x,y);
			T[j].Modify(1,x,y,2);
		}
		if(k==1){
			k=x;
			for(R j=0;j!=26;j++){
				if(tem[j]!=0){
					T[j].Modify(1,k,k+tem[j]-1,1);
				}
				k+=tem[j];
			}
		}else{
			k=y;
			for(R j=0;j!=26;j++){
				if(tem[j]!=0){
					T[j].Modify(1,k-tem[j]+1,k,1);
				}
				k-=tem[j];
			}
		}
	}
	for(R i=0;i!=26;i++){
		T[i].GetAns(1,'a'+i);
	}
	for(R i=1;i<=n;i++){
		printf("%c",S[i]);
	}
	return 0;
}