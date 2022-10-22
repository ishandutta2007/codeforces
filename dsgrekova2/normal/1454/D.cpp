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
pair<int, int> mxstep(int n){
    pair<int, int> res = {0, 1};
    for (int i = 2; i * i <= n; ++i) {
        int k = 0;
        while(n % i == 0){
            k++;
            n /= i;
        }
        if(k > res.first)
            res = {k, i};
    }
    if(n != 1 and res.first == 0)
        res = {1, n};
    return res;
}
void PolnalyubviTop(){
    int n;
    cin >> n;
    pair<int, int> a = mxstep(n);
    vector<int> ans;
    for (int i = 1; i <= a.first; ++i) {
        if(i != a.first){
            ans.push_back(a.second);
            n /= a.second;
        }else{
            ans.push_back(n);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << ' ';
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}