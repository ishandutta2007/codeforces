#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

const int MOD=(int)1e9+7;

int add(int a,int b){
        a+=b;
        if(a>=MOD) return a-MOD;
        if(a<0) return a+MOD;
        return a;
}

int mul(int a,int b){
        return a*(ll)b%MOD;
}

int pw(int a,int b){
        int r=1;
        while(b){
                if(b&1) r=mul(r,a);
                a=mul(a,a);
                b/=2;
        }
        return r;
}

int dv(int a,int b){
        return mul(a,pw(b,MOD-2));
}

void addup(int &a,int b){
        a=add(a,b);
}

void mulup(int &a,int b){
        a=mul(a,b);
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


const int N=(int)1e5+7;
const int K=12;
const int M=4;
int n,k,m,kol[1<<M],ttl,id[K+1][1<<M],inds;

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif

        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        for(int i=1;i<(1<<M);i++){
                int j=i&(-i);
                kol[i]=1+kol[i-j];
        }





        cin>>n>>k>>m;

        for(int i=0;i<=k;i++){
                for(int mask=0;mask<(1<<m);mask++){
                        id[i][mask]=inds++;
                }
        }
        modMatrix mlt(inds,inds,MOD),yes(1,inds,MOD);

        ttl=(1<<m)-1;
        for(int i=0;i<=k;i++){
                for(int mask=0;mask<(1<<m);mask++){
                        /// don't do anything
                        {

                                int old=id[i][mask];
                                int nw=id[i][(mask*2)&ttl];
                                mlt.a[old][nw]=1;
                        }

                        /// place it somewhere
                        if(i+1<=k){
                                int ways=1+kol[mask];
                                int old=id[i][mask];
                                int nw=id[i+1][(1+mask*2)&ttl];
                                mlt.a[old][nw]=ways;
                        }
                }
        }

        yes.a[0][id[0][0]]=1;
        yes=yes*(mlt^n);
        int sol=0;
        for(int mask=0;mask<(1<<m);mask++){
                addup(sol,yes.a[0][id[k][mask]]);
        }
        cout<<sol<<"\n";
}