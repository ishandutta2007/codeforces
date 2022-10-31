#include <bits/stdc++.h>
using namespace std;

long long triples[4][3][2] = {
    {
        {0, 0},
        {0, 0},
        {0, 0}
    },
    {
        {0, 1},
        {1, 0},
        {1, 1}
    },
    {
        {1, 0},
        {1, 1},
        {0, 1}
    },
    {
        {1, 1},
        {0, 1},
        {1, 0}
    }
};

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long k = ceil(n/3.0);
        long long r = n%3;
        r = (r+2)%3;
        long long kk = k-1;
        string s = "";
        while(kk-1 >= 0){
            s += to_string((kk-1)%4);
            kk = (kk-1)/4;
        }
        s += "1";
        long long ans = 0;
        for(long long i = 0; i<s.length(); i++){
            if(triples[s[i]-'0'][r][0] == 1){
                ans += pow(2, 2*i+1);
            }
            if(triples[s[i]-'0'][r][1] == 1){
                ans += pow(2, 2*i);
            }
        }
        cout << ans << endl;
    }
}