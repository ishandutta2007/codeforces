#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
const int M=998244353;
const int G=3,Gi=332748118;
int n_,lg,rev[263000],A[263000],B[263000];
int mypow(int x,int t){int ans=1;for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;return ans;}
void ntt(int *A,int typ){
	for(int i=0;i<n_;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
	for(int i=0;i<lg;i++){
		int mid=(1<<i),Wn=mypow(typ==1?G:Gi,(M-1)/(mid<<1));
		for(int j=0;j<n_;j+=(mid<<1)){
        	int w=1;
        	for(int k=0;k<mid;k++,w=(ll)w*Wn%M){
				int x=A[j+k],y=(ll)w*A[j+mid+k]%M;
				A[j+k]=(x+y)%M,A[j+mid+k]=(x-y+M)%M;
			}
		}
    }
	if(typ<0){int inv=mypow(n_,M-2);for(int i=0;i<n_;i++)A[i]=(ll)A[i]*inv%M;}
}
vector<int>mul(vector<int>a,vector<int>b){
	int n=a.size()-1,m=b.size()-1;n_=1,lg=0;while(n_<=n+m)n_<<=1,lg++;
	for(int i=1;i<n_;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<n_;i++){A[i]=B[i]=0;if(i<=n)A[i]=a[i];if(i<=m)B[i]=b[i];}
	ntt(A,1),ntt(B,1);for(int i=0;i<n_;i++)A[i]=(ll)A[i]*B[i]%M;
	ntt(A,-1);vector<int>ans;for(int i=0;i<=n+m;i++)ans.push_back(A[i]);
	return ans;
}
int n,K,fc[100004],inv[100004],ans;
vector<int>a,b;
int main(){
	fc[0]=1;for(int i=1;i<100004;i++)fc[i]=(ll)fc[i-1]*i%M;
	inv[100003]=mypow(fc[100003],M-2);for(int i=100003;i;i--)inv[i-1]=(ll)inv[i]*i%M;
	scanf("%d%d",&n,&K);
	for(int i=0;i<=K;i++){
		a.push_back((ll)inv[i]*mypow(i,K)%M);
		b.push_back((ll)(i&1?M-1:1)*inv[i]%M);
	}
	vector<int>S=mul(a,b);
	int FC=1;
	for(int i=0;i<=min(n,K);i++){
		if(i>0)FC=(ll)FC*(n-i+1)%M;
		(ans+=(ll)FC*inv[i]%M*S[i]%M*fc[i]%M*mypow(n+1,n-i)%M)%=M;
	}
	printf("%d",ans);
}