#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
using namespace std;
const int K = 1000;
int where[K][K];
vector<vector<bitset<K> > > data;
vector<vector<int> > graf;
vector<bool> used;
bitset<K> goblin;
void dfs(int vertex){
    used[vertex] = true;
    for (int i=0; i < graf[vertex].size(); i++){
        int to = graf[vertex][i];
        if (used[to]) continue;
        dfs(to);
    }
}
int32_t main(){
    int n;
    cin >> n;
    int comp = 0;
    for (int i=0; i < n; i++){
        vector<int> hh;
        used.push_back(false);
        graf.push_back(hh);
        vector<bitset<K> > help;
        string s;
        cin >> s;
        int u = 0;
        while (u < s.size()){
            int number = 0;
            while (s[u] != ':'){
                int symb = s[u] - '0';
                number = 10*number + symb;
                u++;
            }
            u++;
            int counter = help.size();
            bitset<K> b;
            int vertex = 0;
            while (u < s.size() && s[u] != '-'){
                if (s[u] == ','){
                    vertex--;
                    b[vertex] = 1;
                    where[i][vertex] = counter;
                    vertex = 0;
                }
                else{
                    int symb = s[u] - '0';
                    vertex = 10*vertex + symb;
                }
                u++;
            }
            vertex--;
            b[vertex] = 1;
            where[i][vertex] = counter;
            vertex = 0;
            help.push_back(b);
            comp++;
            if (comp > 2*n-2){
                cout << -1 << endl;
                return 0;
            }
            u++;
        }
        data.push_back(help);
    }
    if (comp != 2*n-2){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int> > ans;
    int rebers = 0;
    for (int i=0; i < n; i++){
        for (int j=i+1; j < n; j++){
            int ind1 = where[i][j];
            int ind2 = where[j][i];
            goblin = data[i][ind1] & data[j][ind2];
            if (goblin.none()){
                graf[i].push_back(j);
                graf[j].push_back(i);
                ans.push_back(make_pair(i, j));
                rebers++;
            }
        }
    }
    if (rebers != n-1){
        cout << -1 << endl;
        return 0;
    }
    dfs(0);
    for (int i=0; i < n; i++){
        if (!used[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n-1 << endl;
    for (int i=0; i < n-1; i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    return 0;
}