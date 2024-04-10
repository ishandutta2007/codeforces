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
    int p = 0;
    int time = 0;
    int target = 0;
    int ans = 0;
    vector<pair<int, int>> qest(n);
    vector<pair<int, int>> seg(n + 1);
    for (int i = 0; i < n; ++i) {
        int newt, newtarget;
        cin >> newt >> newtarget;
        qest[i] = {newt, newtarget};
        int run = newt - time;
        seg[i] = {p, p};
        if(target > p)
            p = min(target, p + run);
        else
            p = max(target, p - run);
        time = newt;
        if(target == p){
            target = newtarget;
        }
        seg[i] ={min(seg[i].first, p), max(seg[i].first, p)};
    }
    seg[n] = {min(p, target), max(p, target)};
    for (int i = 0; i < n; ++i) {
        int q = qest[i].second;
        //cout << q << ' ' << seg[i + 1].first << ' ' << seg[i + 1].second << endl;
        if(seg[i + 1].first <= q and seg[i + 1].second >= q)
            ans++;
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}