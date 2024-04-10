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

int c[26],c1[100][26],a[100];
string s;
int n,nfl;
int m;

bool g[128][128];
int w[128][128],f[128][128],u[128][128];
vector<int> res;

bool fordbellman(){
    int p[128];
    int d[128];
    p[0] = -1;
    for (int i=0;i<m;i++)
        d[i] = MAX_INT;
    d[0]=0;
    for (int i=0;i<m;i++)
        for (int v1=0;v1<m;v1++)
            if (d[v1]<MAX_INT)
                for (int v2=0;v2<m;v2++)
                    if (f[v1][v2]<u[v1][v2] && g[v1][v2] && d[v2]>d[v1]+w[v1][v2]){
                        d[v2] = d[v1] + w[v1][v2];
                        p[v2] = v1;
                    }
    if (d[m-1]==MAX_INT)return false;
    res.clear();
    for (int i=m-1;i!=-1;i=p[i])
        res.push_back(i);
    for (int l=0,r=res.size()-1;l<r;l++,r--)
        swap(res[l],res[r]);
    return true;
}

int main(){
    cin >> s;
    for (int i=0;i<26;i++) c[i] = 0;
    for (int i=0;i<s.length();i++)
        c[s[i]-'a']++;
    nfl = s.length();
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s >> a[i];
        for (int j=0;j<26;j++)
            c1[i][j] = 0;
        for (int j=0;j<s.length();j++)
            c1[i][s[j]-'a']++;
    }
    m = 28+n;
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            g[i][j]=false;
    for (int i=1;i<=n;i++){
        g[0][i]=true;
        w[0][i]=i;
        u[0][i]=a[i-1];
        f[0][i]=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=26;j++){
            g[i][n+j]=true;
            w[i][n+j]=0;
            u[i][n+j]=c1[i-1][j-1];
            f[i][n+j]=0;
        }
    for (int j=1;j<=26;j++){
        g[n+j][n+27]=true;
        w[n+j][n+27]=0;
        u[n+j][n+27]=c[j-1];
        f[n+j][n+27]=0;
    }
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            if (!g[j][i] && g[i][j]){
                g[j][i]=true;
                w[j][i]=-w[i][j];
                u[j][i]=0;
                f[j][i]=0;
            }
    int flow = 0,cost = 0;
    while (1){
        if (!fordbellman())
            break;
        int max_flow=MAX_INT;
        int cur_cost=0;
        for (int i=1;i<res.size();i++){
            int v1 = res[i-1];
            int v2 = res[i];
            int cur_flow = u[v1][v2]-f[v1][v2];
            max_flow = min(max_flow,cur_flow);
            cur_cost += w[v1][v2];
        }
        for (int i=1;i<res.size();i++){
            int v1 = res[i-1];
            int v2 = res[i];
            f[v1][v2] += max_flow;
            f[v2][v1] -= max_flow;
        }
        flow += max_flow;
        cost += max_flow*cur_cost;
    }
    if (flow!=nfl)
        cout << -1 << endl;
    else
        cout << cost << endl;
    return 0;
}