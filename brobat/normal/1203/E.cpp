// https://codeforces.com/problemset/problem/1203/E

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("lostcow.in","r",stdin);
    // freopen("lostcow.out","w",stdout);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0; i<n; i++) {
        if(i==0) arr[i] -= 1;
        else {
            if(arr[i-1]>=arr[i]) arr[i] += 1;
            else if(arr[i]-arr[i-1]==1) arr[i] += 0;
            else arr[i] -= 1;
        }
        if(arr[i]==0) arr[i] = 1;
    }
    set <int> s;
    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
    }
    cout << s.size();
    return 0;
}