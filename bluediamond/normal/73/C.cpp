#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int score[30][30];

const int N=676+5;
const int K=100+5;
int n,k,v[N];
string a;
int dp[N][K][30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>k;
    n=a.size();
    for(int i=1;i<=n;i++) {
        v[i]=a[i-1]-'a';
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<K;j++) {
            for(int k=0;k<30;k++) {
                dp[i][j][k]=-(1<<30);
            }
        }
    }
    dp[1][0][v[1]]=0;
    for(int i=0;i<26;i++) {
        dp[1][1][i]=0;
    }
    int q;
    cin>>q;
    while(q--) {
        string x,y;
        cin>>x>>y;
        int f=x[0]-'a';
        int s=y[0]-'a';
        cin>>score[f][s];
    }
    for(int p=2;p<=n;p++) {
        for(int cate=0;cate<=k;cate++) {
            for(int x=0;x<26;x++) {
                for(int y=0;y<26;y++) {
                    if(y==v[p]) {
                        dp[p][cate][y]=max(dp[p][cate][y],dp[p-1][cate][x]+score[x][y]);
                    }
                    else {
                        dp[p][cate+1][y]=max(dp[p][cate+1][y],dp[p-1][cate][x]+score[x][y]);
                    }
                }
            }
        }
    }
    int answer=-(1<<30);
    for(int cate=0;cate<=k;cate++) {
        for(int x=0;x<26;x++) {
            answer=max(answer,dp[n][cate][x]);
        }
    }
    cout<<answer<<"\n";
    return 0;
}
/**

**/