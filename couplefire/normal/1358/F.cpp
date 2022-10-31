#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200000

int n;
int arr[MAXN], brr[MAXN];

void special(){
    int cursum = 0;
    for(int i = 0; i<n; i++) cursum += brr[i] - arr[i];
    int cnt = 0;
    string ans = "";
    while(cursum > 0){
        if(brr[0] > brr[1]){
            if(cnt <= MAXN) ans += "R";
            swap(brr[0], brr[1]);
        }
        else if(brr[0] == brr[1]){
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        int inc = min((brr[1]-1)/brr[0], (cursum+brr[0]-1)/brr[0]);
        cnt += inc;
        if(cnt <= MAXN){
            int tmp = inc;
            while(tmp--) ans += "P";
        }
        brr[1] -= inc*brr[0];
        cursum -= inc*brr[0];
    }
    if(brr[0] == arr[0] && brr[1] == arr[1]){
        if(cnt > MAXN){
            cout << "BIG" << endl;
            cout << cnt << endl;
            exit(0);
        }
        cout << "SMALL" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        exit(0);
    }
    if(cnt <= MAXN) ans += "R";
    swap(brr[0], brr[1]);
    if(brr[0] == arr[0] && brr[1] == arr[1]){
        if(cnt > MAXN){
            cout << "BIG" << endl;
            cout << cnt << endl;
            exit(0);
        }
        cout << "SMALL" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        exit(0);
    }
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

void solve(){ // n >= 3
    int cursum = 0;
    for(int i = 0; i<n; i++) cursum += brr[i] - arr[i];
    int cnt = 0;
    string ans = "";
    while(cursum > 0){
        vector<int> difs;
        for(int i = 1; i<n; i++) difs.push_back(brr[i]-brr[i-1]);
        if((*max_element(difs.begin(), difs.end())) < 0){
            if(cnt <= MAXN) ans += "R";
            reverse(brr, brr+n);
        }
        else if((*min_element(difs.begin(), difs.end())) <= 0){
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
        if(++cnt <= MAXN) ans += "P";
        for(int i = n-1; i>=1; i--){
            cursum -= brr[i];
            brr[i] -= brr[i-1];
            cursum += brr[i];
        }
    }
    // cout << cnt << endl;
    bool f1 = 1, f2 = 1;
    for(int i = 0; i<n; i++) if(arr[i] != brr[i]) f1 = 0;
    if(f1){
        if(cnt > MAXN){
            cout << "BIG" << endl;
            cout << cnt << endl;
            exit(0);
        }
        cout << "SMALL" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        exit(0);
    }
    if(cnt <= MAXN) ans += "R";
    reverse(brr, brr+n);
    for(int i = 0; i<n; i++) if(arr[i] != brr[i]) f2 = 0;
    if(f2){
        if(cnt > MAXN){
            cout << "BIG" << endl;
            cout << cnt << endl;
            exit(0);
        }
        cout << "SMALL" << endl;
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
        exit(0);
    }
    cout << "IMPOSSIBLE" << endl;
    exit(0);
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++) cin >> brr[i];
    if(n == 1){
        if(arr[0] != brr[0]) cout << "IMPOSSIBLE" << endl;
        else{
            cout << "SMALL" << endl;
            cout << 0 << endl;
        }
        return 0;
    }
    if(n == 2) special();
    solve();
}