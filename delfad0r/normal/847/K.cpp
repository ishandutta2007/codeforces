#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, k, f;
map<pair<string,string>, int> costo;

//~ pair<string,string> myp(string x, string y){
    //~ return {min(
//~ }

int main(){
    cin >> n >> a >> b >> k >> f;
    string last = "";
    for(int i=0; i<n; i++){
        string x,y; cin >> x >> y;
        if(x == last) costo[{min(x,y),max(x,y)}]+=b;
        else costo[{min(x,y),max(x,y)}]+=a;
        last = y;
    }
    vector<int> g;
    for(auto &p:costo){
        //~ cerr << p.first.first << ' ' << p.first.second << ' ' << p.second << endl;
        g.push_back(p.second);
    }
    sort(g.begin(), g.end());
    int m=g.size();
    for(int i=1; i<=k; i++) if(m-i >= 0 && g[m-i]>f) g[m-i] = f;
    int ans = 0;
    for(int i=0; i<m; i++) ans += g[i];
    cout << ans << '\n';
    return 0;
}