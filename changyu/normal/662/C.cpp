#include<cstdio>
typedef long long ll;
const int M=1e9+7,INV2=5e8+4,N=1e5+3,K=20;
int n,m,a[1<<K],b[1<<K],c[1<<K],ans,t;char s[K][N];
inline void Fwt(int*a,int f){
	int tmp0,tmp1;
	for(int k=1;k<(1<<n);k<<=1)
	  for(int i=0;i<(1<<n);i+=k+k)
		for(int j=0;j<k;j++)
		  tmp0=a[i+j]+a[i+k+j],tmp1=(a[i+j]-a[i+k+j]+M)%M,
		  a[i+j]=(ll)tmp0*f%M,a[i+k+j]=(ll)tmp1*f%M;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<m;i++){
	  t=0;
	  for(int j=0;j<n;j++)
		t=t<<1|s[j][i]-'0';
	  ++b[t];
	}
	for(int i=0;i<(1<<n);i++)c[i]=c[i>>1]+(i&1);
	for(int i=0;i<(1<<n);i++)if(n-c[i]<c[i])c[i]=n-c[i];
	Fwt(c,1),Fwt(b,1);
	for(int i=0;i<(1<<n);i++)a[i]=(ll)c[i]*b[i]%M;
	Fwt(a,INV2);
	ans=n*m;
	for(int i=0;i<(1<<n);i++)ans=ans<a[i]?ans:a[i];
	printf("%d\n",ans);
	return 0;
}