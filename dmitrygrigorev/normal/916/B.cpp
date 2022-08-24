#include <bits/stdc++.h>
#define int long long
using namespace std;
const int G = 200000;
const int H = 199939;
signed main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> bit(G);
    fill(bit.begin(), bit.end(), 0);
    for (int i=0; i < 61; i++){
        int ba = n & (1LL << i);
        if (ba != 0){
            bit[H+i] = 1;
            k--;
        }
    }
    if (k < 0){
        cout << "No" << endl;
        return 0;
    }
    for (int i=G-1; i > 0; i--){
        if (bit[i] > k) break;
        bit[i-1] += 2*bit[i];
        k -= bit[i];
        bit[i] = 0;
    }
    priority_queue<int> P;
    for (int i=0; i < G; i++){
        for (int j=0; j < bit[i]; j++) P.push(-i);
    }
    for (int i=0; i < k; i++){
        int A = -P.top();
        bit[A]--;
        bit[A-1]+=2;
        P.pop();
        P.push(-A+1);
        P.push(-A+1);
    }
    cout << "Yes" << endl;
    for (int i=G-1; i >= 0; i--){
        while  (bit[i] > 0){
            bit[i]--;
            cout << i-H << " ";
        }
    }
    return 0;
}