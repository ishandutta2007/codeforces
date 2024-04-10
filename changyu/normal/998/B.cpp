#include<cstdio>
#include<algorithm>
int n,m,a[101],b[101],s,c,k;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
      c+=a[i]&1;
      if(c+c==i&&i<n)b[++k]=a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i];//,printf("%d %d\n",c,i);
    }
    std::sort(b+1,b+k+1);
    c=0;
    //printf("%d\n",k);
    //printf("%d %d\n",b[1],b[2]);
    for(int i=1;i<=k;i++)
      if(s+b[i]<=m)s+=b[i],c++;
    printf("%d",c);
	return 0;
}