#include<cstdio>
#define R(i,a,b) for(int i=a;i<=b;i++)
#define N 3000009
char S[N],*s=S,a[N];int c[N],f[N],l[N],r[N],t,m,n;
void M(int k,int x){for(f[k]=x,t--;k<=m;k+=k&-k)c[k]--;}
int A(int x){int s=0,i=1<<22;for(x--;i;i>>=1)if(s+i<=m&&c[s+i]<=x)x-=c[s+=i];return s+1;}
int main(){
scanf("%s%d%d",S+1,&m,&n);R(i,1,n)scanf("%d%d",&l[i],&r[i]);R(i,0,m)c[i]=i&-i;t=m;
for(int i=n;i;i--)for(int j=1,k=l[i]+1;j<=r[i]-l[i]+1&&r[i]<=t;M(A(r[i]+1),A(k)),j++,k+=2)if(k>r[i])k=l[i];
R(i,1,m)putchar(a[i]=(f[i]?a[f[i]]:*(++s)));
}