#include <bits/stdc++.h>
using namespace std;
#define MAXN 3005

int n, p, s;
int arr[MAXN], brr[MAXN];
priority_queue<pair<int, int>> q1, q2, q3;
int vis[MAXN], ans;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> s;
    for(int i = 0; i<n; i++){
        int a; cin >> a; arr[i] = a;
        q1.push({a, i});
    }
    for(int i = 0; i<n; i++){
        int a; cin >> a; brr[i] = a;
        q2.push({a, i});
    }
    while(p--){
        auto x = q1.top(); q1.pop();
        ans += x.first; vis[x.second] = 1;
        q3.push({brr[x.second]-arr[x.second], x.second});
    }
    while(s--){
        while(vis[q1.top().second]) q1.pop();
        while(vis[q2.top().second]) q2.pop();
        auto x1 = q1.top(), x2 = q2.top(), x3 = q3.top();
        if(x1.first+x3.first>x2.first){
            ans += x1.first+x3.first;
            vis[x1.second] = 1, vis[x3.second] = 2;
            q1.pop(); q3.pop(); q3.push({brr[x1.second]-arr[x1.second], x1.second});
        }
        else{
            ans += x2.first;
            vis[x2.second] = 2; q2.pop();
        }
    }
    cout << ans << endl;
    for(int i = 0; i<n; i++) if(vis[i] == 1) cout << i+1 << " ";
    cout << endl;
    for(int i = 0; i<n; i++) if(vis[i] == 2) cout << i+1 << " ";
    cout << endl;
}