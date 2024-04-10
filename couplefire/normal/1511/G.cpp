#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int B = 1900;
const int IB = N/B+5;
const int H = 18;
const int _ = B+5;

struct Trie{
    int ch[_*(H+1)][2], w[_*(H+1)], val[_*(H+1)];
    int tot = 0;
    int mknode(){
        ++tot;
        ch[tot][0] = ch[tot][1] = w[tot] = val[tot] = 0;
        return tot;
    }
    void calc(int v){
        w[v] = val[v] = 0;
        if(ch[v][0]){
            w[v] += w[ch[v][0]];
            val[v] ^= val[ch[v][0]] << 1;
        }
        if(ch[v][1]){
            w[v] += w[ch[v][1]];
            val[v] ^= (val[ch[v][1]] << 1)|(w[ch[v][1]]&1); 
        }
        w[v] &= 1;
    }
    void insert(int &v, int x, int dep){
        if(!v) v = mknode();
        if(dep > H) return (void)(w[v]++);
        insert(ch[v][x&1], x>>1, dep+1);
        calc(v);
    }
    void erase(int v, int x, int dep){
        if(dep > H) return (void)(w[v]--);
        erase(ch[v][x&1], x>>1, dep+1);
        calc(v);
    }
    void addall(int v){
        swap(ch[v][0], ch[v][1]);
        if(ch[v][0]) addall(ch[v][0]);
        calc(v);
    }
} trie[IB];

int n, m, q;
int arr[N], root[IB];
char ans[N];
vector<array<int, 2>> queries[N];

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int a; cin >> a; --a;
        arr[a]++;
    }
    cin >> q;
    for(int i = 0; i<q; i++){
        int l, r; cin >> l >> r; --l, --r;
        queries[l].push_back({r, i});
    }
    for(int i = 0; i<IB; i++)
        root[i] = trie[i].mknode();
    for(int i = m-1; i>=0; i--){
        for(int j = 0; j<IB; j++)
            trie[j].addall(root[j]);
        int lb = i/B;
        for(int j = 0; j<arr[i]; j++)
            trie[lb].insert(root[lb], 0, 0);
        for(auto qs : queries[i]){
            int rb = qs[0]/B;
            int val = 0;
            if(lb == rb){
                for(int j = i; j<=qs[0]; j++)
                    val ^= (arr[j]&1)?(j-i):0;
                ans[qs[1]] = val?'A':'B';
                continue;
            }
            for(int j = i; j<(lb+1)*B; j++)
                val ^= (arr[j]&1)?(j-i):0;
            for(int j = lb+1; j<rb; j++)
                val ^= trie[j].val[root[j]];
            for(int j = rb*B; j<=qs[0]; j++)
                val ^= (arr[j]&1)?(j-i):0;
            ans[qs[1]] = val?'A':'B';
        }
    }
    for(int i = 0; i<q; i++)
        cout << ans[i];
    cout << endl;
}