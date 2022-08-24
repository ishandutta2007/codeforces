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
struct Vertex{int type;int value;bool used;vector<int> go;};
int n, m, ai;
vector<Vertex> data;
bool dfs(int vertex, int please, int last){
    if (data[vertex].type == 1){
        data[vertex].used = true;
        data[vertex].value = please;
        for (int i=0;i<data[vertex].go.size();i++){
            int vv = data[vertex].go[i];
            if (vv == last) continue;
            if (data[vv].used) continue;
            bool sas = dfs(data[vertex].go[i], please, vertex);
            if (!sas){
                data[vertex].used = false;
                data[vertex].value = -1;
                return sas;
            }
        }
        return true;
    }
    else{
        data[vertex].used = true;
        int pl;
        if (please == 0 && data[vertex].value == 0){
            pl = 1;
        }
        if (please == 1 && data[vertex].value == 0){
            pl = 0;
        }
        if (please == 1 && data[vertex].value == 1){
            pl = 1;
        }
        if (please == 0 && data[vertex].value == 1){
            pl = 0;
        }
        for (int i=0;i<data[vertex].go.size();i++){
            int vv = data[vertex].go[i];
            if (vv != last){
                if (!data[vv].used){
                    bool res = dfs(vv, pl, vertex);
                    if (!res){
                        data[vertex].used = false;
                    }
                    return res;
                }
                else{
                    if (pl == data[vv].value){
                        return true;
                    }
                    else {
                            data[vertex].used = false;
                            return false;
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=0;i<n;i++){
        Vertex v;
        cin >> ai;
        v.type = 2;
        v.value = ai;
        v.used = false;
        vector<int> help;
        v.go = help;
        data.push_back(v);
    }
    for (int i=0;i<m;i++){
        int counts;
        Vertex v;
        v.type = 1;
        v.value = -1;
        v.used = false;
        vector<int> help;
        v.go = help;
        data.push_back(v);
        cin >> counts;
        int now;
        for (int j = 0;j<counts;j++){
            cin >> now;
            data[n + i].go.push_back(now - 1);
            data[now - 1].go.push_back(n + i);
        }
    }
    bool ans = true;
    for (int i=n;i<n+m;i++){
        if (data[i].used == false){
            bool res = dfs(i, 0, -1);
            if (!res){
                res = dfs(i, 1, -1);
                if (!res){
                    ans = false;
                    break;
                }
            }
        }
    }
    if (ans){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    std::ios::sync_with_stdio(false);
    return 0;
}