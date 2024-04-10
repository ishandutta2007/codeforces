#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int MOD=1e9+7;

inline int add(int a,int b) {
    a+=b;
    if(a<0) a+=MOD;
    if(a>=MOD) a-=MOD;
    return a;
}

inline int mul(int a,int b) {
    return (a*(ll)b)%MOD;
}

inline int expow(int a,int b) {
    int ans=1;
    while(b) {
        if(b%2==1)
            ans=mul(ans,a);
        a=mul(a,a);
        b/=2;
    }
    return ans;
}

inline int Div(int a,int b) {
    return mul(a,expow(b,MOD-2));
}

const int N=3000;
int n,d;
int dp[N+5][N+5];
int sum[N+5];
vector<int>v[N+5];

void dfs(int nod) {
    if(v[nod].size()==0) {
        for(int j=1;j<=n;j++)
            dp[nod][j]=1;
    }
    else {
        for(auto nou:v[nod])
            dfs(nou);
        for(int cnt=1;cnt<=n;cnt++) {
            int kek=1;
            for(auto nou:v[nod]) {
                sum[nou]=add(sum[nou],dp[nou][cnt]);
                kek=mul(kek,sum[nou]);
            }
            dp[nod][cnt]=kek;
        }
    }
}

int val[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>d;
    for(int i=2;i<=n;i++) {
        int t;
        cin>>t;
        v[t].push_back(i);
    }
    dfs(1);
    for(int cnt=1;cnt<=n;cnt++)
        val[cnt]=add(val[cnt-1],dp[1][cnt]);
    int ans=0;
    for(int i=0;i<=n;i++) {
        int sus=val[i];
        int jos=1;
        for(int j=0;j<=n;j++)
            if(i!=j) {
                sus=mul(sus,d-j);
                jos=mul(jos,add(i,-j));
            }
        ans=add(ans,Div(sus,jos));
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/