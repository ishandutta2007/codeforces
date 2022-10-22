#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=1e6+3,M=1e9+7;
int n,a[N],inv[N],s;
int main(){
	scanf("%d",&n);
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(M-M/i)*(inv[M%i])%M;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+1+n);
	for(int i=1,j=0;i<=n;i++)if(i<n&&a[i]<a[i+1]){
	  s=(s+(ll)a[i]*(i-j)%M*inv[n-j])%M;
	  j=i;
	}
	for(int i=1;i<=n;i++)s=(ll)s*i%M;
	printf("%d\n",s);
	return 0;
}