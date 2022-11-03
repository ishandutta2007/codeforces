#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n;
vector<unordered_set<int>> info[1001];
vector<pair<int,int>> ans;

int main(){
    cin >> n;
    
    int cnt = 0;
    
    for(int i=1; i<=n; i++){
        string line; getline(cin, line);
        if(i == 1)getline(cin, line);
        stringstream ss(line);
        //~ cerr << "->" << line << endl;
        int lung;
        while(ss >> lung){
            //~ cerr << "* " << i << ' ' << lung << endl;
            vector<int> nuovo;
            char cc; ss >> cc;
            for(int j=0; j<lung; j++){
                int x; ss >> x;
                ss >> cc;
                nuovo.push_back(x);
            }
            info[i].emplace_back(nuovo.begin(), nuovo.end());
            cnt++;
        }
    }
    if(cnt != 2*(n-1)){
        cout << -1 << '\n';
        return 0;
    }
    //~ for(int i=1; i<=n; i++){
        //~ cout << i << '\n';
        //~ for(auto s:info[i]){
            //~ cout << " - ";
            //~ for(int x:s) cout << x << ' ';
            //~ cout << endl;
        //~ }
    //~ }
    
    unordered_set<int> nodi;
    for(int i=1; i<=n; i++) nodi.insert(i);
    while(nodi.size() > 1){
        for(int v:nodi){
            for(auto& s:info[v]) if(s.size() == 1){
                int u = *(s.begin());
                ans.emplace_back(u, v);
                nodi.erase(u);
                int note = 0;
                for(auto &t:info[u]) if(!t.empty()) note++;
                if(note != 1){
                    cout << -1 << '\n';
                    return 0;
                }
                for(int i:nodi) for(auto &t:info[i]) if(t.count(u)){
                    if(v!=i && t.count(v) == 0){
                        cout << -1 << '\n';
                        return 0;
                    }
                    t.erase(u);
                }
            }
        }
    }
    
    cout << n-1 << '\n';
    for(auto p:ans){
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}