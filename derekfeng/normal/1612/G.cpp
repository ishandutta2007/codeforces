#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,N=1e6+10,iv=5e8+4;
int n,fc[1000005],f[N*2+10];
int ans1,ans2=1,sum;
int main(){
	fc[0]=1;for(int i=1;i<1e6+5;i++)fc[i]=(ll)fc[i-1]*i%M;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		f[N+1-x]++,f[N+1+x]--;
	}
	for(int i=2;i<=N*2;i++)f[i]+=f[i-2];
	for(int i=0;i<=N*2;i++){
		int l=(sum+1)%M,r=(sum+f[i])%M;sum=r;
		ans2=(ll)ans2*fc[f[i]]%M;
		ans1=((ll)(l+r)*f[i]%M*iv%M*(i-N)%M+ans1)%M;
	}
	printf("%d %d",ans1,ans2);
}