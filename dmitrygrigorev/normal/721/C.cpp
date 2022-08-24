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
vector<vector< vector < double> > > data;
vector<vector< double> > dynamics;
vector<int> answer;
vector<bool> used;
int n, m;
double t;
double constante = 1300000000;
void first_dfs(double vertex, double money){
    if (vertex == n - 1){
        dynamics[vertex][0] = 0;
        used[vertex] = true;
        return;
    }
    else{
        used[vertex] = true;
        for (int i=0;i<data[vertex].size();i++){
            double to = data[vertex][i][0];
            double d = data[vertex][i][1];
                if (!used[to]){
                    first_dfs(to, money + d);
                }
                for (int i=0;i<m;i++){
                    if (dynamics[to][i] != constante){
                        dynamics[vertex][i+1] = min(dynamics[vertex][i+1], dynamics[to][i] + d);
                    }
                }
        }
    }
}
void second_dfs(double vertex, double den){
    answer.push_back(vertex);
    if (vertex == n-1){
        return;
    }
    int maximum = -1;
    for (int i=0;i<m+1;i++){
        double money = dynamics[vertex][i];
        if (money <= den){
            maximum = i;
        }
    }
    for (int i=0;i<data[vertex].size();i++){
        double to = data[vertex][i][0];
        double mm = data[vertex][i][1];
        if (dynamics[to][maximum - 1] <= den - mm){
            second_dfs(to, den - mm);
            return;
        }
    }

}
int main(){
    std::ios::sync_with_stdio(false);
    double ui, vi, ti;
    cin >> n >> m >> t;
    for (int i=0;i<n;i++){
        used.push_back(false);
        vector<vector<double> > help;
        data.push_back(help);
        vector<double> h;
        for (int j=0;j<m+1;j++){
        h.push_back(constante);
        }
        dynamics.push_back(h);
    }
    for (int i=0;i<m;i++){
        cin >> ui >> vi >> ti;
        vector<double> help;
        help.push_back(vi - 1);
        help.push_back(ti);
        data[ui - 1].push_back(help);
    }
    first_dfs(0, 0);
    second_dfs(0, t);
    cout << answer.size() << endl;
    for (int i=0;i<answer.size();i++){
        cout << answer[i] +1<< " ";
    }
    return 0;
}