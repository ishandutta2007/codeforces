#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int get(int i){
    cout << "? " << i+1 << endl;
    cout.flush();
    int a; cin >> a;
    int b;
    if(i == 0) b = INF;
    else{
        cout << "? " << i << endl;
        cout.flush();
        cin >> b;
    }
    return b-a;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    if(n == 1){
        cout << "! " << 1 << endl;
        cout.flush();
        return 0;
    }
    if(get(1) < 0){
        cout << "! " << 1 << endl;
        cout.flush();
        return 0;
    }
    if(get(n-1) > 0){
        cout << "! " << n << endl;
        cout.flush();
        return 0;
    }
    int lo = 0, hi = n-1;
    while(lo < hi){
        int mid = lo+(hi-lo)/2;
        if(get(mid) > 0) lo = mid+1;
        else hi = mid;
    }
    cout << "! " << lo << endl;
    cout.flush();
}