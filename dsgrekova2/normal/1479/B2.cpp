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
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<vector<int>> nums(n + 1);
    for (int i = 0; i < n; ++i) {
        nums[a[i]].push_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        nums[i].push_back(n + 10);
        reverse(all(nums[i]));
    }
    int res = 0;
    int n1 = 0, n2 = 0;
    for (int i = 0; i < n; ++i) {
        nums[a[i]].pop_back();
        if (a[i] == n1 or a[i] == n2)
            continue;
        if (nums[n1].back() > nums[n2].back()){
            n1 = a[i];
        } else{
            n2 = a[i];
        }
        res++;
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    n = 1;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}