#include <bits/stdc++.h>

bool home=1;
using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

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


class modMatrix {
public:
  int n;
  int m;
  int mod;
  vector<vector<int>> a;

  modMatrix(int _n, int _m, int _mod) {
    n = _n;
    m = _m;
    mod = _mod;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0);
    }
  }
  modMatrix operator * (modMatrix b) {
    if (mod != b.mod) {
      cout << "error the mods do not correspond (when wanting to multiply)\n";
      exit(0);
    }
    if (m != b.n) {
      cout << "error on (mod) matrix sizes (when wanting to multiply)\n";
      exit(0);
    }
    modMatrix c(n, m, mod);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] = (c.a[i][j] + (long long) a[i][k] * b.a[k][j]) % mod;
        }
      }
    }
    return c;
  }
  modMatrix operator ^ (long long p) {
    if (n != m) {
      cout << "error on (mod) matrix size (when wanting to rise to the power)\n";
      exit(0);
    }
    modMatrix c(n, m, mod), cur(n, m, mod);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      c.a[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        c = c * cur;
      }
      cur = cur * cur;
      p /= 2;
    }
    return c;
  }
};

int dr[]={-1,0,1,0},dc[]={0,1,0,-1};


signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }

  int n,m,q;
  cin>>n>>m>>q;
  modMatrix mtr(1,n*m,M);
  mtr.a[0][0]=1;

  modMatrix mlt(n*m,n*m,M);
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      mlt.a[i*m+j][i*m+j]=1;
      for(int k=0;k<4;k++){
        int r=i+dr[k],c=j+dc[k];
        if(0<=r&&0<=c&&r<n&&c<m){
          mlt.a[i*m+j][r*m+c]=1;
        }
      }
    }
  }

  int curt=1;
  function<void(int)> grow_to=[&](int what){
    assert(curt<=what);
    mtr=mtr*(mlt^(what-curt));
    curt=what;
  };

  for (int iq=1;iq<=q;iq++){
    int type,x,y,t;
    cin>>type>>x>>y>>t;
    x--;
    y--;
    assert(0<=x&&x<n);
    assert(0<=y&&y<m);

    assert(1<=type&&type<=3);

    assert(curt<=t);

    if(type==1){
      grow_to(t);
      cout<<mtr.a[0][x*m+y]<<"\n";
    }
    if(type==2){
      grow_to(t);
      mtr.a[0][x*m+y]=0;
      int i=x,j=y;
      for (int k=0;k<4;k++){
        int r=i+dr[k],c=j+dc[k];
        if(0<=r&&0<=c&&r<n&&c<m){
          mlt.a[r*m+c][i*m+j]=0;
        }
      }
    }
    if(type==3){
      grow_to(t);
      int i=x,j=y;
      for (int k=0;k<4;k++){
        int r=i+dr[k],c=j+dc[k];
        if(0<=r&&0<=c&&r<n&&c<m){
          mlt.a[r*m+c][i*m+j]=1;
        }
      }
      grow_to(t);
    }

  }
}