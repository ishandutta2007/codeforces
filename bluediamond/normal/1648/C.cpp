#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

void addup(int &a,int b){
        a=add(a,b);
}

void mulup(int &a,int b){
        a=mul(a,b);
}

const int N=(int)2e5+7;
int my,n,vec[N],f[N],mx,fact[N],ifact[N],ft[N];

void add_tree(int a,int x){
        while(a<N){
                ft[a]+=x;
                a+=a&(-a);
        }
}

int get(int a){
        int sl=0;
        while(a){
                sl+=ft[a];
                a-=a&(-a);
        }
        return sl;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

     ///   freopen ("___input___","r",stdin);


        fact[0]=1;
        for(int i=1;i<N;i++){
                fact[i]=mul(fact[i-1],i);
        }
        ifact[N-1]=dv(1,fact[N-1]);
        for(int i=N-2;i>=0;i--){
                ifact[i]=mul(ifact[i+1],i+1);
        }
        /**for(int i=0;i<10;i++){
                cout<<i<< ": "<<fact[i]<<" "<<ifact[i]<<" and "<<mul(fact[i],ifact[i])<<"\n";
        }
        return 0;**/

        cin>>my>>n;
        for(int i=1;i<=my;i++){
                int x;
                cin>>x;
                f[x]++;
                mx=max(mx,x);
                add_tree(x,1);
        }
        for(int i=1;i<=n;i++){
                cin>>vec[i];
        }

        int rem=my;

        int print=0;

        int total=1;

        for(int j=1;j<=mx;j++){
                mulup(total,ifact[f[j]]);
        }


        for(int com=0;com<n;com++){
                if(com>=1){
                        if(f[vec[com]]==0) break;
                        mulup(total,fact[f[vec[com]]]);
                        f[vec[com]]--;
                        mulup(total,ifact[f[vec[com]]]);
                        assert(f[vec[com]]>=0);
                        rem--;
                        add_tree(vec[com],-1);
                }
                rem--;
                int limit=vec[com+1]-1;

                int sol=0;



                sol=get(limit);
                mulup(sol,total);
                mulup(sol,fact[rem]);
                addup(print,sol);
                rem++;
        }

        if(my!=n){
                addup(print,+1);
                for(int i=1;i<=mx;i++){
                        if(f[i]!=0){
                                addup(print,-1);
                                break;
                        }
                }
        }
        cout<<print<<"\n";

}