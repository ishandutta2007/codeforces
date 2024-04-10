#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int parent[MAXN], siz[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    int n, k; cin >> n >> k;
    int p1[n], p2[n];
    int pos1[n], pos2[n];
    int prefix1[n], prefix2[n];
    fill(prefix1, prefix1+n, 0);
    fill(prefix2, prefix2+n, 0);
    for(int i = 0; i<n; i++){
        cin >> p1[i]; --p1[i];
        pos1[p1[i]] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> p2[i]; --p2[i];
        pos2[p2[i]] = i;
    }
    for(int i = 0; i<n; i++){
        make_set(i);
    }
    for(int i = 0; i<n; i++){
        union_sets(p1[i], p2[i]);
        int pp1 = pos1[p2[i]];
        prefix1[min(pp1, i)] += 1;
        prefix1[max(pp1, i)] -= 1;
        int pp2 = pos2[p1[i]];
        prefix2[min(pp2, i)] += 1;
        prefix2[max(pp2, i)] -= 1;
    }
    int cursum1 = 0;
    int cursum2 = 0;
    for(int i = 0; i<n; i++){
        if(cursum1) union_sets(p1[i], p1[i-1]);
        if(cursum2) union_sets(p2[i], p2[i-1]);
        cursum1 += prefix1[i];
        cursum2 += prefix2[i];
    }
    set<int> prts;
    for(int i = 0; i<n; i++) prts.insert(find_set(i));
    if(prts.size() < k){
        cout << "NO" << endl;
        exit(0);
    }
    char cur = 'a'-1;
    string re(n, ' ');
    int prev = -1;
    for(int i = 0; i<n; i++){
        if(find_set(p1[i]) != prev) cur = min(0+'z', cur+1);
        re[p1[i]] = cur;
        prev = find_set(p1[i]);
    }
    cout << "YES" << endl;
    cout << re << endl;
}