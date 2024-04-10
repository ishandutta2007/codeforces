#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n,n0=0,n1=0,x,minn=0;
  int arr[101];
  cin>>n;
  int best=-1000;
  for (int i=0;i<n;i++) {
    cin>>x;
    if (x==0) n0++;
    else n1++;
    arr[i]=n0-n1;

    best = max(best, arr[i] - minn);

    if (arr[i]<minn) minn=arr[i];
  }
  cout<< n1 + best <<endl;

  //cout<<maxn<<"   "<<minn<<endl;
}