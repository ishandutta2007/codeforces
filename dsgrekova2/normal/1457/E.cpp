#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

void PolnalyubviTop(){
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> a(n, 0);
    int sum = 0, coefsum = 0;
    for(auto &i : a)
        cin >> i;
    sort(all(a));
    for(int i = 0; i < n; ++i){
        if(i != 0)
            sum += a[i];
        coefsum += a[i] * i;
    }
    int ans = coefsum;
    int ansnow = 0;
    for (int i = 1; i < n; ++i) {
        int t = i / k;
        ansnow += t * a[i];
        if(t == (i - 1) / k){
            coefsum -= sum;
        }
        sum -= a[i];
        coefsum -= t * a[i];
        ans = max(ans, coefsum + ansnow);
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    PolnalyubviTop();
}