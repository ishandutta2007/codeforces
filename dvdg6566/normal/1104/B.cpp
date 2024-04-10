#include<bits/stdc++.h>
using namespace std;

stack<char> s;
int N,cnt;
string st;

int main(){
  cin>>st;
  for (auto i : st){
    if (s.size() && s.top() == i){
      ++cnt;
      s.pop();
    }
    else s.push(i);
  }
  if(cnt%2==0)cout<<"No";
  else cout << "Yes";
}