#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  deque<int> d;
  for(int i = 0; i<n; i++){
    int a;
    scanf("%d", &a);
    d.push_front(a);
  }
  int prev = 0;
  queue<int> q;
  while(!d.empty()){
    if(d.front() > d.back()){
      if(d.back() > prev){
        q.push(1);
        prev = d.back();
        d.pop_back();
      }
      else if(d.front() > prev){
        q.push(0);
        prev = d.front();
        d.pop_front();
      }
      else break;
    }
    else if(d.front() < d.back()){
      if(d.front() > prev){
        q.push(0);
        prev = d.front();
        d.pop_front();
      }
      else if(d.back() > prev){
        q.push(1);
        prev = d.back();
        d.pop_back();
      }
      else break;
    }
    else{
      if(d.front() <= prev) break;
      break;
    }
  }
  deque<int> co = d;
  int cp = prev;
  int numr = 0, numl = 0;
  while(!d.empty() && d.front() > prev){
    ++numr;
    prev = d.front();
    d.pop_front();
  }
  while(!co.empty() && co.back() > cp){
    ++numl;
    cp = co.back();
    co.pop_back();
  }
  if(numr > numl){ 
    for(int i = 0; i<numr; i++) q.push(0);
  }
  else{
    for(int i = 0; i<numl; i++) q.push(1);
  }
  cout << q.size() << endl;
  while(!q.empty()){
    if(q.front() == 0) cout << "R";
    else cout << "L";
    q.pop();
  }
  cout << endl;
}