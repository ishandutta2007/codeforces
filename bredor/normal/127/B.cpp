//  228

#include <iostream>
#include <algorithm>
// #include <tuple>
// #include <vector>
using namespace std;

int sticks, amount[200], inp;
int divisions, framesTotal;
// vector<tuple<int, int>> stick;  //<0> is length, <1> is

bool sortLargestToSmallest(int i, int j){
  return i > j;
}

int main(){
  cin >> sticks;
  for(int i = 1; i <= sticks; i++){
    cin >> inp;
    amount[inp]++;
  }
  while(true){
    sort(amount, amount + 200, sortLargestToSmallest);
    if(amount[0] >= 2 && amount[1] >= 2){
      divisions = amount[1] / 2;
      amount[0] -= divisions * 2;
      amount[1] -= divisions * 2;
      framesTotal += divisions;
    }
    else if(amount[0] >= 4){
      divisions = amount[0] / 4;
      amount[0] -= divisions * 4;
      framesTotal += divisions;
    }
    else{
      break;
    }
  }
  cout << framesTotal << endl;
  return 0;
}