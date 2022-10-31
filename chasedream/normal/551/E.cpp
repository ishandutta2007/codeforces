// zzfy003
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 500005;
const int Size = 800;
struct ele {
  int id; ll val;
  ele (int id = 0, ll val = 0LL):
    id(id), val(val) {}
  bool operator < (const ele& b) const { // (val, id)
    if (val != b.val) return val < b.val;
    else return id < b.id;
  }
} b[N];
int be[N], L[Size], R[Size];
long long lzy[Size];
int block;
int a[N], n, q;

// binary search: low_id
int Erfen1(int l, int r, int Num) {
  while (l + 5 < r) {
    int mid = (l + r) >> 1;
    if (b[mid].val >= Num) r = mid;
    else l = mid + 1;
  }
  for (int i = l; i <= r; i++) {
    if (b[i].val == Num) return b[i].id;
  }
  return 1e9;
}

// binary search: up_id
int Erfen2(int l, int r, int Num) {
  while (l + 5 < r) {
    int mid = (l + r) >> 1;
    if (b[mid].val > Num) r = mid;
    else l = mid; 
  }
  for (int i = r; i >= l; i--) {
    if (b[i].val == Num) return b[i].id;
  }
  return -1e9;
}

void print() {
  printf(" *** block\n");
  for (int i = 1; i <= block; i++) {
    printf("for [%d, %d, lzy = %lld]: ", L[i], R[i], lzy[i]);
    for (int j = L[i]; j <= R[i]; j++)
      printf("(%d, %d)", b[j].id, b[j].val);
    putchar('\n');
  }
  putchar('\n');
  system("pause");
}

int main() {
  scanf("%d%d", &n, &q);
  block = (int)sqrt(n);
  for (int i = 1; i <= block; i++) {
    L[i] = R[i - 1] + 1;
    R[i] = i * block;
  }
  if (block * block != n) {
    block++;
    L[block] = R[block - 1] + 1;
    R[block] = n;
  }
  
  int tail = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = ele(i, (long long)a[i]);
    if (i > R[tail]) tail++;
    be[i] = tail;
  }
  
  for (int i = 1; i <= block; i++) {
    sort(b + L[i], b + R[i] + 1);
  }
  
  while (q--) {
    int opt; scanf("%d", &opt);
    if (opt == 1) { // update [l,r] += x
      int l, r, x; scanf("%d%d%d", &l, &r, &x);
      int bL = be[l], bR = be[r];
      if (bL == bR) { // the same block
        for (int i = L[bL]; i <= R[bL]; i++) {
          if (l <= b[i].id && b[i].id <= r) { // inside
            b[i].val += x;
          }
        }
        sort(b + L[bL], b + R[bL] + 1);
      }
      else { // different blocks
        for (int i = L[bL]; i <= R[bL]; i++) {
          if (l <= b[i].id && b[i].id <= r) {
            b[i].val += x;
          }
        }
        sort(b + L[bL], b + R[bL] + 1);
        for (int i = bL + 1; i <= bR - 1; i++)
          lzy[i] += x;
        for (int i = L[bR]; i <= R[bR]; i++) {
          if (l <= b[i].id && b[i].id <= r) {
            b[i].val += x;
          }
        }
        sort(b + L[bR], b + R[bR] + 1);
      }
    }
    else { // query ai = aj = x, max{j-i}
      int y; scanf("%d", &y);
      int left_id = 1e9, right_id = -1e9;
      for (int i = 1; i <= block; i++) {
        if (lzy[i] > y) continue;
        int Num = y - lzy[i];
        //printf("num %d\n", Num);
        int low_id = Erfen1(L[i], R[i], Num);
        if (left_id == 1e9 || left_id > low_id)
          left_id = low_id;
        int up_id = Erfen2(L[i], R[i], Num);
        if (right_id == -1e9 || right_id < up_id)
          right_id = up_id;
      }
      
      if (left_id == 1e9 || right_id == -1)
        puts("-1");
      else
        printf("%d\n", right_id - left_id);
    }
    
    //print();
  }
  return 0;
}