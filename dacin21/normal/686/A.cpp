#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    int N, b=0;
    long long K, a;
    char c;
    cin >> N >> K;
    for(int i=0;i<N;++i){
      cin >> c >> a;
      if(c=='+'){
        K+=a;
      } else {
        if(K>=a){
          K-=a;
        } else {
          ++b;
        }
      }
    }
    cout << K << " " << b << "\n";
    return 0;
}