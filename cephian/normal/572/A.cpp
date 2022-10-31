#include <iostream>

using namespace std;

int A[100005], B[100005];

int main() {
  ios::sync_with_stdio(0);
  int a, b;
  int n, k;
  cin >> a >> b >> n >> k;
  for(int i = 0; i < a; ++i)
    cin >> A[i];
    for(int i = 0; i < b; ++i)
      cin >> B[i];
  if(A[n-1] < B[b - k]) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}