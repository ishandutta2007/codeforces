#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N, k;
  cin >> N >>  k;
  k = N-k;

  int even = 0;
  int odd = 0;

  int k2 = k/2;
  int k1=k - k2;

  int tmp;
  for(int i=0;i<N;++i){
    cin >> tmp;
    if(tmp&1)++odd;
      else ++even;
  }

  if(k==0){
    if(odd&1){
      cout << "Stannis";
    } else cout << "Daenerys";
    return 0;
  }


  if(k2 >= odd){
    cout << "Daenerys";
    return 0;
  }


  if(k2 >= even && !((N-k)&1)){
    cout << "Daenerys";
    return 0;
  }

  if(k1>=even && ((N-k)&1)){
      //cout <<k <<"," << k2 << "," << k1 << " >= " << even << "\n";
    cout << "Stannis";
    return 0;
  }




  //if(N&1){
  if(k&1){
    cout << "Stannis";
    return 0;
  }
  cout << "Daenerys";
 return 0;
}