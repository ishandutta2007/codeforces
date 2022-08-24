#include <bits/stdc++.h>
#define ll long long
#define db long double
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1000007;
int fenw[N];
int v[N];

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result ^= fenw[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i < N; i = (i | (i+1)))
        fenw[i] ^= delta;
}

int sum (int l, int r)
{
    return sum (r) ^ sum (l-1);
}

int nxt[N], ans[N];

struct Q{int l; int r; int index;};

bool cmp(Q &a, Q &b){
    return (a.l < b.l);
}

main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n;
    cin >> n;
    for (int i=0; i < n; ++i) cin >> v[i];

    map<int, int> first;

    for (int i=n-1; i >= 0; i--){
        if (first.count(v[i])) nxt[i] = first[v[i]];
        else nxt[i] = -1;
        first[v[i]] = i;
    }

    for (int i=0; i < n; ++i){
        inc(i, v[i]);
    }

    for (auto it = first.begin(); it != first.end(); ++it){
        inc((*it).second, v[(*it).second]);
    }

    vector<Q> queries;

    int q;
    cin >> q;
    for (int i=0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries.push_back({l, r, i});
    }

    sort(queries.begin(), queries.end(), cmp);
    
    int last = 0;
    for (int i=0; i < queries.size(); ++i){
        while (last != queries[i].l){
            int t = nxt[last++];
            if (t!=-1) inc(t, v[t]);
        }
        ans[queries[i].index] = sum(queries[i].l, queries[i].r);
    }
    for (int i=0;i<q;++i) cout << ans[i] << " ";


}