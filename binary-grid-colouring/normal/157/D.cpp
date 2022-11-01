#include<bits/stdc++.h>

using namespace std;
const int maxn = 100100;
const double eps = 1e-9;
const double pi = 3.1415926536;

int n,m;
int a[maxn],b[maxn],c[maxn];
bool ok[maxn];

int main(int argc, char const *argv[]) {

  std::cin >> n >> m;
  int sum = 0; 
  for(int i=1;i<=n;i++) {
    int x;
    cin >> x;
    c[i] = x;
    if(x>0) a[x]++;
    else {
      x = -x;
      b[x]++;
      sum++;
    }
  }

  int num = 0;
  for(int i=1;i<=n;i++) { 
    int tmp = sum - b[i] + a[i];
    if(tmp == m) { 
      num++;
      ok[i] = true;
    }
  }
  if(num > 1) 
  {
    for(int i=1;i<=n;i++) {
      int x = c[i];
      if(x > 0) { 
        puts(ok[x]?"Not defined":"Lie");
      }
      else 
      {
        x = -x;
        puts(ok[x] == 0? "Truth":"Not defined");
      }
    }
  }
  else 
  {
    for(int i=1;i<=n;i++) {
      int x = c[i];
      if(x > 0) { 
        puts(ok[x]?"Truth":"Lie");
      }
      else  
      {
        x = -x;
        puts(ok[x]? "Lie" : "Truth");
      }
    }
  }
  return 0;
}