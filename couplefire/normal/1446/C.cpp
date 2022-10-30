#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    vector<int> lol;
    for(int i = 0; i<n-1; i++){
        int a = arr[i], b = arr[i+1];
        int t = 31;
        int cnt = 0;
        while((a&(1<<t)) == (b&(1<<t))) t--, cnt++;
        lol.push_back(cnt);
    }
    int dp1[lol.size()];
    int dp2[lol.size()];
    stack<int> st1;
    stack<int> st2;
    int c1 = 0, c2 = 0;
    for(int i = 0; i<lol.size(); i++){
        while(!st1.empty() && st1.top() > lol[i]){
            st1.pop();
            c1++;
        }
        st1.push(lol[i]);
        dp1[i] = c1;
    }
    for(int i = lol.size()-1; i >= 0; i--){
        while(!st2.empty() && st2.top() > lol[i]){
            st2.pop();
            c2++;
        }
        st2.push(lol[i]);
        dp2[i] = c2;
    }
    int ans = n;
    for(int i = 0; i<lol.size(); i++){
        ans = min(ans, dp1[i]+dp2[i]);
    }
    cout << ans << endl;
}