#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int par[100];
int ran[100];
vector<int>pat[100];
void init()
{
  for(int i=0;i<100;i++)
    {
      par[i]=i;
      ran[i]=0;
    }
}
int find(int a)
{
  if(par[a]==a)
    {
      return a;
    }
  return par[a]=find(par[a]);
}
void unite(int a,int b)
{
  a=find(a);
  b=find(b);
  if(a==b)
    {
      return;
    }
  if(ran[a]>ran[b])
    {
      par[b]=a;
    }
  else
    {
      par[a]=b;
    }
  if(ran[a]==ran[b])
    {
      ran[a]++;
    }
}
int main()
{
  init();
  int num,z;
  scanf("%d%d",&num,&z);
  bool flag=true;
  for(int i=0;i<num;i++)
    {
      int zan;
      scanf("%d",&zan);
      for(int j=0;j<zan;j++)
	{
	  flag=false;
	  int za;
	  scanf("%d",&za);
	  za--;
	  if(!pat[za].empty())
	    {
	      unite(pat[za][pat[za].size()-1],i);
	    }
	  pat[za].push_back(i);
	}
    }
  if(flag)
    {
      printf("%d\n",num);
      return 0;
    }
  int sum=0;
  for(int i=0;i<num;i++)
    {
      if(par[i]==i)
	{
	  sum++;
	}
    }
  printf("%d\n",sum-1);
}