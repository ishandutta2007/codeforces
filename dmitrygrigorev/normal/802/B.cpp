#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
 
 
using namespace std;
 
 
int inf = 1e9;
long long big_inf = 1e18;
 
 
int last[400228];
int right1[400228];
 
 
int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
 
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
 
    for (int i = 0; i < 400228; ++i){
        last[i] = inf;
    }
 
    for (int i = n - 1; i >= 0; --i){
        right1[i] = last[a[i]];
        last[a[i]] = i;
    }
 
 
    set <int> s1;
    set <pair <int, int> > s2;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (s1.find(a[i]) != s1.end()){
            s2.erase({ -i, a[i] });
            s2.insert({ -right1[i], a[i] });
        }
 
 
        if (s1.find(a[i]) == s1.end()){
            if (s1.size() < k){
                s1.insert(a[i]);
                s2.insert({ -right1[i], a[i] });
                ++ans;
            }
            else {
                pair <int, int> e = *s2.begin();
                s1.erase(e.second);
                s2.erase(e);
                ++ans;
                s1.insert(a[i]);
                s2.insert({ -right1[i], a[i] });
            }
        }
    }
 
    cout << ans;
    return 0;
}