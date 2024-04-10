#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int n;

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  for (int i = 1; i < n; i++)
    if (a[i] != a[i + 1]) {
      int j = i + 1;
      while(j < n && a[j] != a[j + 1])
        j++;
      ans = max(ans, (j - i) / 2);
      for(int k = 1; k <= (j - i) / 2; k++) {
        a[i + k] = a[i];
        a[j - k] = a[j];
      }
      i = j;
    }
  cout << ans <<endl;
  for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
  return 0;
}