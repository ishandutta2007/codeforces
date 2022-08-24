#include <bits/stdc++.h>
using namespace std;
struct Bor{int v[26]; int ind;};
vector<Bor> bor;
vector<deque<pair<int, int> > > data;
void construct(){
    Bor nb;
    for (int i=0; i < 26; i++) nb.v[i] = -1;
    nb.ind=-1;
    bor.push_back(nb);
}
void Add(pair<int, int> a, int ind){
    if (a.first == 0) data[ind].push_front(a);
    else data[ind].push_back(a);
}
int add(int now, int symb){
    if (bor[now].v[symb] == -1){
        construct();
        bor[now].v[symb] = bor.size() - 1;
    }
    return bor[now].v[symb];
}
vector<pair<int, int> > ans;
int Ans=0;
bool cmp(int a, int b){
    return (data[a].size() > data[b].size());
}
void dfs(int vertex, int Len){
    vector<int> indexes = {};
    if (bor[vertex].ind != -1) indexes.push_back(bor[vertex].ind);
    for (int i=0; i < 26; i++){
        int to = bor[vertex].v[i];
        if (to==-1) continue;
        dfs(to, Len+1);
        indexes.push_back(bor[to].ind);
    }
    sort(indexes.begin(), indexes.end(), cmp);
    //cout << 123 << endl;
    for (int i=1; i < indexes.size(); i++){
        int h = indexes[i];
        for (int j=0; j < data[h].size(); j++){
            Add(data[h][j], indexes[0]);
        }
    }
    int I = indexes[0];
    while (data[I].size() > 1){
        //cout << data[I].size() << endl;
        if (data[I][0].first == data[I].back().first) break;
        ans.push_back({data[I][0].second, data[I].back().second});
        Ans += Len;
        data[I].pop_front(), data[I].pop_back();
    }
    //cout << 345 << endl;
    bor[vertex].ind = I;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    construct();
    for (int i=0; i < 2*n; i++){
        int now = 0;
        string s;
        cin >> s;
        for (int j=0; j < s.size(); j++) now = add(now, s[j] - 'a');
        int ii = bor[now].ind;
        if (ii==-1){
            data.push_back({});
            bor[now].ind = data.size() - 1;
            ii = data.size() - 1;
        }
        Add({i/n, i%n}, ii);
    }
    dfs(0, 0);
    cout << Ans << endl;
    for (int i=0;i<ans.size(); i++) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    return 0;
}