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
using namespace std;
int n, a, b;
vector<vector<int> > data;
vector<int> answer;
void dfs(int vertex, int lc, int colour, int last){
    answer[vertex] = colour;
    int now_colour = 1;
    for (int i=0;i<data[vertex].size();i++){
        if (data[vertex][i] == last) continue;
        while (now_colour == lc || now_colour == colour){
            now_colour ++;
        }
        dfs(data[vertex][i], colour, now_colour, vertex);
        now_colour ++;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        vector<int> help;
        answer.push_back(0);
        data.push_back(help);
    }
    for (int i=0;i<n-1;i++){
        cin >> a >> b;
        data[a - 1].push_back(b - 1);
        data[b - 1].push_back(a - 1);
    }
    int ms = 0;
    int mv;
    for (int i=0;i<n;i++){
        if (data[i].size() > ms){
            ms = data[i].size();
            mv = i;
        }
    }
    cout << ms + 1 << endl;
    dfs(mv, -1, 1, -1);
    for (int i=0;i<n;i++){
        cout << answer[i] << " ";
    }
    return 0;
}