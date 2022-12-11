#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int powe[2001010];

int main(){
  int n;
  scanf("%d", &n);
  
  vi pp(n);
  
  for(int i = 0;i < n;++i){
    int x;
    scanf("%d", &x);
    pp[i] = x;
    ++powe[x];
  }
  
  sort(pp.begin(), pp.end());
  
  int count = 0;
  
  for(int i = 0; i < n; ++i){
    int j = pp[i];
    
    while(powe[j] > 0){
      powe[j + 1] += powe[j] / 2;
      if(powe[j] % 2) ++count;
      powe[j] = 0;
      ++j;
    }
  }
  
  
  
  printf("%d\n",count);
}