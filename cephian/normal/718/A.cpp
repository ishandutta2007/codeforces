#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int n,t;
string num;
const int N = 200000;
int f[N]={0};

vector<char> ans;

char p(int i) {
  if(num[i] == '.') return num[i+1];
  return num[i];
}

void add1(int i) {
  if(i == -1) {
    num = "1"+num;
    return;
  }
  if(num[i] == '.') add1(i-1);
  else if(num[i] == '9') {
    num[i] = '0';
    add1(i-1);
  } else {
    ++num[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> t >> num;
  n = num.size();
  f[n-1] = 0;
  for(int i = n-2; i >=0; --i) {
    if(num[i] == '.') continue;
    int j = i+1;
    if(num[i+1] == '.') ++j;

    if(num[j] < '4') {
      f[i] = 0;
    } else if (num[j] == '4') {
      if(f[j] == 0) f[i] = 0;
      else f[i] = 1+f[j];
    } else {
      f[i] = 1;
    }
  }
  int earliest = 0x7fffffff;
  for(int i = 0; i < n; ++i) {
    if(num[i] == '.') {
      earliest = i-1;
      break;
    }
  }
  for(int i = 0; i < n; ++i) {
    if(num[i] == '.') continue;
    if(f[i] != 0 && f[i] <= t && i >= earliest) {
      add1(i);
      for(int j = i+1; j < n; ++j) {
        if(num[j] == '.') continue;
        num[j] = '0';
      }
      break;
    }
  }
  for(int i = 0; i < n; ++i) {
    ans.push_back(num[i]);
  }
  bool hasdec = 0;
  for(int i = 0; i < n; ++i) {
    if(num[i] == '.') hasdec = 1;
  }

  while(hasdec && ans.size() > 1 && (ans[ans.size()-1] == '0')) {
    ans.pop_back();
  }
  if(ans[ans.size()-1] == '.')
    ans.pop_back();
  for(int i = 0; i < ans.size(); ++i)
    cout << char(ans[i]);
  cout << "\n";
  return 0;
}