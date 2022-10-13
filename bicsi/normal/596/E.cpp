#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;


char Mat[300][300];
int A[300], B[300], Node[300][300];
int Go[90000], Digit[90000];
int Viz[90000], In[90000];
int Start[90000], Last[90000];
int cicli;
bool Has[90000][10];

vector<int> G[90000];

void dfs(int node) {
    Viz[node] = 1;
    In[node] = 1;

    if(!Viz[Go[node]]) {
        dfs(Go[node]);
    } else if(In[Go[node]]) {
        ++cicli;

        for(int i=Go[node]; i != node; i = Go[i])
            Has[cicli][Digit[i]] = 1;
        Has[cicli][Digit[node]] = 1;

        Go[node] = 0;
        Last[cicli] = node;
    }

    G[Go[node]].push_back(node);
    In[node] = 0;
}

char query[5000000];

bool dfss(int node, int pos) {
    if(Digit[node] == query[pos]) {
        pos--;
        if(pos < 0) return true;
    }

    for(auto vec : G[node]) {
        if(dfss(vec, pos))
            return true;
    }

    return false;
}

bool Solve() {

    int len = strlen(query);
    for(int i=0; query[i]; i++)
        query[i] -= '0';

    for(int i=1; i<=cicli; i++) {
        for(int pos = len-1; ; pos--) {
            if(pos < 0) return true;

            if(!Has[i][query[pos]]) {
                if(dfss(Last[i], pos))
                    return true;
                break;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE


    int n, m, q;
    cin>>n>>m>>q;

    for(int i=0; i<n; i++) {
        cin>>Mat[i];
    }

    for(int i=0; i<10; i++) {
        cin>>A[i]>>B[i];
    }

    int nodes = 0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
        Mat[i][j] -= '0';
        Node[i][j] = ++nodes;
    }


    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
        int d = Mat[i][j];

        Digit[Node[i][j]] = d;
        int newi = i + A[d];
        int newj = j + B[d];

        if(newi < 0 || newj < 0 || newi >= n || newj >= m)
            Go[Node[i][j]] = Node[i][j];
        else
            Go[Node[i][j]] = Node[newi][newj];
    }


    for(int i=1; i<=nodes; i++) {
        if(!Viz[i]) {
            dfs(i);
        }
    }

    while(q--) {
        cin>>query;
        cout<<(Solve() ? "YES\n" : "NO\n");
    }


    return 0;
}