#include<cstdio>
inline int min(int a,int b){return a<b?a:b;}
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
const int K=11,A=7500001;
int ans=A,n,np[A]={1,1},np1[A],k,p[1234567],cp[1234567],mnp[1234567],cnp[1234567],d[A],d1[A];
inline void _chai_(int a){
	int t,c,m=0;
	for(;a>1;){
	  t=a<A?d[a]:d1[a-A];c=0;
	  for(;a%p[t]==0;)a/=p[t],c++;
	  cp[t]++;
	  if(c==mnp[t])cnp[t]++;
	  if(c<mnp[t])mnp[t]=c,cnp[t]=1;
	}
}
int main()
{
	int t,mn,c;
	for(int i=2;i<A+A;i++)
	{
	  if(!(i<A?np[i]:np1[i-A]))
		p[k]=i,mnp[k]=A,i<A?d[i]=k++:d1[i-A]=k++;
	  for(int j=0;j<k&&p[j]*i<A+A;j++){
		t=i*p[j];
		t<A?np[t]=1:np1[t-A]=1;
		t<A?d[t]=j:d1[t-A]=j;
		if(i%p[j]==0)break;
	  }
	}
	n=read();
	for(int i=1;i<=n;i++)
	  _chai_(read());
	for(int i=0;i<k;i++)
	  ans=min(ans,n-cp[i]?n-cp[i]:cnp[i]);
	printf("%d",ans==n?-1:ans);
	return 0;
}