#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;

int main()
{
  int N;
  cin>>N;
  double Max=0;
  for(int i=0,Sum=0;i<N;i++)
    {
      int X;
      cin>>X;
      Sum+=X;
      Max=max(Max,(double)Sum/(i+1));
    }
  printf("%0.6lf\n",Max);
  return 0;
}