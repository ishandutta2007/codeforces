#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006
#define INF 1000000009
int n, k, l;
int a[MAXN];
pair<int, int> d[MAXN];

int calc(int mid){
    for(int i = 0; i<=n; i++) d[i] = {INF, INF};
    d[0] = {0, 0};

    for(int i = 0; i<n; i++){
        if(d[i+1] > make_pair(d[i].first+a[i], d[i].second)) d[i+1] = {d[i].first+a[i], d[i].second};
        if(d[min(n, i+l)] > make_pair(d[i].first+mid, d[i].second+1)) d[min(n, i+l)] = {d[i].first+mid, d[i].second+1};
    }
    return d[n].second;
}

int getAns(){
    int lo = 0, hi = n;
    int res = 0;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(calc(mid)>k)lo = mid+1, res = mid;
        else hi = mid-1;
    }
    if(calc(res) <= k) return 0;
    calc(res+1);
    return d[n].first-(res+1)*1ll*k;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> l;
    string s; cin >> s;
    int ans = INF;
    for(int i = 0; i<s.length(); i++) a[i] = islower(s[i])>0;
    ans = min(ans, getAns());
    for(int i = 0; i<s.length(); i++) a[i] = isupper(s[i])>0;
    ans = min(ans, getAns());
    cout << ans << endl;
}