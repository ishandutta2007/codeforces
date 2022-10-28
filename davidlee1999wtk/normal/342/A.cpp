#include<cstdio>
#include<iostream>
using namespace std;
int count[10]={0};
int main()
{
  int n;
  int i,t;
  cin>>n;
  for(i=1;i<=n;i++)
  {
    scanf("%d",&t);
    if(t==5||t==7)
    {
      cout<<-1<<endl;
      return 0;
	}
	count[t]++;
  }
  count[1]-=n/3;
  count[2]-=count[4];
  count[6]-=count[3];
  if(count[2]>=0&&count[6]>=0&&count[2]==count[6]&&count[1]==0)
  {
    for(i=1;i<=count[4];i++)
      printf("1 2 4\n");
    for(i=1;i<=count[2];i++)
      printf("1 2 6\n");
    for(i=1;i<=count[3];i++)
      printf("1 3 6\n");
  }
  else
  {
	cout<<-1<<endl;
	return 0;
  }
  return 0;
}