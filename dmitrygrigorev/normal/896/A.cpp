#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
int INF = 2e18;
signed main(){
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string f1 = "What are you doing while sending *";
    string f2 = "*? Are you busy? Will you send *";
    string f3 = "*?";
    vector<int> res;
    res.push_back(f0.size());
    while (true){
        int R = res.back();
        int X = 2*R + f1.size() + f2.size() + f3.size();
        res.push_back(X);
        if (X >= INF) break;
    }
    int q;
    cin >> q;
    string answer = "";
    for (int i=0; i < q; i++){
        int n, k;
        cin >> n >> k;
        k--;
        if (n < res.size()){
            if (k >= res[n]){
                answer += ".";
                continue;
            }
        }
        bool ans = false;
        while (n > 0){
            int F = f1.size();
            if (k < f1.size()){
                answer += f1[k];
                ans = true;
                break;
            }
            k -= f1.size();
            if (n-1 >= res.size()){
                n--;
                continue;
            }
            if (k < res[n-1]){
                n--;
                continue;
            }
            k -= res[n-1];
            if (k < f2.size()){
                answer += f2[k];
                ans = true;
                break;
            }
            k -= f2.size();
            if (n-1 >= res.size()){
                n--;
                continue;
            }
            if (k < res[n-1]){
                n--;
                continue;
            }
            k -= res[n-1];
            answer += f3[k];
            ans = true;
            break;
        }
        if (!ans){
            answer += f0[k];
        }
    }
    char CH = '"';
    for (int i=0; i < q; i++){
        if (answer[i] != '*') cout << answer[i];
        else cout << CH;
    }
    return 0;
}