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
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
vector< vector<int> > g1;
vector< pair<int,int> > a,g2;
int cnt[222222];

void dfs(int v,int pr_s = -1, int pr_f = -1){
    for (int i=0;i<g1[v].size();i++){
        int u = g1[v][i];
        if (u!=pr_s){
            a.push_back(make_pair(v,u));
            if (pr_f!=-1) g2.push_back(make_pair(pr_f,a.size()-1));
            dfs(u,v,a.size()-1);
        }
    }
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++)
        cnt[i]=0;
    g1.resize(n);
    for (int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g1[a].push_back(b);
        g1[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    for (int i=0;i<n;i++)
        if (cnt[i]==1){
            dfs(i);
            break;
        }
    cout << a.size() << endl;
    for (int i=0;i<a.size();i++)
        cout << 2 << " " << (a[i].first+1) << " " << (a[i].second+1) << endl;
    for (int i=0;i<g2.size();i++)
        cout << (g2[i].first+1) << " " << (g2[i].second+1) << endl;
    return 0;
}