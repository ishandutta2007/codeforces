#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#define M 100010
using namespace std;
int n, m, c[M], ans, xd = 0;
map<int, set<int> > cnt;
map<int, set<int> >::iterator it;
int main(){
    scanf("%d%d", &n ,&m);
    for(int i =1; i <= n; i++){
        scanf("%d", &c[i]);
    }
    ans = c[1];
    for(int i = 2; i <= n; i++){
        ans = min(ans ,c[i]);
    }
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        if(c[u] != c[v]){
            cnt[c[u]].insert(c[v]);
            cnt[c[v]].insert(c[u]);
        }
    }

    for(it = cnt.begin(); it != cnt.end(); it++){
        if((*it).second.size() > xd || ((*it).second.size() == xd && (*it).first<ans)){
            xd = (*it).second.size();
            ans = (*it).first;
        }
    }

    //cout << xd << endl;
    cout << ans << endl;
    return 0;
}