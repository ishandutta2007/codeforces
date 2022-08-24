#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    if (a.second != b.second) return (a.second < b.second);
    return (a.first < b.first);
}
vector<int> rmq;
void build(int i, int l, int r){
    if (r-l==1){
        rmq[i]=1;
        return;
    }
    int mid = (l+r)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid, r);
    rmq[i] = rmq[2*i+2] + rmq[2*i+1];
}
int get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1) return rmq[i];
    int mid = (l+r)/2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
}
void change(int i, int l, int r, int ind){
    if (r-l==1){
        rmq[i]=0;
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) change(2*i+1, l, mid, ind);
    else change(2*i+2, mid, r, ind);
    rmq[i] = rmq[2*i+2] + rmq[2*i+1];
}
int bs(vector<int> &v, int T){
    int L = -1, R = v.size();
    while (R-L>1){
        int M = (L+R)/2;
        if (v[M] >= T) R = M;
        else L = M;
    }
    return R;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > points;
    vector<int> xc;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        xc.push_back(x);
        points.push_back({x, y});
    }
    sort(points.begin(), points.end(), cmp);
    sort(xc.begin(), xc.end());
    map<int, int> tet;
    int cur=0;
    for (int i=1; i < xc.size(); i++) if (xc[i] != xc[i-1]){
        tet[xc[i-1]] = cur++;
    }
    tet[xc.back()] = cur;
    vector<int> real_coord;
    vector<int> real_x;
    for (auto it=tet.begin(); it != tet.end(); it++){
        pair<int, int> p = *it;
        real_x.push_back(p.first);
    }
    for (int i=0; i < n; i++){
        real_coord.push_back(tet[points[i].first]);
    }
    int S = real_x.size();
    vector<int> cnt(S);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i=0; i < n; i++){
        cnt[real_coord[i]]++;
    }
    rmq.resize(4*S, 0);
    build(0, 0, S);
    int start = 0;
    int ans=0;
    while (start < n){
        int finish = start;
        while (finish < n && points[finish].second == points[start].second){
            finish++;
        }
        for (int i=start; i < finish; i++){
            if (i > start && real_coord[i] == real_coord[i-1]) continue;
            int ths = real_coord[i];
            int T=0;
            if (i != start) T = real_coord[i-1]+1;
            int A = get(0, 0, S, T, ths+1), B = get(0, 0, S, ths, S);
            ans += A*B;
        }
        for (int i=start; i < finish; i++){
            int T = real_coord[i];
            cnt[T]--;
            if (cnt[T] == 0) change(0, 0, S, T);
        }
        start = finish;
    }
    cout << ans;
    return 0;
}