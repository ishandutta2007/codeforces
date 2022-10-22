#include<cstdio>
int n,a[100001],w[100001],h[100001],f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",w+i,h+i);
	a[1]=w[1]>h[1]?w[1]:h[1];
	for(int i=2;i<=n;i++){
	  f=0;
	  if(w[i]<=a[i-1])a[i]=w[i],f=1;
	  if(h[i]<=a[i-1]){if(h[i]>w[i]||!f)a[i]=h[i];f=1;}
	  if(!f)return 0*puts("NO");
	}
	return 0*puts("YES");
}