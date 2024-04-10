#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,N=2e5+5;
int fc[N],inv[N];
int mypow(int x,int t){
    int ans=1,res=x;
    for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
    return ans;
}
int C(int a,int b){
    return (b<0||a<b)?0:(ll)fc[a]*inv[b]%M*inv[a-b]%M;
}
int p2[200005];
void init(){
    fc[0]=1;
    for(int i=1;i<N;i++)fc[i]=(ll)fc[i-1]*i%M;
    inv[N-1]=mypow(fc[N-1],M-2);
    for(int i=N-1;i;i--)inv[i-1]=(ll)inv[i]*i%M;
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=(ll)p2[i-1]*2%M;
}
int t,n,a[200005],num[33];
int main(){
	memset(num,0,sizeof(num));
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int cnt=0;
		while(a[i]%2==0)a[i]/=2,cnt++;
		num[cnt]++;
	}
	int ans=(ll)(p2[num[0]]-1)*p2[n-num[0]]%M;
	int s=0;
	for(int i=32;i;i--){
		for(int j=2;j<=num[i];j+=2)(ans+=(ll)C(num[i],j)*p2[s]%M)%=M;
		s+=num[i];
	}
	printf("%d\n",ans);
}