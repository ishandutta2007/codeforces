#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  //cin >> n >> m;
  for(int i = 1; i<=m/2; i++){
    for(int k = 1; k<=n; k++){
      printf("%d %d\n", k, i);
      printf("%d %d\n", n+1-k, m+1-i);
      //cout << k << " " << i << endl;
      //cout << n+1-k << " " << m+1-i << endl;
    }
  }
  if(m % 2 == 1){
    int t = m/2 +1;
    for(int i = 1; i<=n/2; i++){
      printf("%d %d\n", i, t);
      printf("%d %d\n", n+1-i, t);
      //cout << i << " " << t << endl;
      //cout << n+1-i << " " << t << endl;
    }
    if(n %2 == 1) printf("%d %d\n", n/2+1, t);//cout << n/2+1 << " " << t << endl;
  }
}