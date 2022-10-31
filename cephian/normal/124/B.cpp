#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
string s[8];
int perm[] = {0,1,2,3,4,5,6,7};
int nums[8];

int dist() {
  for(int i = 0; i < n; ++i) {
    string str = s[i];
    for(int j = 0; j < k; ++j)
      str[perm[j]] = s[i][j];
    nums[i] = 0;
    for(int j = 0; j < k; ++j) {
      nums[i] *= 10;
      nums[i] += str[j] - '0';
    }
  }
  sort(nums, nums+n);
  return nums[n-1] - nums[0];
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    cin >> s[i];
  int ans = 0x7fffffff;
  do {
    ans = min(ans, dist());
  } while(next_permutation(perm, perm+k));
  cout << ans << "\n";
  return 0;
}