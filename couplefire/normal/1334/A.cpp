#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> pre = {0, 0};
        bool work = true;
        for(int i = 0; i<n; i++){
            int a, b; cin >> a >> b;
            if(work && (a-pre.first < b-pre.second || a < pre.first || b < pre.second)){
                cout << "NO" << endl;
                work = false;
            }
            pre = {a, b};
        }
        if(work){
            cout << "YES" << endl;
        }
    }
}