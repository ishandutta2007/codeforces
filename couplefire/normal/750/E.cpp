#include <bits/stdc++.h>
using namespace std;

const int G[5] = {2, 0, 1, 7, 69};
const int B[5] = {69, 69, 69, 6, 6};
const int INF = 0x3f3f3f3f;
const int N = 1<<18;

struct Mat{
    int a[5][5];
    Mat(int n = 420){
        memset(a, INF, sizeof a);
        for(int i = 0; i<5; ++i)
            a[i][i] = (n==G[i] || n==B[i])?1:0;
        for(int i = 0; i<4; ++i)
            a[i][i+1] = (n==G[i])?0:INF;
    }
    void ID(){memset(a, INF, sizeof a);}
    Mat operator * (const Mat& o) const{
        Mat res; res.ID();
        for(int i = 0; i<5; ++i)
            for(int j = i; j<5; ++j)
                for(int k = i; k<=j; ++k)
                    res.a[i][j] = min(res.a[i][j], a[i][k]+o.a[k][j]);
        return res;
    }
};

Mat tree[N<<1];
string s; int arr[N], n, q;

void build(int v = 1, int tl = 0, int tr = N-1){
    if(tl==tr) return void(tree[v] = Mat(arr[tl]));
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm); build(v<<1|1, tm+1, tr);
    tree[v] = tree[v<<1]*tree[v<<1|1];
}

Mat query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(tr<l || tl>r) return Mat();
    if(l<=tl && tr<=r) return tree[v];
    int tm = (tl+tr)>>1;
    return query(l, r, v<<1, tl, tm)*query(l, r, v<<1|1, tm+1, tr);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> s;
    for(int i = 0; i<n; ++i)
        arr[i] = s[i]-'0';
    build();
    while(q--){
        int l, r, tmp; cin >> l >> r; --l; --r;
        cout << ((tmp=query(l, r).a[0][4])==INF?-1:tmp) << '\n';
    }
}