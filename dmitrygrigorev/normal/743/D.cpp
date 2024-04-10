#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
vector<long long> data;
vector<vector<int> > graf;
int n, f, s;
long long ai, answer, constante;
vector<long long> dfs(int vertex, int last){
    long long ss = data[vertex];
    long long max1=constante;
    long long max2=constante;
    long long rar;
    int counter = 0;
    for (int i=0;i<graf[vertex].size();i++){
        int to = graf[vertex][i];
        if (to != last){
            counter ++;
            vector<long long> rar = dfs(to, vertex);
            long long r1 = rar[0];
            long long r2 = rar[1];
            ss += r2;
            if (max(r1, r2) > max1){
                max2 = max1;
                max1 = max(r1, r2);
            }
            else{
                if (max(r1, r2) > max2){
                    max2 = max(r1, r2);
                }
            }
        }
    }
       if (counter > 1 & answer < max1 + max2){
        answer = max1 + max2;
    }
    vector<long long> hh;
    hh.push_back(max1);
    hh.push_back(ss);
    return hh;
}
int main(){
    cin >> n;
    constante = -2000000000000;
    answer = constante;
    for (int i=0;i<n;i++){
        vector<int> help;
        cin >> ai;
        graf.push_back(help);
        data.push_back(ai);
    }
    for (int i=0;i<n-1;i++){
        cin >> f >> s;
        graf[f-1].push_back(s-1);
        graf[s-1].push_back(f-1);
    }
    dfs(0, -1);
    if (answer == constante){
        cout << "Impossible";
        return 0;
    }
    cout << answer << endl;
    return 0;
}