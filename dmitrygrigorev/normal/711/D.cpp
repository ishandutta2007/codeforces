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
vector<int> cycles;
vector<long long> ost;
vector<int> used;
vector<int> times;
long long c;
void dfs(int vertex, int length){
    times[vertex] = length;
    used[vertex] = 1;
    int to = data[vertex] - 1;
    if (used[to] == 2){
        used[vertex]=2;
        return;
    }
    if (used[to] == 1){
        cycles.push_back(times[vertex] - times[to] + 1);
        used[vertex] = 2;
        return;
    }
    if (used[to] == 0){
        dfs(to, length + 1);
    }
    used[vertex] = 2;
}
int main(){
    cin >> n;
    c = pow(10, 9) + 7;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
        used.push_back(0);
        times.push_back(0);
    }
    for (int i=0;i<n;i++){
        if (used[i]==0){
            dfs(i, 1);
        }
    }
    long long cc = 2;
    for (int i=0;i<n;i++){
        ost.push_back(cc);
        cc = (cc * 2) % c;
    }
    long long ans = 1;
    int oo = n;
    for (int i=0;i<cycles.size();i++){
        oo -= cycles[i];
        ans = (ans * (ost[cycles[i]-1] - 2)) % c;
    }
    if (oo > 0){
    ans = (ans * ost[oo-1]) % c;
    }
    cout << ans << endl;
    return 0;
}