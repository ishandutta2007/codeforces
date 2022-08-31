#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    int m;
    cin >> m;
    int q[m][2];
    for (int i=0; i < m; i++){
        for (int j=0; j < 2; j++){
            cin >> q[i][j];
        }
    }
    int K = (1 << 11) - 2;
    bool dp[n+m][K];
    vector<string> pal, st;
    for (int i=0; i < n+m; i++){
        for (int j=0; j < K; j++){
            dp[i][j] = false;
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < v[i].size(); j++){
            for (int k=j; k - j <= 9; k++){
                if (k >= v[i].size()) break;
                int num = 0;
                for (int p=k; p >= j; p--){
                    num += (1 << (k - p)) * (v[i][p] - '0');
                }
                num += (1 << (k - j + 1)) - 2;
                dp[i][num] = true;
            }
        }
        string kon = "";
        string start = "";
        if (v[i].size() <= 9){
            start = v[i];
            kon = v[i];
        }
        else{
            for (int j=9; j >= 1; j--){
                kon += v[i][v[i].size() - j];
                start += v[i][9-j];
            }
        }
        st.push_back(start);
        pal.push_back(kon);
    }
    for (int i=0; i < m; i++){
        int first = q[i][0] - 1;
        int second = q[i][1] - 1;
        for (int j=0; j < K; j++){
            dp[i+n][j] = dp[first][j] | dp[second][j];
        }
        string conc = pal[first] + st[second];
        for (int j=0; j < conc.size(); j++){
            for (int k=j; k - j <= 9; k++){
                if (k >= conc.size()) break;
                int num = 0;
                for (int p=k; p >= j; p--){
                    num += (1 << (k - p)) * (conc[p] - '0');
                }
                num += (1 << (k - j + 1)) - 2;
                dp[i+n][num] = true;
            }
        }
        string newf = st[first];
        int u = 0;
        while (newf.size() < 9 && u < st[second].size()){
            newf += st[second][u];
            u++;
        }
        string newe = pal[second];
        u = pal[first].size() - 1;
        while (newe.size() < 9 && u >= 0){
            string help = pal[first][u] + newe;
            newe = help;
            u--;
        }
        pal.push_back(newe);
        st.push_back(newf);
        int ans = K;
        for (int j=0; j < K; j++){
            if (!dp[i+n][j]){
                ans = j;
                break;
            }
        }
        int sc = 0;
        int answer = 0;
        for (int j=1; j <= 10; j++){
            sc += (1 << j);
            if (ans < sc) break;
            answer++;
        }
        cout << answer << endl;
    }
    return 0;
}