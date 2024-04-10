#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tree[400002];
void init(int i, int l, int r)
{
    tree[i] = 0;
    if(l == r) return;
    int m = (l + r)/2;
    init(i*2, l, m);
    init(i*2+1, m+1, r);
}

void update(int i, int l, int r, int id, int v)
{
    if(l == r) { tree[i] = v; return; }
    int m = (l + r)/2;
    if(id <= m) update(i*2, l, m, id, v);
    else update(i*2+1, m+1, r, id, v);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int i, int l, int r, int s, int e)
{
    if(e < s) return 0;
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return query(i*2, l, m, s, e) + query(i*2+1, m+1, r, s, e);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> A[4];
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'A') A[0].push_back(i);
            if(s[i] == 'N') A[1].push_back(i);
            if(s[i] == 'T') A[2].push_back(i);
            if(s[i] == 'O') A[3].push_back(i);
        }
        vector<int> v;
        for(int i=0;i<4;i++) v.push_back(i);
        vector<int> u(4);
        ll opt = -1;
        do
        {
            ll tmp = 0;
            init(1, 0, n-1);
            for(int p=0;p<4;p++)
            {
                for(int i : A[v[p]])
                {
                    tmp += i - query(1, 0, n-1, 0, i-1);
                    update(1, 0, n-1, i, 1);
                }
            }
            if(tmp > opt)
            {
                opt = tmp;
                u = v;
            }
        }while(next_permutation(v.begin(), v.end()));

        for(int i=0;i<4;i++)
        {
            int S = A[u[i]].size();
            for(int j=0;j<S;j++)
            {
                if(u[i] == 0) cout << "A";
                if(u[i] == 1) cout << "N";
                if(u[i] == 2) cout << "T";
                if(u[i] == 3) cout << "O";
            }
        }

        cout << "\n";
    }
}