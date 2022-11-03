#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

const int NMAX = 100011;

vector<vector<int> > g;
vector<vector<pair<int,int> > > q;
int res[NMAX];
int n,m;

map<string,int> ren;
int z[NMAX];

void dfs(int v,deque<set<int> > & a){
    for (int i=0;i<g[v].size();i++){
        deque<set<int> > tmp;
        dfs(g[v][i],tmp);
        if (a.size()<tmp.size())
            swap(a,tmp);
        for (int i=0;i<tmp.size();i++){
            if (a[i].size()<tmp[i].size())swap(a[i],tmp[i]);
            a[i].insert(tmp[i].begin(),tmp[i].end());
        }
    }
    set<int> tt;
    tt.insert(z[v]);
    a.push_front(tt);
    for (int i=0;i<q[v].size();i++)
        if (q[v][i].second>=a.size())
            res[q[v][i].first] = 0;
        else
            res[q[v][i].first] = a[q[v][i].second].size();
}

int main(){
  //  ifstream cin("input.txt");
    cin >> n;
    g.resize(n+1);
    q.resize(n+1);
    int cnt = 1,p,temp;
    string s;
    for (int i=1;i<=n;i++){
        cin >> s >> p;
        temp = ren[s];
        if (!temp)
            z[i] = ren[s] = cnt++;
        else
            z[i] = temp;
        g[p].push_back(i);
    }
    cin >> m;
    for (int i=0;i<m;i++){
        int v,k;
        cin >> v >> k;
        q[v].push_back(make_pair(i,k));
    }
    for (int i=0;i<g[0].size();i++){
        deque<set<int> > tmp;
        dfs(g[0][i], tmp);
    }
    for (int i=0;i<m;i++)
        cout << res[i] << endl;
    return 0;
}