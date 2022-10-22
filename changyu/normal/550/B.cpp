#include<cstdio>
int n,l,r,m,a[15],ans;
int main(){
	scanf("%d%d%d%d",&n,&l,&r,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0,x,z,c,s;i<(1<<n);i++){
	  z=1e7,x=0,c=0,s=0;
	  for(int k=0;k<n;k++)
		if(i&(1<<k))c++,s+=a[k],x=x>a[k]?x:a[k],z=z<a[k]?z:a[k];
	  if(c>=2&&x-z>=m&&s<=r&&s>=l)ans++;
	}printf("%d",ans);
	return 0;
}