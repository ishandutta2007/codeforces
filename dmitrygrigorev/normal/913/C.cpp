#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> pr;
int solve(int x){
    if (x == 0) return 0;
    int i = 0;
    while (true){
        if ((1LL << i) > x) break;
        i++;
    }
    int sz = pr.size();
    int j = i-1;
    int can = pr[j];
    int P = 3e18;
    for (int k=i; k < pr.size(); k++){
        if (pr[k] < P){
            P = pr[k];
        }
    }
    return min(can + solve(x - (1LL << j)), P);
}
int32_t main(){
    int n, l;
    cin >> n >> l;
    for (int i=0; i < n; i++){
        int A;
        cin >> A;
        pr.push_back(A);
    }
    for (int i=1; i < n; i++){
        pr[i] = min(pr[i], 2*pr[i-1]);
    }
    while (pr.size() < 32){
        pr.push_back(pr.back() * 2);
    }
    cout << solve(l);
    return 0;
}