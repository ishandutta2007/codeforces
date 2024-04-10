#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t1,t2,t3,l1,r1,l2,r2,l3,r3,n;
int main()
{
  scanf("%d",&n);
  scanf("%d%d",&l1,&r1);
  scanf("%d%d",&l2,&r2);
  scanf("%d%d",&l3,&r3);
  t1=min(r1,n-l2-l3);
  t2=min(r2,n-t1-l3);
  t3=n-t1-t2;
  printf("%d %d %d\n",t1,t2,t3);
  return 0;
}