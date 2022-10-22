#include<cstdio>
typedef long long ll;
const int K=20,M=1e9+7;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
inline int Count(int a){int s=0;for(;a;a-=a&-a)s++;return s;}
int n,a,b[1<<K],s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a),b[a]++;
	for(int k=1;k<(1<<K);k<<=1)
	  for(int i=0;i<(1<<K);i+=k+k)
		for(int j=0;j<k;j++)
		  b[i+j]+=b[i+k+j];
	for(int i=0;i<(1<<K);i++)
	  Count(i)&1?s=(s-Pow(2,b[i])+M)%M:s=(s+Pow(2,b[i]))%M;
	printf("%d\n",s);
	return 0;
}