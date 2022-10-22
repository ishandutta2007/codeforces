#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
int n,a[100004],f[100004],m,ans;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),a[x]++,m+=x;
	f[0]=0;
	for(int i=1;i<=1e5;i++)f[i]=(f[i-1]+myp(m-i+1,M-2))%M;
	for(int i=1;i<=1e5;i++){
		f[i]=(ll)f[i]*(m-1)%M*(m-i)%M;
		while(a[i]--)(ans+=f[i])%=M;
	}
	printf("%d",ans);
}