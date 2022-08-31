#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Vertex{int go[26]; bool have;};
int n, ans;
vector<Vertex> bor;
vector<deque<int> > vd;
void create(){
    Vertex v;
    for (int i=0; i < 26; i++) v.go[i] = -1;
    v.have = false;
    bor.push_back(v);
}
int add(int sost, int ind){
    if (bor[sost].go[ind] == -1){
        create();
        bor[sost].go[ind] = bor.size() - 1;
    }
    return bor[sost].go[ind];
}
bool cmp(int a, int b) {return (vd[a].size() > vd[b].size());}
int dfs(int vertex){
    vector<int> v;
    for (int i=0; i < 26; i++){
        if (bor[vertex].go[i] == -1) continue;
        int dr = dfs(bor[vertex].go[i]);
        v.push_back(dr);
    }
    sort(v.begin(), v.end(), cmp);
    if (!v.size()){
        deque<int> dd;
        dd.push_back(1);
        vd.push_back(dd);
        return vd.size() - 1;
    }
    for (int i=1; i < v.size(); i++){
        for (int j=0; j < vd[v[i]].size(); j++){
            vd[v[0]][j] += vd[v[i]][j];
        }
    }
    vd[v[0]].push_front(bor[vertex].have);
    if (vertex==0) return v[0];
    if (!bor[vertex].have){
        vd[v[0]][0]++;
        vd[v[0]].back()--;
        while (!vd[v[0]].back()) vd[v[0]].pop_back();
    }
    return v[0];
}
int32_t main()
{
    cin >> n;
    create();
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        int sost = 0;
        for (int j=0; j < s.size(); j++){
            sost = add(sost, s[j] - 'a');
        }
        bor[sost].have = true;
    }
    ans = 0;
    int ibor = dfs(0);
    for (int i=0; i < vd[ibor].size(); i++){
        ans += i * vd[ibor][i];
    }
    cout << ans;
}