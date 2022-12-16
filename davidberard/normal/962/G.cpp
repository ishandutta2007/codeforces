#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

set<pii> have;

struct Seg {
  int x, y1, y2;
  bool operator< (const Seg& o) const {
    return x < o.x;
  }
};


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int x1, x2, y1, y2;
  cin >> x1 >> y2 >> x2 >> y1;
  int n;
  cin >> n;
  vector<pii> pts(n);
  for (auto& p : pts) {
    cin >> p.first >> p.second;
  }
  vector<Seg> segs;
  for (int i=0; i<n; ++i) {
    if (pts[i].first == pts[(i+1)%n].first) {
      segs.push_back({pts[i].first, pts[i].second, pts[(i+1)%n].second});
    }
  }
  sort(segs.begin(), segs.end());
  int ans = 0;

  for (auto s : segs) {
    if (s.x >= x2) break;
    //cerr << " ISERT " << endl;
    if (s.y1 > s.y2) { // enter
      if (s.y1 <= y1 || s.y2 >= y2) {
        continue;
      }
      s.y1 = min(s.y1, y2);
      s.y2 = max(s.y2, y1);
      have.insert({s.y2, s.y1});
    } else { // exit s.y2 > s.y1
      if (s.y2 <= y1 || s.y1 >= y2) {
        continue;
      }
      s.y2 = min(s.y2, y2);
      s.y1 = max(s.y1, y1);
      bool rtop = 0, rbot = 0;
      while (true) {
        auto it = have.upper_bound(pii(s.y1, -1e9));
        //cerr << " :: " << s.x << "," << s.y1 << "," << s.y2 << endl;
        if (it == have.end()) {
          break;
        }
        if (it->first == s.y2) {
          //cerr << " : EXIT " << endl;
          rtop = 1;
          break;
        }
        if (it->first > s.y2) {
          break;
        }
        pii res = *it;
        have.erase(it);
        res.first = s.y2;
        if (res.first < res.second) {
          have.insert(res);
        }
      }
      auto it = have.upper_bound(pii(s.y1, -1e9));
      if (it != have.begin()) {
        it = prev(it);
        if (it->second >= s.y1) {
          pii res = *it;
          have.erase(it);
          if (it->second > s.y2) {
            have.insert({res.first, s.y1});
            have.insert({s.y2, res.second});
            if (s.x > x1) {
              --ans;
        //cerr << " .. " << s.x << "," << s.y1 << "," << s.y2 << " -1 " << endl;
            }
            continue;
          }
          res.second = s.y1;
          if (res.second > res.first) {
            have.insert(res);
          }
          rbot = 1;
        }
      }

      ////cerr << " RTOP RBOT " << rtop << " " << rbot << " x " << s.x << endl;
      if (rtop && rbot && s.x > x1) {
        //cerr << " :: " << s.x << "," << s.y1 << "," << s.y2 << " -1 " << endl;
        --ans;
        continue;
      }

      it = have.upper_bound(pii(s.y1, -1e9));
      if (it != have.end()) {
        assert(it->first >= s.y2);
        //cerr << " :: " << it->first << " VS " << s.y2 << endl;
        if (it->first == s.y2) {
          //cerr << " HAS AFTER " << endl;
          continue;
        }
      }
      if (it != have.begin()) {
        it = prev(it);
        assert(it->second <= s.y1);
        //////cerr << " -> " << it->first <<','<< it->second << endl;
        if (it->second == s.y1) {
          //cerr << " HAS BEFORE" << endl;
          continue;
        }
      }

      //////cerr << " :: " << s.x << " " << s.y1 << " " << s.y2 << endl;
      
      if (s.x > x1) {
        ans++;
      }
    }
  }

  ans += have.size();
  ////cerr << "!! " << endl;
  for (auto it = have.begin(); it != have.end() && next(it) != have.end(); ++it) {
    if (it->second == next(it)->first) {
      --ans;
    }
  }
  cout << ans << "\n";

  return 0;
}