#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int N = 1e7 + 1;

bool prime[N];

int main()
{
   for (int i=2; i<N; ++i)
      prime[i] = 1;
   for (int i=2; i<N; ++i)
      if (prime[i] && 1LL*i*i < N)
         for (int j=i*i; j<N; j += i)
            prime[j] = false;
   
   int n;
   cin >> n;
   for (int i=2; n; ++i)
      if (prime[i])
      {
         cout << i << " ";
         --n;
      }
   cout << endl;
   return 0;
}