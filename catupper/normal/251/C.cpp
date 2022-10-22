#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF (1LL << 60)

long long int table[360366], res, a, b, k;
int lcf[] = {0,0,2,6,12,60,60,420,840,2520,2520,27720,27720,360360,360360,360360};

void filt(int from){
  fill(table, table + 360366, INF);
  table[from] = 0;
  for(int i = from + 1;i < lcf[k];i++){
    table[i] = table[i - 1] + 1;
    for(int j = 2;j <= k;j++){
      table[i] = min(table[i], table[i - i % j] + 1);
    }
  }
}

int main(){
  cin >> a >> b >> k;
  if(a / lcf[k] != b / lcf[k]){
    filt(0);
    res += table[a % lcf[k]];
    res += (a/lcf[k] - b/lcf[k] - 1) * (table[lcf[k] - 1] + 1) + 1;
    a = lcf[k] * (b / lcf[k] + 1) - 1;
  }
  filt(b % lcf[k]);
  res += table[a % lcf[k]];
  cout << res << endl;
  return 0;
}