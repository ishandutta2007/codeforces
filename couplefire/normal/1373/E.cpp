#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    return (a+b)*(b-a+1)/2;
}

string construct(int b, int d, int tmp){
    string tcur = "";
    tcur += '0'+d;
    for(int i = 0; i<b; i++) tcur += '9';
    if(tmp <= 8 && tmp > 0) tcur += '0'+tmp;
    else if(tmp > 0){
        tmp -= 8;
        tcur += '8';
        while(tmp >= 9){
            tcur += '9';
            tmp -= 9;
        }
        if(tmp != 0) tcur += '0'+tmp;
    }
    reverse(tcur.begin(), tcur.end());
    return tcur;
}

bool cmp(string a, string b){
    if(b == "z") return 1;
    if(a.length() < b.length()) return 1;
    if(a.length() > b.length()) return 0;
    int i = 0;
    while(i < a.length() && a[i] == b[i]) i++;
    if(i == a.length()) return 0;
    return a[i]<b[i];
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string cur = "z";
        for(int b = 0; b<=n/9+10; b++){
            for(int d = 0; d<=9; d++){
                if(d+k < 10){
                    int tmp = n-sum(d, d+k)-(k+1)*b*9;
                    if(tmp < 0) continue;
                    if(tmp%(k+1) != 0) continue;
                    tmp /= (k+1);
                    string tcur = construct(b, d, tmp);
                    // cout << tcur << endl;
                    if(cmp(tcur, cur)) cur = tcur;
                }
                else{
                    int tmp = n-sum(d, 9)-sum(0,k+d-10)-(9-d+1)*b*9-(k+d-10+1);
                    if(tmp < 0) continue;
                    if(tmp%(k+1) != 0) continue;
                    tmp /= (k+1);
                    string tcur = construct(b, d, tmp);
                    // cout << tcur << endl;
                    if(cmp(tcur, cur)) cur = tcur;
                }
            }
        }
        if(cur == "z") cout << -1 << endl;
        else cout << cur << endl;
        // cout << endl;
    }
}