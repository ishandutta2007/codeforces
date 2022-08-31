#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;
int main(){

  /*  ifstream f("in.txt");
    cin.rdbuf(f.rdbuf());*/

  unsigned long long H, Q;
  cin >> H >> Q;

  //vector<pair<int, int> > in;
  vector<pair<unsigned long long, unsigned long long> > out;


  unsigned long long index, L, R, ans;
  unsigned long long minL = 1LL<<(H-1);
  unsigned long long maxR = (1LL<<H)-1;
  /*if(Q==27472){
      cout << minL << " / " << maxR << "\n";
  }*/
  for(int i=0;i<Q;++i){
    cin >> index >> L >> R >> ans;
    for(;index < H;++index){
      L*=2;
      R=2*R+1;
    }
    if(ans==1){
      minL = max(minL, L);
      maxR = min(maxR, R);
    } else {
      out.emplace_back(L, R);
    }
  }

  sort(out.begin(), out.end());
  out.emplace_back(1LL<<H, 1LL<<H);

  unsigned long long maxBan = minL-1;
  unsigned long long ret = 0;
  for(auto e:out){
    if(e.first > maxR) e.first = maxR+1;

    if(e.first <= maxBan+1){
      maxBan=max(maxBan, e.second);
    } else {
      if(maxBan >= maxR){
        if(ret==0){
          cout << "Data not sufficient!";
          return 0;
        } else{
          cout << ret;
          return 0;
        }
      } else {
        if(e.first == maxBan+2){
          if(ret==0){
            ret = maxBan+1;
            maxBan=e.second;
          } else {
            cout << "Data not sufficient!";
            return 0;
          }
        } else {
            cout << "Data not sufficient!";
            //cerr  << e.first << " / " << e.second;
            return 0;
        }
      }
    }
  }
  /*if(Q==27472){
    cout << minL << " / " << maxR;
  }*/

  if(ret==0) cout << "Game cheated!";
  else cout << ret;

  return 0;
}