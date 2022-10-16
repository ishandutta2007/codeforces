#include <iostream>
using namespace std;
long long sum[100001],arr[100001],mx=0;

int main()
{
  int n,p,i;
  cin>>n>>p;
  for (i=1;i<=n;i++){
    cin>>arr[i];
    sum[i]=arr[i];
    sum[i]+=sum[i-1];
  }
  for (i=1;i<n;i++){
    mx=max(mx,(sum[i]%p)+(sum[n]-sum[i])%p);
  }
  cout<<mx<<endl;
  return 0;
}