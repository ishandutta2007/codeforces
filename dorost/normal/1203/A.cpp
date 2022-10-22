#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        deque <int> a;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        bool f = false;
        for (int i = 0; i < n * n; i++){
            a.push_front(a[n - 1]);
            a.pop_back();
            if (is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend())){
                f = true;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}