#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int w;
};

istream& operator >> (istream& input_stream, Edge& edge)
{
    input_stream >> edge.from >> edge.to >> edge.w;
    --edge.from;
    --edge.to;
    return input_stream;
}

struct MyComp
{
public:
    bool operator () (const Edge& a, const Edge& b) const
    {
        return a.w < b.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> d(n, 0);
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i];
    }
    sort(edges.begin(), edges.end(), MyComp());
    vector<int> ed(n);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j + 1 < m && edges[j + 1].w == edges[i].w) {
            ++j;
        }
        for (int t = i; t <= j; ++t) {
            ed[edges[t].to] = max(ed[edges[t].to], d[edges[t].from] + 1);
        }
        for (int t = i; t <= j; ++t) {
            d[edges[t].to] = max(d[edges[t].to], ed[edges[t].to]);
        }
        i = j + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;

    return 0;
}