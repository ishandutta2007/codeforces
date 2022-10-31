%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define clear(s) memset(s, 0, sizeof(s))
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define For(i, l, r) rep(i, l, r - 1)

void read(int &x) {
  x = 0; int f = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') f = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  x *= f;
}

int cnt[1005];

int Abs(int k) {
  return k < 0 ? -k : k;
}
bool OK(string pp) {
  int len = pp.size();
  for (int i = 1; i < len; i++) {
    if (Abs(pp[i - 1] - pp[i]) == 1)
      return 0;
  }
  return 1;
}

int main() {
  int t; read(t);
  while (t--) {
    clear(cnt);
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
      cnt[s[i] - 'a' + 1]++;
    }
    int l1 = 0, l2 = 0, fuck1 = 0, fuck2 = 0;
    for (int i = 2; i <= 26; i += 2) l1 += cnt[i];
    for (int i = 1; i <= 26; i += 2) l2 += cnt[i];
    
    if (l1 == 0) {
      for (int i = 1; i <= 26; i += 2)
        for (int j = 1; j <= cnt[i]; j++)
          printf("%c", i + 'a' - 1);
      puts("");
      continue;
    }
    if (l2 == 0) {
      for (int i = 2; i <= 26; i += 2)
        for (int j = 1; j <= cnt[i]; j++)
          printf("%c", i + 'a' - 1);
      puts("");
      continue;
    }
    
    for (int i = 2; i <= 26; i += 2)
      for (int j = 1; j <= 26; j += 2)
        if (cnt[i] && cnt[j] && Abs(i - j) != 1)
          fuck1 = i, fuck2 = j;

    
    string tot = "";
    for (int i = 25; i >= 1; i -= 2) {
      if (i == fuck2) continue;
      for (int j = 1; j <= cnt[i]; j++) {
        char f = i + 'a' - 1;
        tot += f;
      }
    }
    // fuck you!
    for (int i = 1; i <= cnt[fuck2]; i++) {
      char f = fuck2 + 'a' - 1;
      tot += f;
    }
    for (int i = 1; i <= cnt[fuck1]; i++) {
      char f = fuck1 + 'a' - 1;
      tot += f;
    }
    for (int i = 26; i >= 2; i -= 2) {
      if (i == fuck1) continue;
      for (int j = 1; j <= cnt[i]; j++) {
        char f = i + 'a' - 1;
        tot += f;
      }
    }
    /*
    if (l1 > 0 && l2 > 0 && Abs(tot[l1 - 1]-tot2[0]) == 1) {
      int ok = 0;
      for (int i = l1 - 1; i >= 0; i--) {
        if (Abs(tot[i] - tot2[0]) != 1) {
          ok = 1;
          swap(tot[i], tot[l1 - 1]);
          break;
        }
      }
      if (!ok) {
        for (int i = 0; i < l2; i++) {
          if (Abs(tot[l1 - 1] - tot2[i]) != 1) {
            ok = 1;
            swap(tot2[0], tot2[i]);
            break;
          }
        }
      }
    }
    */
  //  cout << tot << '\n';
    if (OK(tot)) cout << tot << '\n';
    else puts("No answer");
  }
  return 0;
}