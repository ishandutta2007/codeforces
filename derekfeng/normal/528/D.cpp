#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,G=3,Gi=332748118,INF=0x3f3f3f3f;
int n,m,K,n_=1,lg,rev[534288];
int mypow(int x,int t){
	int ret=1,ans=x;
	while(t){
		if(t&1)ret=1ll*ret*ans%MOD;
		ans=1ll*ans*ans%MOD,t>>=1;
	}
	return ret;
}
void ntt(int *A,int typ){
	for(int i=0;i<n_;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for (int i=0;i<lg;i++){
		int mid=(1<<i);
		int Wn=mypow(typ==1?G:Gi,(MOD-1)/(mid<<1));
		for(int j=0;j<n_;j+=(mid<<1)){
        	int w=1;
        	for(int k=0;k<mid;k++,w=1ll*w*Wn%MOD){
        		int x=A[j+k],y=1ll*w*A[j+mid+k]%MOD;
        		A[j+k]=(x+y)%MOD,A[j+mid+k]=(x-y+MOD)%MOD;
			}
		}
    }
}
bitset<200004>bs;
int A[534288],B[534288];
char a[200004],b[200004];
void sol(char c){
	for(int i=0;i<n_;i++)A[i]=B[i]=0;
	int lst=-INF;
	for(int i=0;i<n;i++){
		if(a[i]==c)lst=i;
		A[i]=(i-lst>K);
	}
	lst=INF;
	for(int i=n-1;i>=0;i--){
		if(a[i]==c)lst=i;
		A[i]&=(lst-i>K);
	}
	for(int i=0;i<m;i++)B[i]=(b[i]==c);
	ntt(A,1),ntt(B,1);
	for(int i=0;i<n_;i++)A[i]=1ll*A[i]*B[i]%MOD;
	ntt(A,-1);
	for(int i=m-1;i<n;i++)if(A[i])bs[i]=0;
}
int main(){
	scanf("%d%d%d%s%s",&n,&m,&K,a,b);
	reverse(b,b+m);
	while(n_<n+m-1)n_<<=1,lg++;
	for(int i=1;i<n_;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=m-1;i<n;i++)bs[i]=1;
	sol('A'),sol('C'),sol('G'),sol('T');
	printf("%d",bs.count());
}