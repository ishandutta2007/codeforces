#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif


string solve(LL n, LL k) {
    if (n == 0 and k == 0) return "";
    if (k > (n-1)*n/2) return "Impossible";
    if (k <= (n-2)*(n-1)/2) return solve(n-1, k) + "()";
    LL h = (n-1)*n/2 - k;
    string res = "";
    for (LL i = 0; i < n-1; i++) res += "(";
    for (LL i = 0; i < h; i++) res += ")";
    res += "()";
    for (LL i = 0; i < n-1-h; i++) res += ")";
    return res; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    LL n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
}