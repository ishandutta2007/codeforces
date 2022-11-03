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

const int MAXN = 111111;

int cl[MAXN],cnt[MAXN];
bool icl[MAXN];
int n,m,ans;
vector<pair<int,int> > g;

bool cmp(const pair<int,int> & t1, const pair<int,int> & t2){
    return (t1.first < t2.first || (t1.first==t2.first && t1.second < t2.second));
}

int main(){
    cin >> n >> m;
    for (int i=0;i<MAXN;i++)
        icl[i]=false;
    for (int i=0;i<n;i++){
        cin >> cl[i];
        icl[cl[i]]=true;
    }
    ans = cl[0];
    for (int i=0;i<m;i++){
        int v1,v2;
        cin >> v1 >> v2;
        v1--;v2--;
        v1 = cl[v1];
        v2 = cl[v2];
        if (v1>v2)swap(v1,v2);
        if (v1!=v2)
            g.push_back(make_pair(v1,v2));
    }
    sort(g.begin(),g.end(),cmp);
    m = -1;
    for (int i=0;i<g.size();i++)
        if (m==-1 || (g[i].first!=g[m].first || g[i].second!=g[m].second)){
            m++;
            g[m] = g[i];
        }
    for (int i=1;i<MAXN;i++)
        cnt[i]=0;
    for (int i=0;i<=m;i++){
        cnt[g[i].first]++;
        cnt[g[i].second]++;
    }
    for (int i=1;i<MAXN;i++)
        if (icl[i] && (cnt[i]>cnt[ans] || (cnt[i]==cnt[ans] && i<ans)))
            ans = i;
    cout << ans << endl;

    return 0;
}