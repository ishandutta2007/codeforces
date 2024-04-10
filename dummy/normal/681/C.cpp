#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int m;
int ans[N], val[N];
priority_queue< int > pq;
char s[20];
void ins(int v) {
  ans[m] = 1;
  val[m] = v;
  pq.push(-v);
  m++;
}
void rem() {
  if(pq.empty()) {
    ans[m] = 1;
    val[m] = 0;
    m++;
  }
  else
    pq.pop();
  ans[m] = -1;
  val[m] = -1;
  m++;
}
void gett(int v) {
  while(!pq.empty() && pq.top() > -v) {
    ans[m] = -1;
    m++;
    pq.pop();
  }
  if(pq.empty() || pq.top() < -v) {
    ins(v);
  }
  ans[m] = 0;
  val[m] = v;
  m++;
}

int main() {
  int n;
  scanf("%d", &n);
  m = 0;
  while(n--) {
    scanf("%s", s);
    if(s[0] == 'r') {
      rem();
    }
    else {
      int v;
      scanf("%d", &v);
      if(s[0] == 'i')
        ins(v);
      else
        gett(v);
    }
  }
  printf("%d\n", m);
  for(int i = 0; i<m; i++) {
    if(ans[i] == -1)
      puts("removeMin");
    else if(ans[i] == 0)
      printf("getMin %d\n", val[i]);
    else
      printf("insert %d\n", val[i]);
  }

  return 0;
}