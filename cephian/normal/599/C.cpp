#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> srt;
const int N = 100005;
int s[N];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    srt.push_back(pii(h,i));
  }
  sort(srt.begin(),srt.end());
  for(int i = 0; i < srt.size(); ++i)
    s[srt[i].second] = i;
    int mx_seen = -1;
  int blk = 0;
  for(int i = 0; i < n; ++i) {
    mx_seen = max(mx_seen,s[i]);
    if(mx_seen == i) ++blk;
  }
  cout << blk << "\n";
  return 0;
}