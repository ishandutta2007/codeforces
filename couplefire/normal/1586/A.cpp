#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        int sum = 0;
        for(int i = 0; i<n; ++i)
            cin >> arr[i], sum += arr[i];
        bool isPrime = 1;
        for(int i = 2; i<sum; ++i)
            if(sum%i==0){isPrime=0; break;}
        if(!isPrime){
            cout << n << '\n';
            for(int i = 0; i<n; ++i)
                cout << i+1 << ' ';
            cout << '\n';
            continue;
        }
        int pos = -1;
        for(int i = 0; i<n; ++i)
            if(arr[i]%2){pos = i; break;}
        cout << n-1 << '\n';
        for(int i = 0; i<n; ++i)
            if(i!=pos) cout << i+1 << ' ';
        cout << '\n';
    }
}