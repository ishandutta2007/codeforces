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
using namespace std;

void PolnalyubviTop(){
    int n;
    cin >> n;
    map<int, int> ans;
    map<int, bool> b;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
        if(b[a[i]] == 0){
            ans[a[i]] = 1;
            b[a[i]] = 1;
        }
        if(i == 0)
            ans[a[i]]--;
        if(i != n - 1 and a[i+1] != a[i])
            ans[a[i]]++;
    }
    int x = n;
    for(auto i : ans)
        x = min(x, i.second);
    cout << x << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}