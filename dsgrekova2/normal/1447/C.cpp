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
    int n, w;
    cin >> n >> w;
    vector<pair<int,int>> a(n);
    int t = 0;
    for(auto &i : a) {
        ++t;
        cin >> i.first;
        if(i.first > w){
            i.first = 0;
        }
        i.second = t;
    }sort(a.rbegin(), a.rend());
    int prefsum = 0;
    for (int i = 0; i < n; ++i) {
        prefsum += a[i].first;
        if(prefsum * 2 >= w){
            cout << i + 1 << endl;
            for (int j = 0; j <= i; ++j) {
                cout << a[j].second << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}