#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; ++i)
            cin >> arr[i];
        bool bruh = 0;
        for(int i = 0; i<n; ++i){
            bool work = 0;
            for(int j = i; j>=0; --j)
                if(arr[i]%(j+2)!=0){work = 1; break;}
            if(!work){cout << "NO" << '\n'; bruh = 1; break;}
        }
        if(!bruh) cout << "YES" << '\n';
    }
}