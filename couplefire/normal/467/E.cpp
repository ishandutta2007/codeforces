//https://codeforces.com/problemset/problem/467/E
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009
#define MAXN 500005

template<int SZ> struct mergeSortTree{
    const int ID = 1000000009;
    vector<int> t[4*SZ];
    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = vector<int>(1, a[tl]);
        } else { 
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), back_inserter(t[v]));
        }
    }
    int query(int l, int r, int x, int v, int tl, int tr) {
        if (l > r) 
            return ID;
        if (l == tl && r == tr) {
            vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
            if (pos != t[v].end())
                return *pos;
            return ID;
        }
        int tm = (tl + tr) / 2;
        return min(query(l, min(r, tm), x, v*2, tl, tm), query(max(l, tm+1), r, x, v*2+1, tm+1, tr));
    }
};
mergeSortTree<MAXN> tree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    map<int, int> nextpos;
    int pos[n];
    for(int i = n-1; i>=0; i--){
        if(!nextpos.count(arr[i])){
            pos[i] = INF;
        }
        else pos[i] = nextpos[arr[i]];
        nextpos[arr[i]] = i;
    }
    tree.build(pos, 1, 0, n-1);
    int getNext[n+1];
    getNext[n] = INF;
    pair<int, int> tempans[n+1];
    tempans[n] = {INF, INF};
    for(int i = n-1; i>=0; i--){
        getNext[i] = getNext[i+1];
        tempans[i] = tempans[i+1];
        int cur = pos[i];
        int j;
        for(j = 0; j<3 && cur != INF; j++){
            int t = tree.query(i+1, cur-1, cur+1, 1, 0, n-1);
            if(t < getNext[i]) tempans[i] = {arr[i], arr[t]}; 
            getNext[i] = min(getNext[i], t);
            //cout << j << endl;
            if(j != 2) cur = pos[cur];
        }
        if(cur != INF){
            if(cur < getNext[i]) tempans[i] = {arr[i], arr[i]};
            getNext[i] = min(getNext[i], cur);
        }
    }
    int cur = 0;
    vector<int> ans;
    while(cur < n && getNext[cur] != INF){
        ans.push_back(tempans[cur].first);
        ans.push_back(tempans[cur].second);
        ans.push_back(tempans[cur].first);
        ans.push_back(tempans[cur].second);
        cur = getNext[cur]+1;
    }
    // cout << pos[5] << endl;
    // cout << getNext[4] << endl;
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
}