#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=101;
bool m1[MAX_N];
int n;
vector<pair<int,int> > v;
//vector<int> adj[MAX_N];
bool dfs(int s, int u){
    if(s==u) return true;
    m1[s]=true;
    for(int i=0; i<v.size(); i++){
        if(!m1[i] && ((v[s].first > v[i].first && v[s].first < v[i].second) || (v[s].second > v[i].first && v[s].second < v[i].second))){
            if(dfs(i,u)) return true;
        }
    }
    return false;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1) v.emplace_back(b,c);
        else{
            fill(m1,m1+MAX_N,false);
            if(dfs(b-1,c-1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}