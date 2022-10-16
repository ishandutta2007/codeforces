#include <iostream>
using namespace std;
int cnt[1001];

int main()
{
  int n,x,y,i;
  cin>>n;
  for (i=1;i<n;i++){
    cin>>x>>y;
    cnt[x]++;
    cnt[y]++;
  }
  int ans=0;
  for (i=1;i<=n;i++){
    if (cnt[i]==1)
      ans++;
  }
  cout<<ans<<endl;
  return 0;
}