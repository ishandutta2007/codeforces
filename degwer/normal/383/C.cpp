#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
class BIT
{
public:
  int bit[SIZE+1];
  void add(int a,int b)
  {
    for(;;)
      {
	if(a>SIZE)
	  {
	    break;
	  }
	bit[a]+=b;
	a+=a&-a;
      }
  }
  int sum(int a)
  {
    int ret=0;
    for(;;)
      {
	if(a==0)
	  {
	    return ret;
	  }
	ret+=bit[a];
	a-=a&-a;
      }
  }
};
BIT bi;
vector<int>pat[200000];
int depth[200000];
int toseg[200000];
vector<int>eul;
int las[200000];
bool flag[200000];
void dfs(int node,int d)
{
  if(flag[node])
    {
      return;
    }
  flag[node]=true;
  toseg[node]=eul.size();
  eul.push_back(node);
  depth[node]=d;
  for(int i=0;i<pat[node].size();i++)
    {
      dfs(pat[node][i],d+1);
    }
  las[node]=eul.size()-1;
}
int main()
{
  int num,query;
  scanf("%d%d",&num,&query);
  vector<int>vec;
  for(int i=0;i<num;i++)
    {
      int zan;
      scanf("%d",&zan);
      vec.push_back(zan);
    }
  for(int i=0;i<num-1;i++)
    {
      int za,zb;
      scanf("%d%d",&za,&zb);
      za--;
      zb--;
      pat[za].push_back(zb);
      pat[zb].push_back(za);
    }
  fill(flag,flag+num,false);
  dfs(0,0);
  for(int i=0;i<num;i++)
    {
      if(depth[i]%2==0)
	{
	  bi.add(toseg[i]+1,vec[i]);
	  bi.add(toseg[i]+2,-vec[i]);
	}
      else
	{
	  bi.add(toseg[i]+1,-vec[i]);
	  bi.add(toseg[i]+2,vec[i]);
	}
    }
  for(int i=0;i<query;i++)
    {
      int zan;
      scanf("%d",&zan);
      if(zan==1)
	{
	  int za,zb;
	  scanf("%d%d",&za,&zb);
	  za--;
	  if(depth[za]%2==0)
	    {
	      bi.add(toseg[za]+1,zb);
	      bi.add(las[za]+2,-zb);
	    }
	  else
	    {
	      bi.add(toseg[za]+1,-zb);
	      bi.add(las[za]+2,zb);
	    }
	}
      else
	{
	  int za;
	  scanf("%d",&za);
	  za--;
	  if(depth[za]%2==0)
	    {
	      printf("%d\n",bi.sum(toseg[za]+1));
	    }
	  else
	    {
	      printf("%d\n",-bi.sum(toseg[za]+1));
	    }
	}
    }
}