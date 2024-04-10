#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

const int M=998244353;

int add(int a,int b){
        a+=b;
        if(a>=M) return a-M;
        if(a<0) return a+M;
        return a;
}

int mul(int a,int b){
        return a*(ll)b%M;
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
        return mul(a,pw(b,M-2));
}

void addup(int &a,int b){
        a=add(a,b);
}

void mulup(int &a,int b){
        a=mul(a,b);
}

int fact(int x){
        int sol=1;
        for(int i=1;i<=x;i++){
                mulup(sol,i);
        }
        return sol;
}

const int N=2000+7;
int n,k,lmul;
int dp[2*N][2*N][2];

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

        /**

        prob that is inside :

        total = (2n+1)!
        ways = aranj*n!*2^n

        **/


        cin>>n>>k>>lmul;

        dp[0][0][0]=1;

        for(int l=0;l<=2*n;l++){
                for(int op=0;op<=l;op++){
                        for(int is=0;is<=1;is++){
                                int coef=dp[l][op][is];
                                if(!coef) continue;
                                /// another one
                                addup(dp[l+1][op+1][is],coef);
                                /// close one
                                if(op>=1) addup(dp[l+1][op-1][is],mul(op,coef));
                                /// place da one
                                if(op>=k&&!is) addup(dp[l+1][op][1],coef);
                        }
                }
        }


        int aranj=dp[2*n+1][0][1];

        int ways=mul(aranj,mul(fact(n),pw(2,n)));
        int total=fact(2*n+1);
        cout<<mul(lmul,dv(ways,total))<<"\n";

}