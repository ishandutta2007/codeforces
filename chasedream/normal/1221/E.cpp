#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...); 
}

int a, b;
string s;

void work() {
  cin >> a >> b >> s;
  int n = s.size(); s += '#';
  
  for (int i = 0; i < n; i++) {
    if (s[i] != '.' && s[i] != 'X')
      assert(0);
  }
  
  int sum = 0, len;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 0; i <= n; i++) {
    if (s[i] == '.') sum++;
    else {
      if (sum >= b) {
        if (sum < a) cnt0++;
        else if (sum >= 2 * b) cnt2++, len = sum;
        else cnt1++;
      }
      sum = 0;
    }
  }
  
  if (cnt0 > 0 || cnt2 >= 2)
    puts("NO");
  else { // cnt0 = 0
    if (cnt2 == 0)
      puts(cnt1 & 1 ? "YES" : "NO");
    else {
      if (2 * b <= a) {
        assert(cnt1 == 0);
        if (len <= a + 2 * (b - 1))
          puts("YES");
        else
          puts("NO");
      }
      else {
        if (cnt1 & 1) {
          if (len >= 2 * a && len <= a + (2 * b - 1) + (b - 1))
            puts("YES");
          else
            puts("NO"); 
        }
        else {
          if (len <= a + 2 * (b - 1) || (len >= 3 * a && len <= a + 2 * (2 * b - 1)))
            puts("YES");
          else
            puts("NO");
        } 
      }
    }      
  }
}

int main() {
  //ios :: sync_with_stdio(false); cin.tie(0);
  int T; read(T);
  while (T--) work();
  return 0;
}

/*
At first, let's transform input to a more convenient form. We consider only such subsegments that consist of the symbols . and which cannot be expanded to the right or left. For example, for s=XX...X.X...X.. we consider segments of length 3, 1, 3, and 2.

Let's divide all such segments into four groups by their length len:

len<b;
blen<a;
alen<2b;
len2b.
In such a division, each segment belongs to exactly one type.

Suppose that the Bob takes the first turn. If there is a segment of second type, then Bob wins, because he always have a spare turn that Alice cannot make. If there is a segment of fourth type then the Bob also wins because he can make the segment of second type by taking turn in this segment of four type. If there are no segments of second and four types, then victory depends on the parity of the number of segments of the third type.

But it is true if the Bob takes first turn. If Alice takes first turn then she doesn't want, after her move, there are segments of the second and fourth types. So if initially there is a segment of second type then Alice loses because she can't take turns into segment of second type. If there are two or more segments of four type then Alice also loses, because after her turn at least one such segments remains. If there are only one segment of four type then Alice have to take turn into this segment. Since the length of this segment doesn't exceed n, we can iterate over all possible Alice moves. After Alice's move segment of fourth type can be divided into no more than two new segments, let's denote their types as t1 and t2. If at least one of these segments of second or fourth type, then it's bad turn for Alice. Otherwise Alice win if remaining number of segment of third type is even (note that t1 or t2 also can be the third type). And finally, if initially there are only segments of first or third type, then victory depends on the parity of the number of segments of the third type.
*/