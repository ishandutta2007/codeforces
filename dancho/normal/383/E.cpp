#include <cstdio>
#include <cstring>

inline int bcnt(int ma) {
  int r = 0;
  while (ma) {
    r += (ma&1);
    ma /= 2;
  }
  return r;
}

inline int hasLet(char x, int ma) {
  return (ma&(1<<(x-'a')));
}

int cnt;

int n;
char s[10020][16];

void solve(int le, int ri, int a[], int b[], int c[]) {
  if (le == ri-1) {
    b[0] = a[le];
    return;
  }
  int mid = (le+ri)/2;
  solve(le, mid, a, c, b);
  int len = mid-le;
  solve(mid, ri, a, c+len, b);
  for (int i = le, j = 0; i < ri; ++i, ++j) {
    if (j < len) {
      b[j] = c[j];
    }
    else {
      b[j] = c[j-len] + c[j];
    }
  }
}

int a[1<<24];
int b[1<<24];
int c[1<<24];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }

  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int ma = (1<<(s[i][0]-'a')) | (1<<(s[i][1]-'a')) | (1<<(s[i][2]-'a'));
    ++a[ma];
  }

  solve(0, (1<<24), a, b, c);
  cnt = 0;
  for (int i = 0; i < (1<<24); ++i) {
    //~ if (b[i])
      //~ printf("%d %d\n", i, b[i]);
    cnt ^= (n-b[i])*(n-b[i]);
  }
  printf("%d\n", cnt);
  return 0;
}