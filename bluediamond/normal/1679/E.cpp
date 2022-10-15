#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a,int b) {
  a=add(a,b);
}

void mulup(int &a,int b) {
  a=mul(a,b);
}

int n,total=0,totalqs=0;
string s;
vector<int> offs[1<<17];

void expand(int l, int r,int cnt,int mask) {
  if (l<0||r>=n) return;
  if (s[l]!='?'&&s[r]!='?'&&s[l]!=s[r]) return;
  cnt+=(s[l]=='?'&&s[r]=='?'&&l!=r);
  if (s[l]!='?' && s[r]=='?') cnt++;
  if (s[l]=='?' && s[r]!='?') cnt++;
  if (s[l]!='?'&&s[r]=='?') mask|=(1<<(s[l]-'a'));
  if (s[r]!='?'&&s[l]=='?') mask|=(1<<(s[r]-'a'));
  offs[mask].push_back(totalqs-cnt);
  expand(l-1,r+1,cnt,mask);
}

int solution[19][1<<17];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  cin>>n>>s;
  assert((int)s.size()==n);

  for (int i=0;i<n;i++) {
    totalqs+=(s[i]=='?');
  }
  for (int i=0;i<n;i++) {
    expand(i,i,0,0);
  }

  for (int i=0;i+1<n;i++) {
    expand(i,i+1,0,0);
  }
  for (int x=1;x<=17;x++) {
    for (int mask=0;mask<(1<<17);mask++) {
      for (auto &k:offs[mask]) {
        addup(solution[x][mask], pw(x,k));
      }
    }
    for (int bit=0;bit<17;bit++) {
      for (int mask=0;mask<(1<<17);mask++) {
        if (mask&(1<<bit)) {
          addup(solution[x][mask],solution[x][mask-(1<<bit)]);
        }
      }
    }
  }

  int Q;
  cin>>Q;
  while(Q--) {
    string t;
    cin>>t;
    int mask=0;
    for (auto &ch:t) {
      mask|=(1<<(ch-'a'));
    }
    cout<<solution[__builtin_popcount(mask)][mask]<<"\n";
  }



  return 0;
}