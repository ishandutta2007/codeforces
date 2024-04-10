#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,N=4e5;
int n,fc[400005],iv[400005];
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*iv[b]%M*iv[a-b]%M;
}
int main(){
	fc[0]=1;for(int i=1;i<=N;i++)fc[i]=(ll)fc[i-1]*i%M;
	iv[N]=myp(fc[N],M-2);for(int i=N;i;i--)iv[i-1]=(ll)iv[i]*i%M;
	scanf("%d",&n);
	int ans=0;
	for(int i=0,x;i<=n;i++)scanf("%d",&x),(ans+=C(i+x,i+1))%=M;
	printf("%d",ans);
}