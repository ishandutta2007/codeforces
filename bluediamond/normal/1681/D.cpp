#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int get_length(int x) {
  if (x<=9) return 1;
  return 1+get_length(x/10);
}

vector<int> get_digits(int x) {
  vector<int> sol;
  while (x) {
    sol.push_back(x%10);
    x/=10;
  }
  return sol;
}


const int inf=(int)1e9+7;
time_t bg,nd;
int cnt, sol=inf, len, ptr=1;
bool done;

void bkt(int x, int current) {
  if (done) {
    return;
  }
  int in_my_mind=current, cop=x;
  while (cop<ptr) {
    cop*=9;
    in_my_mind++;
  }
  if (in_my_mind>=sol) {
    return;
  }
  if (current>=sol) {
    return;
  }

  cnt++;
  if (cnt>=1000) {
    cnt=0;
    nd=clock();
    double tt=(double)(nd-bg)/CLOCKS_PER_SEC;
    if (tt>=1.8) {
      done=1;
      return;
    }
  }
  int me=get_length(x);
  assert(me<=len);
  if (me==len) {
    assert(current < sol);
    sol=current;
    return;
  }
  vector<int> digits=get_digits(x);
  sort(digits.begin(),digits.end());
  digits.resize(unique(digits.begin(), digits.end()) - digits.begin());
  for (int p = (int) digits.size() - 1; p >= 0 && digits[p] >= 2; p--) {
    bkt(x * digits[p], current + 1);
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE
  bg=clock();

  int x;
  cin>>len>>x;
  for (int i=1;i<len;i++) {
    ptr*=10;
  }
  bkt(x, 0);
  if (sol==inf) {
    sol=-1;
  }
  cout<<sol<<"\n";

}