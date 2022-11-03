#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
int amount_of_vertexes;
int amount_of_edges;
int n;

void AddEdge(int v1, int v2)
{
    ++amount_of_edges;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

void Add(int shift)
{
    for (int i = 1; i < n; ++i) {
        AddEdge(shift, shift + i);
    }
    int last = shift + n;
    for (int i = 1; i < n; i += 2) {
        int l1 = last;
        int r1 = last + (n - 1) - 1;
        for (int j = l1; j <= r1; ++j) {
            AddEdge(shift + i, j);
        }
        last += (n - 1);
        int l2 = last;
        int r2 = last + (n - 1) - 1;
        for (int j = l2; j <= r2; ++j) {
            AddEdge(shift + i + 1, j);
        }
        for (int j1 = l1; j1 <= r1; ++j1) {
            for (int j2 = l2; j2 <= r2; ++j2) {
                AddEdge(j1, j2);
            }
        }
        last += (n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    if ((n & 1) == 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    if (n == 1) {
        cout << "YES" << endl;
        cout << "2 1" << endl;
        cout << "1 2" << endl;
        return 0;
    }
    
    int N = 1 + (n - 1) + (n - 1) * (n - 1);
    
    amount_of_vertexes = 2 * N;
    amount_of_edges = 0;
    g.resize(amount_of_vertexes);
    
    Add(0);
    Add(N);
    
    AddEdge(0, N);
    
    cout << "YES" << endl;
    cout << amount_of_vertexes << " " << amount_of_edges << endl;
    for (int i = 0; i < amount_of_vertexes; ++i) {
        for (int j = 0; j < (int) g[i].size(); ++j) {
            if (g[i][j] > i) {
                cout << i + 1 << " " << g[i][j] + 1 << '\n';
            }
        }
    }
    cout.flush();
    
   
    return 0;
}