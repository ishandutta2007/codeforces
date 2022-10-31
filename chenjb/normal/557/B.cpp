#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double ans;
int n,w;
int a[300000];
int main()
{
  scanf("%d%d",&n,&w);
  for(int i=1;i<=2*n;i++)
    scanf("%d",&a[i]);
  sort(a+1,a+2*n+1);
  int tmp=min(2*a[1],a[n+1]);
  ans=min(double(1.5)*tmp*n,double(w));
  printf("%.2f\n",ans);
  return 0;
}