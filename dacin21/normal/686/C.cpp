#include <bits/stdc++.h>

using namespace std;

int da=1, db=1;
bool dec(int a, int b){
  bitset<7>did(0);
  for(int i=0;i<da;++i){
    if(did[a%7])return false;
    did[a%7]=1;
    a/=7;
  }
  for(int i=0;i<db;++i){
    if(did[b%7])return false;
    did[b%7]=1;
    b/=7;
  }
  return true;
}

int main()
{
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    vector<long long> pow7(1, 1);
    for(int i=0;i<15;++i){
      pow7.emplace_back(pow7.back()*7);
    }
    while(pow7[da]<a)++da;
    while(pow7[db]<b)++db;
    if(da+db>7){
      cout << 0 << "\n";
      return 0;
    }
    int ret=0;
    for(int i=0;i<a;++i){
      for(int j=0;j<b;++j){
        if(dec(i, j)){
          //cerr << i << " " << j << "\n";
          ++ret;
        }
      }
    }
    cout << ret << "\n";



    return 0;
}