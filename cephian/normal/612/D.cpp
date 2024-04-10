#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n, k;
vector<pii> v;
vector<int> ans;

int main() {
  scanf("%d %d", &n , &k);
  for(int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    v.push_back(pii(a,0));
    v.push_back(pii(b,1));
  }
  sort(v.begin(), v.end());

  bool in_seg=0;
  int cover=0;
  for(int i = 0; i < v.size(); ++i) {
    if(v[i].second == 0) ++cover;
    if(v[i].second == 1) --cover;
    if(cover >= k && !in_seg) {
      ans.push_back(v[i].first);
      in_seg = 1;
    } else if(cover < k && in_seg) {
      ans.push_back(v[i].first);
      in_seg = 0;
    }
  }
  printf("%d\n", int(ans.size()/2));
  for(int i = 0; i < ans.size(); i+=2)
    printf("%d %d\n", ans[i], ans[i+1]);
}