#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
struct ch
{
  int id;
  int h;
};
int n,m;
queue<ch> Q;
int main()
{
  cin>>n>>m;
  ch tmp;
  for(int i=1;i<=n;i++)
  {
    cin>>tmp.h;
    tmp.id=i;
    Q.push(tmp);
  }
  while(Q.size()>1)
  {
    tmp=Q.front();
    Q.pop();
    tmp.h-=m;
    if(tmp.h>0)Q.push(tmp);
  }
  tmp=Q.front();
  cout<<tmp.id;
  return 0;
}