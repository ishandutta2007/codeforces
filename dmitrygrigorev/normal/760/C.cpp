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
int n, ai;
vector<int> data;
vector<bool> used;
void dfs(int vertex){
    used[vertex] = true;
    int to = data[vertex];
    if (!used[to]){
        dfs(to);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai - 1);
    }
    int summ = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        summ += ai;
        used.push_back(false);
    }
    int answer = 0;
    if (summ % 2 == 0){
        answer ++;
    }
    int counter = 0;
    for (int i=0;i<n;i++){
        if (!used[i]){
            dfs(i);
            counter ++;
        }
    }
    if (counter == 1){
        cout << answer << endl;
    }
    else{
        cout << answer + counter << endl;
    }
    return 0;
}