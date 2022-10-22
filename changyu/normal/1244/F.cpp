#include<cstdio>
#include<algorithm>
const int N=2e5+3;
int n,m,l[N+N+N],r[N+N+N],k;char a[N+N+N],b[N];
int main(){
	int p,q;
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1;i<=n;i++)a[i+n]=a[i+n+n]=a[i];
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++)
	  if(a[i+n]==a[i+n-1])goto Brk;
	for(int i=1+(m&1);i<=n+(m&1);i++)putchar(a[i]);
	return 0;
	Brk:;
	k=0;
	for(int i=1;i<=n*3;i++)
	  if(a[i]==a[i-1]&&a[i]!=a[i+1])r[++k]=i;
	k=0;
	for(int i=1;i<=n*3;i++)
	  if(a[i]!=a[i-1]&&a[i]==a[i+1])l[++k]=i;
	for(int i=1+n;i<=n*2;i++)if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
	  q=l[std::lower_bound(l+1,l+1+k,i)-l];
	  p=r[std::lower_bound(r+1,r+1+k,i)-r-1];
	  if(q-i>m&&i-p>m)b[i-n]=a[i+(m&1)];
	  else if(q-i<i-p)b[i-n]=a[q];
	  else b[i-n]=a[p];
	}for(int i=1;i<=n;i++)putchar(b[i]);
	return 0;
}