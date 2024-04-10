#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353,G=3,Gi=332748118;
int A[524300],B[524300];
int rev[524300],lg,n_;
int mypow(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%MOD)if(t&1)ans=(ll)ans*x%MOD;
	return ans;
}
void ntt(int *A,int typ){
	for(int i=0;i<n_;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for (int i=0;i<lg;i++){
		int mid=(1<<i);
		int Wn=mypow(typ==1?G:Gi,(MOD-1)/(mid<<1));
		for(int j=0;j<n_;j+=(mid<<1)){
        	int w=1;
        	for(int k=0;k<mid;k++,w=(ll)w*Wn%MOD){
        		int x=A[j+k],y=(ll)w*A[j+mid+k]%MOD;
        		A[j+k]=(x+y)%MOD,A[j+mid+k]=(x-y+MOD)%MOD;
			}
		}
    }
    if(typ<0){
		int inv=mypow(n_,MOD-2);
		for(int i=0;i<n_;i++)A[i]=(ll)A[i]*inv%MOD;
	}
}
vector<int>getmul(vector<int>a,vector<int>b){
	int n=a.size()-1,m=b.size()-1;
	n_=1,lg=0;
	while(n_<=n+m)n_<<=1,lg++;
	for(int i=1;i<n_;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<n_;i++){
		A[i]=B[i]=0;
		if(i<=n)A[i]=a[i];
		if(i<=m)B[i]=b[i];
	}
	ntt(A,1),ntt(B,1);
	for(int i=0;i<n_;i++)A[i]=(ll)A[i]*B[i]%MOD;
	ntt(A,-1);
	vector<int>ans;
	for(int i=0;i<=n+m;i++)ans.push_back(A[i]);
	return ans;
}
int n,S;
int dp[200004],ans[200004];
int fc[200004],iv[200004];
int main(){
	scanf("%d",&n),S=(n+1)/2;
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=(ll)fc[i-1]*i%MOD;
	iv[n]=mypow(fc[n],MOD-2);for(int i=n;i;i--)iv[i-1]=(ll)iv[i]*i%MOD;
	dp[1]=fc[n-1];
	vector<int>a,b;
	for(int i=0;i<=n;i++){
		if(i<=S-2)a.push_back(fc[i]);
		else a.push_back(0);
		if(i<=n-S-1)b.push_back(iv[i]);
		else b.push_back(0);
	}
	reverse(b.begin(),b.end());
	vector<int>mul=getmul(a,b);
	for(int i=2;i<=S;i++)dp[i]=(ll)mul[n+i-2]*fc[n-i]%MOD*(i-1)%MOD;
	int suf=0;
	for(int i=n;i;i--){
		ans[i]=(dp[i]-(ll)suf*mypow(i,MOD-2)%MOD+MOD)%MOD;
		(suf+=ans[i])%=MOD;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}