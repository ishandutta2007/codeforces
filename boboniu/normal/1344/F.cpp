#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 1234;
typedef bitset<3001> equation;
int n, k, id, val[maxN], equid;
int lab[maxN][4];
equation eqn[3333], eq;
// R 011
// Y 101
// B 110

void addeq() {
  for (int i = 3 * n - 1; i >= 0; i--) {
    if (eq[i]) {
      if (eqn[i][i])
        eq ^= eqn[i];
      else {
        eqn[i] = eq;
        eq.reset();
        break;
      }
    }
  }
  if (eq[3 * n]) {
    printf("NO\n");
    exit(0);
  }
};
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      lab[i][j] = id++;
      eq[lab[i][j]] = 1;
    }
    addeq();
  }
  for (int query = 0; query < k; query++) {
    char op[5], op2[5];
    scanf("%s", op);
    if (op[0] == 'm') {
      int m;
      scanf("%d", &m);
      for (int l = 0; l < m; l++) {
        scanf("%d", &val[l]);
        --val[l];
      }
      scanf("%s", op2);

      for (int j = 0; j < 3; j++) {
        eq.reset();
        for (int l = 0; l < m; l++) {
          eq[lab[val[l]][j]] = 1;
        }
        if (op2[0] == 'R') {
          if (j == 0)
            eq[3 * n] = 0;
          else
            eq[3 * n] = 1;
        } else if (op2[0] == 'Y') {
          if (j == 1)
            eq[3 * n] = 0;
          else
            eq[3 * n] = 1;
        } else if (op2[0] == 'B') {
          if (j == 2)
            eq[3 * n] = 0;
          else
            eq[3 * n] = 1;
        }
        addeq();
      }
    } else if (op[0] == 'R' && op[1] == 'Y') {
      int m;
      scanf("%d", &m);
      for (int l = 0; l < m; l++) {
        scanf("%d", &val[l]);
        --val[l];
      }
      for (int l = 0; l < m; l++)
        swap(lab[val[l]][0], lab[val[l]][1]);
    } else if (op[0] == 'R' && op[1] == 'B') {
      int m;
      scanf("%d", &m);
      for (int l = 0; l < m; l++) {
        scanf("%d", &val[l]);
        --val[l];
      }
      for (int l = 0; l < m; l++)
        swap(lab[val[l]][0], lab[val[l]][2]);
    } else {
      int m;
      scanf("%d", &m);
      for (int l = 0; l < m; l++) {
        scanf("%d", &val[l]);
        --val[l];
      }
      for (int l = 0; l < m; l++)
        swap(lab[val[l]][1], lab[val[l]][2]);
    }
  }
  for (int i = 0; i < 3 * n; i++)
    if (eqn[i][i]) {
      for (int j = i + 1; j < 3 * n; j++)
        if (eqn[j][i])
          eqn[j] ^= eqn[i];
    }
  string ch(n, ' ');
  for (int i = 0; i < n; i++) {
    int val = 0;
    for (int j = 0; j < 3; j++)
      val = val * 2 + ((bool)eqn[i * 3 + j][3 * n]);
    if (val == 0)
      ch[i] = '.';
    else if (val == 3)
      ch[i] = 'R';
    else if (val == 5)
      ch[i] = 'Y';
    else
      ch[i] = 'B';
  }
  printf("YES\n%s\n", ch.c_str());
}