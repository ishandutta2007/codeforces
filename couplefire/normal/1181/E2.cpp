#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1000000009;
using node = pair<pair<int, int>, int>;

int n;
node points[N][4];

bool solve(set<node> st[4]){
    int m = st[0].size();
    if(m == 1) return 1;
    int mx[4]; 
    set<node>::iterator it[4];
    for(int i = 0; i<4; i++)
        mx[i] = -2*INF, it[i] = st[i].begin();
    for(int i = 1; i<=m/2; i++){
        for(int j = 0; j<4; j++){
            mx[j] = max(mx[j], it[j]++->first.second);
            if(mx[j] <= it[j]->first.first){
                set<node> o[4];
                auto oit = st[j].begin();
                for(int k = 1; k<=i; k++){
                    int id = oit++->second;
                    for(int a = 0; a<4; a++)
                        st[a].erase(points[id][a]),
                        o[a].insert(points[id][a]);
                }
                return solve(st)&&solve(o);
            }
        }
    }
    return 0;    
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; set<node> st[4];
    for(int i = 1; i<=n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        points[i][0] = {{a, c}, i};
        points[i][1] = {{-c, -a}, i};
        points[i][2] = {{b, d}, i};
        points[i][3] = {{-d, -b}, i};
        for(int j = 0; j<4; j++)
            st[j].insert(points[i][j]);
    }
    cout << (solve(st)?"YES":"NO") << endl;
}