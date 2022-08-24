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
int n, x;
vector<int> data;
vector<int> cycles;
vector<int> used;
bool bad;
int c;
int nok(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return nok(b, a%b);
    }
}
int nod(int a, int b){
    return a * b / nok(a, b);
}
void dfs(int vertex, int mass, int start){
    used[vertex] = c;
    int to = data[vertex];
    if (used[to] != c & used[to] != 0){
        bad = true;
    }
    else{
        if (to == vertex & mass > 1){
            bad = true;
            return;
        }
        if (used[to] == c){
                if (to == start){
            c ++;
            cycles.push_back(mass);
            return;
                }
                else{
                    bad = true;
                    return;
                }
        }
        dfs(to, mass+1, start);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    c = 1;
    bad = false;
    for (int i=0;i<n;i++){
        cin >> x;
        used.push_back(0);
        data.push_back(x - 1);
    }
    for (int i=0;i<n;i++){
        if (used[i] == 0){
            dfs(i, 1, i);
        }
    }
    if (bad){
        bool h = true;
        for (int i=0;i<n;i++){
            if (data[i] != i){
                h = false;
            }
        }
        if (h){
            cout << 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        for (int i=0;i<cycles.size();i++){
            if (cycles[i] % 2 == 0){
                cycles[i] = cycles[i] / 2;
            }
        }
        int a = cycles[0];
        for (int i=1;i<cycles.size();i++){
            a = nod(a, cycles[i]);
        }
        cout << a << endl;

    }
    return 0;

}