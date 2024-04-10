#include<bits/stdc++.h>
using namespace std;
 
const int N = 5005, M = 1e9+7;
int cc[N], h[N], col[N];
vector<int> gr[N];
 
int lcnt[N], rcnt[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin>>n>>m;
 
    for (int i=1; i<=n; i++)    cin>>col[i];
 
    for (int i=1; i<=m; i++) {
        cin>>cc[i]>>h[i];
        gr[cc[i]].push_back(i);
    }
 
    for (int i=1; i<=n; i++) {
        sort(gr[i].begin(), gr[i].end(), [](int i, int j) {return h[i] < h[j];});
    }
 
    int ans = 0, ways = 0;
 
    for (int i=1; i<=m; i++) {
        int id = -1, cnt = 0, c = cc[i];
        for (int ii=1; ii<=n; ii++) {
            if (col[ii] != c)   continue;
            cnt++;
            if (cnt == h[i]) {
                id = ii;
                break;
            }
        }
        if (id == -1)   continue;
 
        for (int i=1; i<=n; i++)    lcnt[i] = rcnt[i] = 0;
        for (int ii=1; ii<id; ii++)
            if (col[ii] != c)
                lcnt[col[ii]]++;
        for (int ii=id+1; ii<=n; ii++)  rcnt[col[ii]]++;
 
        int cur = 1, ww = 1;
        for (int c=1; c<=n; c++) {
            int ll = 0, rr = 0, both = 0;
            for (int v: gr[c]) {
                if (v == i)     continue;
                if (h[v] <= lcnt[c])    ll++;
                if (h[v] <= rcnt[c])    rr++;
                if (h[v] <= lcnt[c] && h[v] <= rcnt[c])     both++;
            }
 
            int taketwo = ll*rr-both;
            int takeone = ll+rr;
 
            if (taketwo)        cur += 2, ww = (1LL*ww*taketwo)%M;
            else if (takeone)   cur += 1, ww = (1LL*ww*takeone)%M;
 
//            cout<<c<<": "<<ll<<" "<<rr<<" "<<both<<" "<<lcnt[c]<<" "<<rcnt[c]<<endl;
        }
 
//        cout<<i<<" "<<id<<" "<<cur<<" "<<ww<<endl;
 
        if (cur > ans)  ans = cur, ways = ww;
        else if (cur == ans)  ways = (ways + ww)%M;
    }
 
 
    memset(rcnt, 0, sizeof rcnt);
    for (int i=1; i<=n; i++)    rcnt[col[i]]++;
 
    int cur = 0, ww = 1;
    for (int c=1; c<=n; c++) {
        int cnt = 0;
        for (int v: gr[c]) {
            if (h[v] <= rcnt[c])    cnt++;
        }
        if (cnt)    cur++, ww = (1LL*ww*cnt)%M;
    }
 
    if (cur > ans)  ans = cur, ways = ww;
    else if (cur == ans)  ways = (ways + ww)%M;
    cout<<ans<<" "<<ways<<endl;
}