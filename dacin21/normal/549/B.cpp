#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


using namespace std;

int main()
{
  /*ifstream is("in.txt");
    cin.rdbuf(is.rdbuf());*/
  int N;
  cin >> N;
  vector<int> left;
  queue<int> cands;
  queue<int> ret;

  int tmp;

  vector<vector<int> > friends(N, vector<int>(0));
  char ch;
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){

        cin >> ch;

        if(ch == '1'){
          friends[i].push_back(j);
        }
    }
  }


  for(int i=0;i<N;++i){
    cin >> tmp;
    left.push_back(tmp);
    if(tmp == 0){
      cands.push(i);
    }
  }

  int cur;
  while(!cands.empty()){
    cur = cands.front();
    cands.pop();
    if(left[cur]) continue;
    ret.push(cur);
    for(int e:friends[cur]){
      if(!(--left[e])){
        cands.push(e);
      }
    }
  }

  cout << ret.size() << "\n";
  while(!ret.empty()){
    cur = ret.front()+1;
    ret.pop();
    cout << cur << " ";
  }

  return 0;
}