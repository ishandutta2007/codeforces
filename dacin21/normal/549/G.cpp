#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> pp;
  int tmp;
  for(int i=0;i<N;++i){
    cin >> tmp;
    pp.push_back(tmp+i);
  }

  sort(pp.begin(), pp.end());

  for(int i=0;i<N-1;++i){
    if(pp[i] == pp[i+1]){
      cout << ":(";
      return 0;
    }
  }

  for(int i=0;i<N;++i){
    cout << pp[i]-i <<" ";
  }

  return 0;

}