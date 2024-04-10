#include<bits/stdc++.h>
using namespace std;
int maxx[2010];
int main(int argc, char const *argv[]) {
  int n,m,k;
  cin>>n>>m>>k;
  memset(maxx,-1,sizeof(maxx));
  for(int i=0;i<n;i++)
  {
    int r,val;
    cin>>r>>val;
    if(maxx[r]==-1||val<maxx[r])
    {
      maxx[r] = val;
    }
  }
  sort(maxx+1,maxx+m+1);
  int sum = 0;
  for(int i=1;i<=m;i++){
    sum+=maxx[i];
  }
  if(sum > k) sum = k;
  printf("%d\n", sum);
  return 0;
}