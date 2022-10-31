#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    int mi = 51;
    for(int i = 0; i<n; i++) mi = min(mi, arr[i]);
    int cnt = 0;
    for(int i  = 0; i<n; i++) if(arr[i] == mi) cnt++;
    if(cnt > (n/2)) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}