#include <bits/stdc++.h>
using namespace std;

#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define endl '\n'
#define int long long

const int N = 1000000007;
const int N2 = 998244353;
const int INF = 1000000000000000000;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input12.txt","r",stdin);
    // freopen("ans12.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    int sp;
    cin >> sp;
    sp--;
    vector<vector<int>> edge(n);
    for (int t1=0;t1<m;t1++) {
        int a,b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        // edge[b-1].push_back(a-1);
    }
    int vis[n]={};
    int par[n]={};
    int end[n]={};
    par[sp]=-2;
    vis[sp]=-2;
    end[sp]=1;
    queue<int> q;
    for (int t1=0;t1<edge[sp].size();t1++) {
        par[edge[sp][t1]]=sp;
        // end[edge[sp][t1]]=1;
        vis[edge[sp][t1]]=t1+1;
        q.push(edge[sp][t1]);
    }
    int pt1=INF,pt2;
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int t1=0;t1<edge[pos].size();t1++) {
            int child=edge[pos][t1];
            if (!vis[child]) {
                vis[child]=vis[pos];
                par[child]=pos;
                q.push(child);
            }
            else if (!end[child] && child!=par[pos] && vis[pos]!=vis[child]) {
                pt1=child;
                pt2=pos;
            }
        }
    }
    if (pt1==INF) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        vector<int> path1,path2;
        int tt=pt1;
        while (tt!=-2) {
            path1.push_back(tt);
            tt=par[tt];
        }
        reverse(path1.begin(),path1.end());
        tt=pt2;
        path2.push_back(pt1);
        while (tt!=-2) {
            path2.push_back(tt);
            tt=par[tt];
        }
        reverse(path2.begin(),path2.end());
        cout << path1.size() << endl;
        for (int t1=0;t1<path1.size();t1++) {
            cout << path1[t1]+1 << " ";
        }
        cout << endl;
        cout << path2.size() << endl;
        for (int t1=0;t1<path2.size();t1++) {
            cout << path2[t1]+1 << " ";
        }
    }
    return 0;
}