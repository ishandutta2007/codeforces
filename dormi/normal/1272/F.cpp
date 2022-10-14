#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
pair<int,pair<pair<pii,int>,char>> dp[201][201][401];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<=sz(a);i++){
        for(int j=0;j<=sz(b);j++){
            for(int k=0;k<401;k++) {
                if (pair<pii,int>{{i, j}, k} != pair<pii,int>{{0, 0}, 0}) {
                    dp[i][j][k] = {801, {{{-1, -1}, -1}, '-'}};
                    if (k != 400) {
                        for (int m = 0; m <= (a[i - 1] == ')' ? 1 : 0); m++) {
                            for (int n = 0; n <= (b[j - 1] == ')' ? 1 : 0); n++) {
                                if ((m||n)&&i >= m && j >= n)
                                    if (dp[i - m][j - n][k + 1].first + 1 < dp[i][j][k].first) {
                                        dp[i][j][k] = {dp[i - m][j - n][k + 1].first + 1,
                                                       {{{i - m, j - n}, k + 1}, ')'}};
                                    }
                            }
                        }
                    }
                    if (k) {
                        for (int m = 0; m <= (a[i - 1] == '(' ? 1 : 0); m++) {
                            for (int n = 0; n <= (b[j - 1] == '(' ? 1 : 0); n++) {
                                if ((m||n)&&i >= m && j >= n)
                                    if (dp[i - m][j - n][k - 1].first + 1 < dp[i][j][k].first) {
                                        dp[i][j][k] = {dp[i - m][j - n][k - 1].first + 1,
                                                       {{{i - m, j - n}, k - 1}, '('}};
                                    }
                            }
                        }
                    }
                }
            }
            for (int k = 1; k < 401; k++) {
                if (dp[i][j][k - 1].first + 1 < dp[i][j][k].first) {
                    dp[i][j][k] = {dp[i][j][k - 1].first + 1, {{{i, j}, k - 1}, '('}};
                }
            }
        }
    }
    int mi=801,loc=-1;
    for(int k=0;k<401;k++){
        if(dp[sz(a)][sz(b)][k].first+k<mi){
            mi=dp[sz(a)][sz(b)][k].first+k;
            loc=k;
        }
    }
    vector<char> ans;
    for(int i=0;i<loc;i++)ans.push_back(')');
    pair<pii,int> cur={{sz(a),sz(b)},loc};
    while(cur!=pair<pii,int>{{0,0},0}){
        ans.push_back(dp[cur.first.first][cur.first.second][cur.second].second.second);
        cur=dp[cur.first.first][cur.first.second][cur.second].second.first;
    }
    reverse(ans.begin(),ans.end());
    for(char x:ans)printf("%c",x);
    return 0;
}