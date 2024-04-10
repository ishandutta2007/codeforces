#include <bits/stdc++.h>

using namespace std;

void bye() {
  cout << "no\n";
  exit(0);
}

const int N = 3000 + 7;
int n, m, score[N], sol[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> score[i];
  }

  int sumScore = n * (n - 1);
  for (int i = 1; i <= m; i++) {
    sumScore -= score[i];
  }

  if (sumScore < 0) bye();

  if (m < n) {
    int cnt = n - m, big = sumScore % cnt;
    for (int i = m + 1; i <= n; i++) {
      score[i] = sumScore / cnt;
      if (big) {
        score[i]++;
        big--;
      }
    }

    sumScore = 0;
    for (int i = 1; i <= n; i++) {
      sumScore += score[i];
    }
    assert(sumScore == n * (n - 1));
  }


  for (int i = 1; i < n; i++) {
    if (score[i] < score[i + 1]) bye();
  }

  sumScore = 0;
  int cnt = 0;


  for (int i = n; i >= 1; i--) {
    sumScore += score[i];
    cnt++;
    if (sumScore < cnt * (cnt - 1)) bye();
  }

  for (int i = 1; i <= n; i++) {
    assert(score[i] <= 2 * (n - i));

    priority_queue<pair<int, int>> pq;
    for (int j = i + 1; j <= n; j++) {
      sol[i][j] = 2;
      pq.push({score[j], j});
    }

    for (int ind = 1; ind <= 2 * (n - i) - score[i]; ind++) {
      while (1) {
        assert(!pq.empty());

        int x = pq.top().second;
        pq.pop();

        if (sol[i][x] > 0) {
          sol[i][x]--;
          score[x]--;
          pq.push({score[x], x});
          break;
        }
      }
    }


  }

  cout << "yes\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        cout << "X";
        continue;
      }
      if (i > j) sol[i][j] = 2 - sol[j][i];
      if (sol[i][j] == 2) cout << "W";
      if (sol[i][j] == 1) cout << "D";
      if (sol[i][j] == 0) cout << "L";
    }
    cout << "\n";
  }
  return 0;
}