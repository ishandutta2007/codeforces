#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int N = 501;
const int M = 5001;

int dp[N][M];
pii par[N][M];

int main () {
    int d,s;
    cin >> d >> s;
    memset(dp,-1,sizeof(dp));
    par[0][0] = make_pair(0,0);
    dp[0][0] = 0;
    queue<pii> que;
    que.push(make_pair(0,0));
    while (!que.empty()) {
        pii p=que.front();
        que.pop();
        int sum = p.S;
        int mod = p.F;
        //cout << "sum = " << sum << " , mod = " << mod << endl;
        for (int i=0;i<10;++i) {
            int newsum = sum + i;
            int newmod = (mod*10+i)%d;
            if (newsum > s) continue;
            if (dp[newmod][newsum] != -1) continue;
            dp[newmod][newsum] = i;
            par[newmod][newsum] = p;
            que.push(make_pair(newmod,newsum));
        }
    }
    if (dp[0][s] == -1) cout << -1 << endl;
    else {
        string ans = "";
        int nowx = 0,nowy = s;
        while (make_pair(nowx,nowy) != make_pair(0,0)) {
            ans.push_back('0'+dp[nowx][nowy]);
            int x = par[nowx][nowy].first, y = par[nowx][nowy].second;
            //nowx = par[nowx][]
            nowx = x;
            nowy = y;
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    //cout << "1000000000000000000000000000001" << endl;
}