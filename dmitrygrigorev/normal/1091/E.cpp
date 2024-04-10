#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > rmq;
int n;
pair<int, int> Get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return {0,0};
    if (l==l1 && r==r1) return rmq[i];
    int mid = (l+r)/2;
    pair<int, int> A = Get(2*i+1, l, mid, l1, min(r1, mid)), B = Get(2*i+2, mid, r, max(l1, mid), r1);
    return {A.first+B.first, A.second+B.second};
}
int get(int k){
    pair<int, int> p = Get(0, 0, n+1, 0, k+1);
    pair<int, int> q = Get(0, 0, n+1, k+1, n+1);
    //cout << k+1 << " " << n+1 << " " << q.first << " " << q.second << endl;
    return p.first + k*q.second;
}
void add(int i, int l, int r, int ind){
    if (r-l==1){
        rmq[i].first+=l;
        rmq[i].second++;
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) add(2*i+1, l, mid, ind);
    else add(2*i+2, mid, r, ind);
    pair<int, int> A = rmq[2*i+1], B = rmq[2*i+2];
    rmq[i] = {A.first+B.first, A.second+B.second};
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    for (int i=0; i < 4*n+4;i++) rmq.push_back({0, 0});
    int S = 0;
    for (int i=0; i < n; i++) S += v[i];
    int lowb=0, highb=n+1;
    for (int i=n; i >= 0; i--){
        int lb;
        if (i != n) lb = v[i];
        else lb = 0;
        int k = i+1;
        if (k != n+1){
            int right_sum = k*(k-1) + get(k);
            right_sum -= S;
            //cout << right_sum << endl;
            highb = min(highb, max(right_sum, lb-1));
        }
        int rb;
        if (i != 0) rb = v[i-1];
        else rb = n+1;
        k = i;
        if (k != 0){
            int right_sum = k*(k-1) + get(k);
            right_sum -= S;
            right_sum*=-1;
            //cout << right_sum << endl;
            lowb = max(lowb, min(right_sum, rb+1));
        }
        if (i==0) break;
        add(0, 0, n+1, v[i-1]);
        S -= v[i-1];
    }
    vector<int> anses;
    for (int i=0;i<n;i++) S += v[i];
    for (int i=0; i <= n; i++){
        if ((S+i)%2 != 0) continue;
        if (i < lowb || i > highb) continue;
        anses.push_back(i);
    }
    if (anses.size() == 0) cout << -1;
    else{
        for (int i=0;i<anses.size();i++) cout << anses[i] << " ";
    }
    return 0;
}