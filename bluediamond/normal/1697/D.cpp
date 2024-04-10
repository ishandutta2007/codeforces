#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n;
char solution[N];
int rightmost[N];
int leftmost[N];
int last[26];

char getChar(int pos) {
  assert(1 <= pos && pos <= n);
  cout << "? 1 " << pos << endl;
  string Sol;
  cin >> Sol;
  assert((int) Sol.size() == 1);
  return Sol[0];
}

int cntDistinctInInterval(int l, int r) {
  assert(1 <= l && l <= r && r <= n);
  cout << "? " << 2 << " " << l << " " << r << endl;
  int Sol;
  cin >> Sol;
  return Sol;
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) solution[i] = '?';
  int lastTime = 0;
  for (int i = 1; i <= n; i++) {
    int current = cntDistinctInInterval(1, i);
    if (current != lastTime) {
      assert(current == lastTime + 1);
      solution[i] = getChar(i);
      lastTime = current;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (solution[i] == '?') {
      vector<pair<int, int>> Possible;
      for (int x = 0; x < 26; x++) {
        if (last[x]) {
          Possible.push_back({last[x], x});
        }
      }
      sort(Possible.rbegin(), Possible.rend());
      int low = 0, high = (int) Possible.size() - 1;
      while (low <= high) {
        int j = (low + high) / 2;
        if (cntDistinctInInterval(Possible[j].first, i) != j + 2) {
          solution[i] = Possible[j].second + 'a';
          high = j - 1;
        } else {
          low = j + 1;
        }
      }
    }
    assert('a' <= solution[i] && solution[i] <= 'z');
    last[solution[i] - 'a'] = i;
  }

  cout << "! " << (solution + 1) << endl;
}

/**
[xaa][x......]


x a a x
**/