#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=1e6+1;
int good[MN];
int tosub[MN];
int ans[MN];
vector<pii> updates[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)good[i]=0,tosub[i]=0;
        for(int i=0;i<m*n;i++)updates[i]=vector<pii>();
        string a(n*m,'1');
        cin>>a;
        int goodcnt=0;
        vector<int> ord;
        for(int i=0;i<sz(a);i++){
            if(a[i]=='1') {
                good[i % m]++;
                if (good[i % m] == 1)goodcnt++;
                while(sz(ord)>=2&&i-ord[sz(ord)-2]<=m)ord.pop_back();
                ord.push_back(i);
            }
            ans[i]=goodcnt;
        }
        if(sz(ord)) {
            for (int i = 0; i < n; i++) {
                if (i * m + ord[0] < n * m)updates[i * m + ord[0]].push_back({i, 1});
            }
            for (int i = 1; i < sz(ord); i++) {
                if (ord[i] - ord[i - 1] > m) {
                    for (int j = ord[i - 1] + m; j < ord[i]; j++) {
                        updates[j].push_back({-1, (j - ord[i - 1]) / m});
                    }
                    for (int j = 0; j < m; j++) {
                        int cur = ord[i] + j;
                        if (cur < n * m) {
                            int otherat = max(0, (cur - ord[i - 1]) / m - 1);
                            updates[cur].push_back({-2, otherat});
                        }
                    }
                }
            }
            for (int j = ord.back() + m; j < n * m; j++) {
                updates[j].push_back({-1, (j - ord.back()) / m});
            }
        }
        for(int i=0;i<n;i++)good[i]=0;
        goodcnt=0;
        for(int i=0;i<n*m;i++){
            int tempsub=0;
            for(auto x:updates[i]){
                if(x.first>=0)goodcnt++;
                else if(x.first==-1){
                    tempsub+=x.second;
                }
                else{
                    tosub[i%m]+=x.second;
                }
            }
            updates[i]=vector<pii>();
            printf("%d%c",goodcnt-tempsub-tosub[i%m]+ans[i]," \n"[i==n*m-1]);
        }
    }
    return 0;
}