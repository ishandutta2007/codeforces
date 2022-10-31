#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct node{
    int dp[3][3]; 
    node(){memset(dp, 0, sizeof dp);}
    node(char c){
        memset(dp, 0, sizeof dp);
        dp[c-'a'][c-'a'] = 1;
    }
    node(node a, node b){
        memset(dp, 63, sizeof dp);
        for(int i = 0; i<3; ++i)
            for(int j = i; j<3; ++j)
                for(int x = i; x<=j; ++x)
                    dp[i][j] = min(dp[i][j], a.dp[i][x]+b.dp[x][j]);
    }
} tree[N<<2];

int n, q; string s;

void build(int v, int tl, int tr){
    if(tl==tr) return tree[v] = node(s[tl]), void();
    int tm = (tl+tr)>>1;
    build(v<<1, tl, tm); build(v<<1|1, tm+1, tr);
    tree[v] = node(tree[v<<1], tree[v<<1|1]);
}

void upd(int pos, char c, int v, int tl, int tr){
    if(tl==tr) return tree[v] = node(c), void();
    int tm = (tl+tr)>>1;
    if(pos<=tm) upd(pos, c, v<<1, tl, tm);
    else upd(pos, c, v<<1|1, tm+1, tr);
    tree[v] = node(tree[v<<1], tree[v<<1|1]);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> s;
    build(1, 0, n-1);
    while(q--){
        int pos; char c;
        cin >> pos >> c;
        upd(pos-1, c, 1, 0, n-1);
        cout << tree[1].dp[0][2] << '\n';
    }
}