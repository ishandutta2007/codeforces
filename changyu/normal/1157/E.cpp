#include<cstdio>
const int N=2e5+1;
int a[N],b,c[N],n;
inline int Sum(int k){int s=0;for(k++;k;k-=k&-k)s+=c[k];return s;}
inline void Add(int k,int a){for(k++;k<=n;k+=k&-k)c[k]+=a;}
inline int Find(int s,int t,int g){
	int l=s,r=t,m;
	for(;l<r;)m=l+r>>1,Sum(m)-g>0?r=m:l=m+1;
	return l;
}
int main(){
	int r,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",&b),c[b+1]++;
	for(int j=1;j<=n;j++)if(j+(j&-j)<=n)c[j+(j&-j)]+=c[j];
	for(int i=1;i<=n;i++)
	  r=Sum(n-a[i]-1),
	  t=n-i+1-r?Find(n-a[i],n-1,r):Find(0,n-a[i]-1,0),
	  Add(t,-1),
	  printf("%d ",(a[i]+t)%n);
	return 0;
}