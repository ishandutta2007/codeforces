#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200000;
int ans = 0;
int bin(vector<pair<int, int> > &v, int a){
    int L = 0, R = v.size()+1;
    while (R-L > 1){
        int M = (L+R)/2;
        if (v[M-1].first <= a) L = M;
        else R = M;
    }
    return L;
}
void solve(int s, vector<pair<int, int> > &v){
    if (v.size() == 0) return;
    int sz = v.size();
    int pref_min[sz], pref_max[sz], suf_min[sz], suf_max[sz];
    pref_min[0] = v[0].second, pref_max[0] = v[0].second, suf_max[sz-1] = v[sz-1].second, suf_min[sz-1] = v[sz-1].second;
    for (int i=1; i < sz; i++){
        pref_min[i] = min(pref_min[i-1], v[i].second);
        pref_max[i] = max(pref_max[i-1], v[i].second);
    }
    for (int i=sz-2; i >= 0; i--){
        suf_max[i] = max(suf_max[i+1], v[i].second);
        suf_min[i] = min(suf_min[i+1], v[i].second);
    }
    for (int i=s; i < N; i+=2){
        int a = bin(v, i-1);
        if (a==0 || a==sz) continue;
        int Mn = max(pref_min[a-1], suf_min[a]) + 1;
        int Mx = min(pref_max[a-1], suf_max[a]) - 1;
        Mn += i, Mx += i;
        //cout << i << " " << a << " " << Mn << " " << Mx << endl;
        if (Mx < Mn) continue;
        int D = (Mx-Mn+1) / 2;
        if ((Mx-Mn)%2==0 && Mn%2==0) D++;
        ans += D;
    }
}
signed main(){
   // freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > vn, vc;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        int X = x-y;
        int Y = x+y;
        if (X%2==0) vc.push_back(make_pair(X, Y));
        else vn.push_back(make_pair(X, Y));
    }
    sort(vc.begin(), vc.end());
    sort(vn.begin(), vn.end());
    solve(-N+1, vc);
    solve(-N, vn);
    cout << ans << endl;
    return 0;
}