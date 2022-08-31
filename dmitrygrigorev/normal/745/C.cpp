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
int n, m, k, ai, bi;
long long answer;
vector<int> capitals;
vector<bool> used;
vector<int> comp;
vector<vector<int > > data;
void dfs(int vertex, int counter){
    used[vertex] = true;
    comp[counter] ++;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        if (!used[to]){
            dfs(to, counter);
        }
    }
}
int main(){
    cin >> n >> m >> k;
    answer = 0;
    for (int i=0;i<n;i++){
        used.push_back(false);
        vector<int> help;
        data.push_back(help);
    }
    for (int i=0;i<k;i++){
        cin >> ai;
        capitals.push_back(ai-1);
    }
    for (int i=0;i<m;i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    for (int i=0;i<k;i++){
        comp.push_back(0);
        dfs(capitals[i], i);
    }
    sort(comp.begin(), comp.end());
    int summ = 0;
    for (int i=0;i<k;i++){
        summ += comp[i];
    }
    int aaa = n - summ;
    comp[k-1] += aaa;
    for (int i=0;i<k;i++){
        answer += comp[i] * (comp[i] - 1) / 2;
    }
    cout << answer - m << endl;
    return 0;
}