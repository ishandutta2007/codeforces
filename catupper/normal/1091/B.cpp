#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;

vector<P> obel, clue;
P ans;
int x, y, n;
void check(){
  vector<P> dif;
  for(int i = 0;i < n;i++){
    dif.push_back(P(ans.first - obel[i].first,ans.second - obel[i].second));
  }
  sort(dif.begin(), dif.end());
  if(dif == clue){
    cout << ans.first << " " << ans.second << endl;
    exit(0);
  }
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> x >> y;
    obel.push_back(P(x,y));
  }
  
  for(int i = 0;i < n;i++){
    cin >> x >> y;
    clue.push_back(P(x,y));
  }
  sort(clue.begin(), clue.end());
  for(int i = 0;i < n;i++){
    ans.first = obel[0].first + clue[i].first;
    ans.second = obel[0].second + clue[i].second;
    check();
  }
  return 0;
}