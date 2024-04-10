//https://codeforces.com/problemset/problem/1254/A

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){
    //freopen("a.in", "r", stdin);
    int t; cin >> t;
    vector<char> dumb;
    for(int i = '0'; i<='9'; i++) dumb.push_back(i);
    for(int i = 'A'; i<='Z'; i++) dumb.push_back(i);
    for(int i = 'a'; i<='z'; i++) dumb.push_back(i);
    while(t--){
        int r, c, k; cin >> r >> c >> k;
        int grid[r][c];
        int num = 0;
        int cur = 0;
        for(int i = 0; i<r; i++){
            string s; cin >> s;
            for(int j = 0; j<c; j++){
                if(s[j] == '.') grid[i][j] = 0;
                else grid[i][j] = 1;
                num += grid[i][j];
            }
        }
        int ave = num/k;
        --k; num -= ave;
        int csum = 0;
        if(k == 0) csum = -INF;
        for(int i = 0; i<r; i++){
            if(i % 2 == 0){
                for(int j = 0; j<c; j++){
                    csum += grid[i][j];
                    grid[i][j] = (int) dumb[cur];
                    if(csum == ave){
                        cur++;
                        if(k == 0) ave = num;
                        else ave = num/k;
                        num -= ave;
                        --k;
                        if(k == 0) csum = -INF;
                        else csum = 0;
                    }
                }
            }
            else{
                for(int j = c-1; j>=0; j--){
                    csum += grid[i][j];
                    grid[i][j] = (int) dumb[cur];
                    if(csum == ave){
                        cur++;
                        if(k == 0) ave = num;
                        else ave = num/k;
                        num -= ave;
                        --k;
                        if(k == 0) csum = -INF;
                        else csum = 0;
                    }
                }
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cout << (char) grid[i][j];
            }
            cout << endl;
        }
    }
}