#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> pos;
  int tmp;
  for(int i=0;i<N;++i){
    cin >> tmp;
    pos.push_back(tmp);
  }

  sort(pos.begin(), pos.end());
  long long sum = 0;
  int count = 0;
  for(int e:pos){
    if(e>=sum){
      sum+=e;
      ++count;
    }
  }
  cout << count;
  return 0;
}