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
int n, ai, bi;
vector<vector< int > > data;
vector<int> pairs;
vector<bool> used;
vector<int> eat;
void dfs(int vertex, int now){
    used[vertex] = true;
    eat[vertex] = now;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (!used[to]){
            dfs(to, 1-now);
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    n = 2 * n;
    for (int i=0;i<n;i++){
        vector<int> help;
        used.push_back(false);
        eat.push_back(0);
        data.push_back(help);
    }
    for (int i=0;i<n;i+=2){
        data[i].push_back(i+1);
        data[i+1].push_back(i);
    }
    for (int i=0;i<n;i+=2){
        cin >> ai >> bi;;
        pairs.push_back(ai-1);
        pairs.push_back(bi-1);
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);

    }
    for (int i=0;i<n;i++){
        if (!used[i]){
            dfs(i, 0);
        }
    }
    for (int i=0;i<n;i+=2){
        int first = pairs[i];
        int second = pairs[i + 1];
        cout << eat[first] + 1 << " " << eat[second] + 1 << endl;;
    }
    return 0;

}