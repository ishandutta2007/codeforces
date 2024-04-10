#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=30005;
int n,t;
int a[maxn],b[maxn];
void init()
{
  scanf("%d%d",&n,&t);
  for(int i=1;i<n;i++)
    scanf("%d",a+i);
}

void work()
{
  b[1]=1;
  for(int i=1;i<n;i++)
    if(b[i])b[i+a[i]]=1;
  if(b[t])puts("YES");
  else puts("NO");
}

int main()
{
  init();
  work();
  return 0;
}