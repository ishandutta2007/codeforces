#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int r;
  int c;
};

bool operator < (T a,T b) {
  if (a.c==b.c) return a.r<b.r;
  else return a.c<b.c;
}

int n;

const int N=(int) 1e6+7;
bool ok[N][4];
bool lib[N][2];
int ocup[N];

bool good(vector<T> v) {
  int l=v[n-1].c;
  for (int i=1;i<=l;i++) {
    for (int j=0;j<4;j++) ok[i][j]=0;
    lib[i][0]=lib[i][1]=1;
    ocup[i]=0;
  }
  for (auto &it : v) {
    lib[it.c][it.r]=0;
    ocup[it.c]+=(1<<it.r);
  }
  ok[0][0]=1;
  for (int i=0;i<=l;i++) {
    if (ok[i][0]) ok[i][3]=1;
    if (ok[i][3]) ok[i+1][ocup[i+1]]=1;
    if (ok[i][1]) {
      if (lib[i+1][1]) ok[i+1][ocup[i+1]+(1<<1)]=1;
    }
    if (ok[i][2]) {
      if (lib[i+1][0]) ok[i+1][ocup[i+1]+(1<<0)]=1;
    }
  }
  return ok[l][3];
}

int solve() {
  int l;
  cin>>l>>n;
  vector<T> v;
  v.resize(n);
  for (auto &x : v) {
    cin>>x.r>>x.c;
    x.r--;
  }
  sort(v.begin(),v.end());
  vector<T> v2(n);
  v2[0] = {v[0].r,v[0].c%2+1};
  for (int i=1;i<(int)v.size();i++) {
    if (v[i-1].c==v[i].c) {
      v2[i]={v[i].r,v2[i-1].c};
    } else {
      int dif=v[i].c-v[i-1].c;
      if (dif%2==0) dif=2;
      else dif=1;
      v2[i]={v[i].r,v2[i-1].c+dif};
    }
  }
  return good(v2);
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--) {
    int x=solve();
    if (x==1) {
      cout << "YES\n";
      continue;
    }
    if (x==0) {
      cout << "NO\n";
      continue;
    }
    cout << "???\n";
  }

}