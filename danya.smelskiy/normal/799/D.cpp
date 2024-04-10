#include <bits/stdc++.h>
using namespace std;

long long a,b,z,x,y,n,c[100005];
bool dp[35][100001];
long long q=-1;


inline bool chek(long long xx,long long yy){
    return ((xx*x>=a && yy*y>=b) || (xx*y>=a && yy*x>=b) || (xx*x>=b && yy*y>=a) || (xx*y>=b && yy*x>=b));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>x>>y>>n;
    if (a>b) swap(a,b);
    if (x>y) swap(x,y);
    if (chek(1,1)) {
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=n;++i)
        cin>>c[i];
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);
    long long last=1;
    n=min(n,(long long)34);
    dp[0][1]=true;
    for (int i=1;i<=n;++i) {
        last*=c[i];
        for (int j=1;j<=1e5;++j) {
            if (dp[i-1][j]==true) {
                z=j*c[i];
                if (z<=1e5) dp[i][z]=true;
                else {
                    if (q==-1 || q>z) q=z;
                }
            }
        }
        for (int j=1;j<=1e5;++j) {
            if (dp[i-1][j]) dp[i][j]=true;
            if (dp[i][j]==true) {
                if (chek(j,last/j)) {
                    cout<<i;
                    return 0;
                }
            }
        }
        if (q!=-1) {
            if (chek(q,last/q)) {
                cout<<i;
                return 0;
            }
        }
    }
    cout<<"-1";
}