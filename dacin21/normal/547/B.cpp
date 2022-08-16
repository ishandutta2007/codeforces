#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  cin.tie(0);

  vector<int> bears(N);
  vector<pair<int, int> > sorted(N);
  map<int, int> segs;
  int mindist = 0;

  for(int i=0;i<N;++i){
    int tmp;
    cin >> tmp;
    bears[i] = tmp;
    sorted[i] = pair<int, int> (-tmp, i);
  }
  sort(sorted.begin(), sorted.end());

  for(auto e:sorted){
    auto base = segs.lower_bound(e.second);
    if(base!=segs.begin()){
      --base;
      if(base->first+base->second == e.second){
        base->second++;
      } else {
        segs[e.second] = 1;
        base=segs.find(e.second);
      }
    }
     else {
      segs[e.second] = 1;
      base=segs.find(e.second);
    }
    if(base!=segs.end()){
      auto base2(base);
      ++base2;
      if(base2!=segs.end() && base2->first == base->first + base->second){
        base->second+=base2->second;
        segs.erase(base2);
      }
    }

    base = segs.upper_bound(e.second);
    --base;
    while(mindist < base->second){
      cout << -e.first << " " ;
      ++mindist;
    }
  }

  return 0;

}