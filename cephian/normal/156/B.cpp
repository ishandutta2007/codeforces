#include <iostream>
#include <set>

using namespace std;

int n,m,tdidnt=0;
int did[100005]={0};
int didnt[100005]={0};
int guess[100005]={0};
set<int> maybe;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> guess[i];
    if(guess[i] > 0) {
      ++did[guess[i]];
    } else {
      ++didnt[-guess[i]];
      ++tdidnt;
    }
  }
  for(int i = 1; i <= n; ++i) {
    int truth = did[i] + tdidnt - didnt[i];
    if(truth == m)
      maybe.insert(i);
  }
  for(int i = 1; i <= n; ++i) {
    if(guess[i] > 0) {
      if(maybe.size() == 1) {
        if(maybe.count(guess[i])) cout << "Truth\n";
        else cout << "Lie\n";
      } else if(maybe.count(guess[i])) {
        cout << "Not defined\n";
      } else {
        cout << "Lie\n";
      }
    } else {
      if(maybe.size() == 1) {
        if(maybe.count(-guess[i]))
          cout << "Lie\n";
        else cout << "Truth\n";
      } else if(maybe.count(-guess[i])) {
        cout << "Not defined\n";
      } else {
        cout << "Truth\n";
      }
    }
  }
  return 0;
}