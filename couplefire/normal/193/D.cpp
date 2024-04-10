#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define BLOCK 2000

int n;
int arr[MAXN];
vector<int> neigh[MAXN];
bool pos[MAXN] = {0};
int loc[MAXN];
int cnt[MAXN/BLOCK+10][MAXN] = {{0}};
int shift[BLOCK] = {0};
int num[MAXN] = {0};
long long ans = 0;

void help(int i, int cl, int x){
    cnt[cl][num[i]]--;
    num[i] += x;
    cnt[cl][num[i]]++;
}

void upd(int l, int r, int x){
    if(r < l) return;
    int cl = l/BLOCK, cr = r/BLOCK;
    if(cl == cr){
        for(int i = l; i<=r; i++){
            help(i, cl, x);
        }
    }
    else{
        for(int i = l, end = (cl+1)*BLOCK-1; i<=end; i++){
            help(i, cl, x);
        }
        for(int i = cl+1; i<=cr-1; i++) shift[i] += x;
        for(int i = cr*BLOCK; i<=r; i++) help(i, cr, x);
    }
}

int query(int l, int r){
    if(l > r) return 0;
    int cl = l/BLOCK, cr = r/BLOCK;
    int cc = 0;
    if(cl == cr){
        for(int i = l; i<=r; i++){
            if(num[i]+shift[cl] <= 2) cc++;
        }
    }
    else{
        for(int i = l, end = (cl+1)*BLOCK-1; i<=end; i++){
            if(num[i]+shift[cl] <= 2) cc++;
        }
        for(int i = cl+1; i<=cr-1; i++) cc += cnt[i][2-shift[i]]+cnt[i][1-shift[i]]+cnt[i][0-shift[i]];
        for(int i = cr*BLOCK; i<=r; i++){
            if(num[i]+shift[cr] <= 2) cc++;
        }
    }
    return cc;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a; cin >> a; --a;
        arr[a] = i;
        loc[i] = a;
    }
    int cur = 0;
    for(int i = 0; i<n; i++){
        int a = arr[i];
        if((a == 0 || !pos[a-1]) && (!pos[a+1])) cur++;
        if((a > 0 && pos[a-1]) && pos[a+1]) cur--;
        if(a > 0 && pos[a-1]){
            neigh[a].push_back(i);
            neigh[a-1].push_back(i);
        }
        if(pos[a+1]){
            neigh[a].push_back(i);
            neigh[a+1].push_back(i);
        }
        pos[a] = 1;
        cnt[i/BLOCK][cur]++;
        if(cur <= 2) ans++;
        num[i] = cur;
    }
    for(int i = 0; i<n; i++) sort(neigh[i].begin(), neigh[i].end());
    for(int i = 0; i<n-1; i++){
        int a = arr[i];
        vector<int> t;
        for(auto j : neigh[a]){
            if(j > i) t.push_back(j);
        }
        if(t.size() == 0){
            upd(i, n-1, -1);
        }
        else if(t.size() == 1){
            upd(i, t[0]-1, -1);
        }
        else{
            upd(i, t[0]-1, -1);
            upd(t[1], n-1, 1);
        }
        ans += query(i+2, n-1);
    }
    cout << ans-1 << endl;
}