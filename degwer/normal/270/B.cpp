#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int num;
  scanf("%d",&num);
  vector<int>vec;
  for(int i=0;i<num;i++)
    {
      int zan;
      scanf("%d",&zan);
      vec.push_back(zan);
    }
  int ans=0,now=1000000000;
  for(int i=num-1;i>=0;i--)
    {
      if(now>vec[i])
	{
	  ans++;
	  now=vec[i];
	}
      else
	{
	  break;
	}
    }
  printf("%d\n",num-ans);
}