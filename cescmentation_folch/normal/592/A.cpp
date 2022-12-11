#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

int rt[8];
int rb[8];

int main(){
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      char a;
      cin >> a;
      if(a != '.'){
	if(rt[j] == 0) rt[j] = (a == 'W')? i + 1 : -(i + 1);
	rb[j] = (a == 'B')? 8 - i : -(8 - i);
      }
    }
  }
  int mt = 9;
  int mb = 9;
  
  for(int i = 0; i < 8; ++i){
    if(rt[i] > 0) mt = min(mt, rt[i]);
    if(rb[i] > 0) mb = min(mb, rb[i]);
  }
  
  if(mt <= mb) cout << 'A' << endl;
  else cout << 'B' << endl;
}