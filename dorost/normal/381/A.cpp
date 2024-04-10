#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, a;
    cin >> n;
    deque <int> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.push_back(a);
    }
    int ans[2] = {};
    for(int i = 0; i < n; i++){
        if (s.back() > s.front()){
            ans[i % 2] += s.back();
            s.pop_back();
        }else {
            ans[i % 2] += s.front();
            s.pop_front();
        }
    }
    cout << ans[0] << ' ' << ans[1];
}