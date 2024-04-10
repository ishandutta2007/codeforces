#include<cstdio>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  bool flag=0;
  int x;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&x);
    if (x==1)flag=1;
  }
  if (flag)printf("-1");
  else printf("1");
}