#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double PI = 3.14159265358979;
struct angle{double val; int ind; bool change;};
struct el{int L; int R; double ch;};
bool cmp(angle &a, angle &b){
    return (a.val < b.val);
}
vector<bool> used;
vector<pair<int, int> > pol, ug;
int n, X=0, Y=0;
vector<angle> v;
vector<bool> ans;
void dfs(int vertex, bool ch){
    ch ^= v[vertex].change;
    used[vertex] = true;
    if (vertex < n){
        ans[v[vertex].ind] = ch;
        if (ch) X += ug[v[vertex].ind].first;
        if (ch) Y += ug[v[vertex].ind].second;
        if (!ch) X -= ug[v[vertex].ind].first;
        if (!ch) Y -= ug[v[vertex].ind].second;
        return;
    }
    dfs(pol[vertex].first, ch);
    dfs(pol[vertex].second, ch);
}
signed main() {
    //freopen("1.txt", "r", stdin);
    //srand(time(NULL));
    cin >> n;
    for (int i=0; i < n; i++){
        ans.push_back(true);
        int x, y;
        cin >> x >> y;
        ug.push_back({x, y});
        double ang = atan2(y, x);
        bool ch = false;
        if (ang < 0){
            ang += PI;
            ch = true;
        }
        //cout << x << " " << y << " " << ang << endl;
        v.push_back({ang, i, ch});
        pol.push_back(make_pair(-1, -1));
    }
    if (n==1){
        cout << 1;
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    vector<el> dv;
    set<pair<double, int> > best;
    set<pair<double, int> > angs;
    for (int i=0; i < n; i++){
        angs.insert({v[i].val, i});
        double diff = v[(i+1+n)%n].val - v[i].val;
        if (diff < 0) diff += PI;
        best.insert({diff, i});
        dv.push_back({(i-1+n)%n, (i+1+n)%n, diff});
    }
    int cur = n;
    for (int e=0; e < n-2; e++){
        pair<double, int> b = *best.begin();
        int B = b.second;
        int A = dv[B].L;
        int C = dv[B].R;
        int D = dv[C].R;
        pol.push_back({B, C});
        pair<double, int> gg = *angs.begin();
        int bee = gg.second;
        angs.erase(angs.find({v[B].val, B}));
        angs.erase(angs.find({v[C].val, C}));
        best.erase(best.find({dv[A].ch, A}));
        best.erase(best.find({dv[B].ch, B}));
        best.erase(best.find({dv[C].ch, C}));
        double diff = v[D].val - v[A].val;
        if (diff < 0) diff += PI;
        best.insert({diff, A});
        dv[A].ch = diff;
        dv[A].R = D;
        dv[D].L = A;
        double g;
        //cout << v[B].change << endl;
        if (bee != C){
            v[B].change ^= 1;
        }
        int BB=v[B].ind, CC=v[C].ind;
        int aaa = -(2*v[B].change-1), bbb = -(2*v[C].change-1);
        ug.push_back({aaa*ug[BB].first + bbb*ug[CC].first, aaa*ug[BB].second + bbb*ug[CC].second});
        g = atan2(ug[cur].second, ug[cur].first);
        bool ch = false;
        if (g < 0){
            g += PI;
            ch = true;
        }
        v.push_back({g, cur, ch});
        set<pair<double, int> > ::iterator it = angs.upper_bound({g, -1});
        int nd;
        if (it == angs.end()){
            pair<double, int> pp = *angs.begin();
            nd = pp.second;
        }
        else{
            pair<double, int> pp = *it;
            nd = pp.second;
        }
        int H = dv[nd].L;
        best.erase(best.find({dv[H].ch, H}));
        double AA = g - v[H].val;
        if (AA < 0) AA += PI;
        double BBH = v[nd].val - g;
        if (BBH < 0) BBH += PI;
        best.insert({AA, H});
        best.insert({BBH, cur});
        dv.push_back({H, nd, BBH});
        dv[H].R = cur;
        dv[nd].L = cur;
        dv[H].ch = AA;
        angs.insert({g, cur});
        cur++;
    }
    pair<double, int> gg = *angs.begin();
    int bee = gg.second;
    pair<double, int> ppp = *best.begin();
    if (bee == ppp.second) v[ppp.second].change ^= 1;
    for (int i=0; i < dv.size(); i++) used.push_back(false);
    for (int i=dv.size() - 1; i >= 0; i--){
        if (!used[i]){
            dfs(i, 0);
        }
    }
    for (int i=0; i < n; i++){
        if (ans[i]) cout << 1 << " ";
        else cout << -1 << " ";
    }
    //cout << X << " " << Y;
    return 0;
}