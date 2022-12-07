#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int n, k;
vector<pair<int, int> >g;
int l, r, ans, ansL[1000100], ansR[1000100];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        g.push_back(make_pair(l, -1));
        g.push_back(make_pair(r, 1));
    }
    sort(g.begin(), g.end());
    int now = 0, la = -(1 << 30);
    for(int i = 0; i < g.size(); i++){
        now -= g[i].second;
        while(i != g.size() - 1 && g[i].first == g[i + 1].first && g[i].second == g[i + 1].second){
            i++;
            now -= g[i].second;
        }
        if (now < k){
            if (la > -(1 << 30)){
                ansL[++ans] = la;
                ansR[ans] = g[i].first;
                la = -(1 << 30);
            }
        }else{
            if (la == -(1 << 30)){
                la = g[i].first;
            }
        }
    }
    if (la != -(1 << 30)){
        ansL[++ans] = la;
        ansR[ans] = g[g.size() - 1].first;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= ans; i++) printf("%d %d\n", ansL[i], ansR[i]);
  return 0;
}