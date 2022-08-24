#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int> > Data;
vector<int> value;
vector<string> tp;
vector<pair<int, int> > ans;
void dfs(int vertex, pair<int, int> p){
    //cout << vertex << endl;
    if (Data[vertex].size() == 0){
        if (value[vertex] == 0) ans.push_back(make_pair(vertex, p.second));
        else ans.push_back(make_pair(vertex, p.first));
        return;
    }
    if (Data[vertex].size() == 1){
        dfs(Data[vertex][0], make_pair(p.second, p.first));
        return;
    }
    int rs = value[Data[vertex][1]];
    int A[2];
    for (int i=0; i < 2; i++){
        int X;
        if (tp[vertex] == "AND") X = (rs&i);
        if (tp[vertex] == "OR") X = (rs|i);
        if (tp[vertex] == "XOR") X = (rs^i);
        if (X==0) A[i] = p.first;
        else A[i] = p.second;
    }
    dfs(Data[vertex][0], make_pair(A[0], A[1]));
    rs = value[Data[vertex][0]];
    for (int i=0; i < 2; i++){
        int X;
        if (tp[vertex] == "AND") X = (rs&i);
        if (tp[vertex] == "OR") X = (rs|i);
        if (tp[vertex] == "XOR") X = (rs^i);
        if (X==0) A[i] = p.first;
        else A[i] = p.second;
    }
    dfs(Data[vertex][1], make_pair(A[0], A[1]));
}
int calc(int vertex){
    if (Data[vertex].size() == 0) return value[vertex];
    if (Data[vertex].size() == 1){
        int res = calc(Data[vertex][0]);
        value[vertex] = 1-res;
        return value[vertex];
    }
    int a = calc(Data[vertex][0]), b = calc(Data[vertex][1]);
    if (tp[vertex] == "AND") value[vertex] = (a&b);
    if (tp[vertex] == "OR") value[vertex] = (a|b);
    if (tp[vertex] == "XOR") value[vertex] = (a^b);
    return value[vertex];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        Data.push_back({});
        tp.push_back(s);
        if (s!="IN"){
            value.push_back(-1);
            if (s != "NOT"){
                int a, b;
                cin >> a >> b;
                Data[i].push_back(a-1);
                Data[i].push_back(b-1);
            }
            else{
                int a;
                cin >> a;
                Data[i].push_back(a-1);
            }
        }
        else{
            int nn;
            cin >> nn;
            value.push_back(nn);
        }
    }
    calc(0);
    dfs(0, {0, 1});
    sort(ans.begin(), ans.end());
    for (int i=0; i < ans.size(); i++) cout << ans[i].second;
    return 0;
}