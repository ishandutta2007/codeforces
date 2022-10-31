#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    long long combo[50][50];
    for(long long i = 0; i<50; i++){
        combo[i][0] = 1;
        combo[i][i] = 1;
        for(long long j = 1; j<i; j++){
            combo[i][j] = combo[i-1][j-1]+combo[i-1][j];
        }
    }
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        map<long long, long long, greater<>> mp;
        long long cur = 2;
        while(n > 0){
            long long r = n % cur;
            mp[r]++;
            n /= cur++;
        }
        long long temp = --cur;
        long long ans = 1;
        bool later = true;
        for(auto i : mp){
            if(i.first >= 1) ans *= combo[cur-i.first][i.second];
            else ans *= combo[cur-i.first-1][i.second];
            if(i.first != 0 && (cur-i.first) == i.second) later = false;
            cur-=i.second;
        }
        //cout << later << endl;
        if(mp.count(0) && later){
            long long ta = 1;
            for(auto i : mp){
                if(i.first >= 1) ta *= combo[temp-i.first-1][i.second];
                else ta *= combo[temp-i.first-2][i.second-1];
                temp-=i.second;
            }
            //cout << ta << endl;
            ans -= ta;
        }
        cout << --ans << endl;
    } 
}