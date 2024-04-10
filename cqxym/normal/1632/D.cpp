#include<iostream>
using namespace std;
#define R register int
inline int Min(const int x,const int y){
	return x<y?x:y; 
}
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
int f[18][200001],a[200001],lf[200001],minF[800001];
inline void Modify(int p,int lf,int rt,const int x,const int f){
	if(lf==rt){
		minF[p]=f;
	}else{
		int mid=lf+rt>>1;
		if(x>mid){
			Modify(p<<1|1,mid+1,rt,x,f);
		}else{
			Modify(p<<1,lf,mid,x,f);
		}
		minF[p]=Min(minF[p<<1],minF[p<<1|1]);
	}
}
inline int GetMin(int p,int lf,int rt,const int l,const int r){
	if(l<=lf&&rt<=r){
		return minF[p];
	}
	int mid=lf+rt>>1,res=999999;
	if(l<=mid){
		res=GetMin(p<<1,lf,mid,l,r);
	}
	if(r>mid){
		res=Min(res,GetMin(p<<1|1,mid+1,rt,l,r));
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		f[0][i]=a[i];
	}
	for(R j=1;1<<j<=n;j++){
		for(R k=1<<j;k<=n;k++){
			f[j][k]=Gcd(f[j-1][k],f[j-1][k-(1<<j-1)]);
		}
	}
	for(int i=1;i<=n;i++){
		int pre=0,cur=i;
		for(R j=17;j!=-1;j--){
			if(cur>=1<<j&&Gcd(f[j][cur],pre)>=i-cur+(1<<j)){
				pre=Gcd(f[j][cur],pre);
				cur-=1<<j;
			}
		}
		if(pre==i-cur){
			lf[i]=cur+1;
		}
	}
	for(R i=1;i<=n;i++){
		int f;
		if(lf[i]!=0){
			f=GetMin(1,0,n,lf[i]-1,i-1)+1;
		}else{
			f=GetMin(1,0,n,i-1,i-1);
		}
		Modify(1,0,n,i,f);
		printf("%d ",f);
	}
	return 0;
}