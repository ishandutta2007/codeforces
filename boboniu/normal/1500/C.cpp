#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 1534

int n, m;
int a[maxN][maxN], b[maxN][maxN], ord[maxN], negcnt[maxN];
bool isequ[maxN], used[maxN];
vector<int> seqa[maxN], seqb[maxN];

void solve(vector<int> id) {
  bool sorted = true;
  for (int i = 1; i < id.size(); i++)
    if (id[i - 1] > id[i])
      sorted = false;
  if (sorted)
    return;
  for (int i = 0; i < m; i++) {
    bool ordered = true;
    for (int j = 1; j < id.size(); j++) {
      if (a[id[j - 1]][i] > a[id[j]][i]) {
        ordered = false;
      }
    }
    if (a[id[0]][i] == a[id.back()][i])
      ordered = false;
    if (ordered) {
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    vector<int> pa;
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
    pa = vector<int>(a[i], a[i] + m);
    pa.push_back(i);
    seqa[i] = pa;
  }
  for (int i = 0; i < n; i++) {
    vector<int> pb;
    for (int j = 0; j < m; j++)
      scanf("%d", &b[i][j]);
    pb = vector<int>(b[i], b[i] + m);
    pb.push_back(i);
    seqb[i] = pb;
  }
  sort(seqa, seqa + n);
  sort(seqb, seqb + n);
  for (int i = 0; i < n; i++) {
    if (vector<int>(seqa[i].begin(), seqa[i].begin() + m) !=
        vector<int>(seqb[i].begin(), seqb[i].begin() + m)) {
      printf("-1");
      return 0;
    }
    b[seqb[i][m]][m] = seqa[i][m];
  }
  for (int i = 1; i < n; i++)
    isequ[i] = true;
  vector<int> answer;
  set<int> zeroneg;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m + 1; j++) {
      negcnt[j] += b[i - 1][j] > b[i][j];
    }
  }
  for (int j = 0; j < m + 1; j++) {
    if (negcnt[j] == 0)
      zeroneg.insert(j);
  }
  for (int i = 0; i < m + 1; i++) {
    bool found = false;
    if (!zeroneg.empty()) {
      int j = *(zeroneg.begin());
      zeroneg.erase(j);
      found = true;
      answer.push_back(j + 1);
      used[j] = 1;
      for (int k = 1; k < n; k++)
        if (isequ[k] && b[k - 1][j] < b[k][j]) {
          isequ[k] = false;
          for (int j = 0; j < m + 1; j++) {
            if (!used[j] && b[k - 1][j] > b[k][j]) {
              negcnt[j] -= 1;
              if (negcnt[j] == 0)
                zeroneg.insert(j);
            }
          }
        }
    }

    if (!found) {
      printf("-1");
      return 0;
    }
    if (answer.back() == m + 1)
      break;
  }
  printf("%d\n", answer.size() - 1);
  reverse(answer.begin(), answer.end());
  for (int col : answer)
    if (col != m + 1)
      printf("%d ", col);
  printf("\n");
}