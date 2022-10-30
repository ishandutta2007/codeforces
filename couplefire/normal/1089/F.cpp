#include <bits/stdc++.h>
using namespace std;

pair<int, int> factor(int n){
  int num = 0;
  int i = 2;
  bool findone = false;
  queue<int> q;
  pair<int, int> temp;
  while(i <= sqrt(n)){
    if(n % i == 0){
      n /= i;
      if(!findone){
        num++;
        q.push(i);
        findone = true;
      }
    }
    else{
      findone = false;
      i++;
    }
  }
  if(n > i){
    num++;
    q.push(n);
  }
  if(num < 2) return make_pair(-1, 0);
  temp.first = q.front();
  q.pop();
  temp.second = q.front();
  return temp;
}

int main() {
  int n;
  cin >> n;
  pair<int, int> t = factor(n);
  if(t.first == -1){
    cout << "NO" << endl;
    return 0;
  }
  --n;
  int x = 1;
  while((n - x*t.first) % t.second != 0) x++;
  cout << "YES" << endl;
  cout << 2 << endl;
  cout << x << " " << (n+1)/t.first << endl;
  cout << (n-x*t.first)/t.second << " " << (n+1)/t.second << endl;
}