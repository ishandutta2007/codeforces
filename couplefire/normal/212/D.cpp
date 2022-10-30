#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006

int parent[MAXN];
int siz[MAXN];

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

int n, m;
pair<int, int> arr[MAXN];
bool visited[MAXN] = {0};
long long queries[MAXN];
long long prefix[MAXN] = {0};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    for(int i = 0; i<n; i++) make_set(i);
    sort(arr, arr+n);
    reverse(arr, arr+n);
    for(int i = 0; i<n; i++){
        int lsiz = 0, rsiz = 0;
        if(arr[i].second !=n-1 && visited[arr[i].second+1]){
            rsiz = siz[find_set(arr[i].second+1)];
            union_sets(arr[i].second, arr[i].second+1);
        }
        if(arr[i].second != 0 && visited[arr[i].second-1]){
            lsiz = siz[find_set(arr[i].second-1)];
            union_sets(arr[i].second, arr[i].second-1);
        }
        if(lsiz > rsiz) swap(lsiz, rsiz);
        prefix[1] += arr[i].first;
        prefix[lsiz+2] -= arr[i].first;
        prefix[rsiz+2] -= arr[i].first;
        prefix[lsiz+rsiz+3] += arr[i].first;
        visited[arr[i].second] = 1;
    }
    long long curadd = 0;
    long long cur = 0;
    for(int i = 1; i<=n; i++){
        curadd += prefix[i];
        cur += curadd;
        queries[i] = cur;
    }
    scanf("%d", &m);
    for(int i = 0; i<m; i++){
        int k; scanf("%d",&k);
        printf("%.10f\n", (0.0+queries[k])/(0.0+n-k+1.0));
    }
}