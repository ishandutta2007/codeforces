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
struct Polina{vector<int> vertex;vector<int> go;int really;int colour;};
vector<Polina> data;
int n, m, a, b;
int fv, mv, sv, ov;
vector<int> answer;
map <int, pair<int, int> > mymap;
map<int, bool> zan;
vector<vector<int> > diagonales;
void dfs1(int vertexs, int last, int dist){
    if (dist > mv){
        mv = dist;
        fv = vertexs;
    }
    for (int i=0;i<data[vertexs].go.size();i++){
        int to = data[vertexs].go[i];
        if (to == last || data[to].colour != -1) continue;
        dfs1(to, vertexs, dist + 1);
    }
}
bool dfs2(int vertexs, int last, int dist){
    if (vertexs == sv){
        return true;
    }
    for (int i=0;i<data[vertexs].go.size();i++){
        int to = data[vertexs].go[i];
        if (to == last || data[to].colour != -1) continue;
        bool res = dfs2(to, vertexs, dist + 1);
        if (res){
            if (mv / 2 == dist){
                ov = vertexs;
            }
            return true;
        }
    }
    return false;
}
void make_centroid(int vertexs, int colours){
    mv = 0;
    fv = vertexs;
    dfs1(vertexs, -1, 0);
    mv = 0;
    sv = fv;
    dfs1(sv, -1, 0);
    if (fv == sv){
        data[vertexs].colour = colours;
        int real = data[vertexs].really;
        answer[real] = colours;
        return;
    }
    dfs2(fv, -1, 0);
    int oov = ov;
    data[oov].colour = colours;
    int real = data[oov].really;
    answer[real] = colours;
    for (int i=0;i<data[oov].go.size();i++){
        int to = data[oov].go[i];
        if (data[to].colour == -1){
            make_centroid(to, colours + 1);
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int j=0;j<n;j++){
        zan[j] = false;
    }
    for (int i=0;i<m;i++){
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if (a > b) swap(a, b);
        vector<int> help;
        if (b - a - 1 <= n - 2 - (b - a - 1)){
            help.push_back(b - a - 1);
            help.push_back(a);
            help.push_back(b);
        }
        else{
            help.push_back(n - 2 - (b - a - 1));
            help.push_back(b);
            help.push_back(a);
        }
        diagonales.push_back(help);
    }
    sort(diagonales.begin(), diagonales.end());
    for (int i=0;i<m+1;i++){
        Polina polina;
        vector<int> help, help1;
        polina.go = help;
        polina.colour = -1;
        polina.vertex = help1;
        data.push_back(polina);
    }
    int cc = 1;
    int ff;
    for (int i=0;i<m;i++){
        int firsts = diagonales[i][1];
        ff = firsts;
        int seconds = diagonales[i][2];
        int j = firsts;
        while (true){
            if (j != firsts && j != seconds){
                zan[j] = true;
            }
            data[i].vertex.push_back(j);
            if (!mymap.count(j)){
                j += 1;
            }
            else{
            data[i].go.push_back(mymap[j].second);
            data[mymap[j].second].go.push_back(i);
            j = mymap[j].first;
            }
            j = j % n;
            if (firsts < seconds){
                if (!(j >= firsts && j < seconds)){
                    break;
                }
            }
            else{
                if (!(j >= firsts || j < seconds)){
                    break;
                }
            }
        }
        data[i].vertex.push_back(seconds);
        pair<int, int> p;
        p.first = seconds;
        p.second = i;
        mymap[firsts] = p;
    }
    int counter = ff;
    bool out = false;
    while (counter < ff + n){
        if (!zan[counter % n]){
            data[m].vertex.push_back(counter % n);
        }
        if (!mymap.count(counter % n)){
            counter += 1;
        }
        else{
            data[m].go.push_back(mymap[counter % n].second);
            data[mymap[counter % n].second].go.push_back(m);
            int cl = counter;
            counter = mymap[counter % n].first;
            if (counter < cl){
                out = true;
            }
            if (out) counter += n;
        }
    }
    vector<vector<int> > sort_right;
    for (int i=0;i<m+1;i++){
        sort(data[i].vertex.begin(), data[i].vertex.end(), greater<int>());
        sort_right.push_back(data[i].vertex);
        sort_right.back().push_back(i);
    }
    sort(sort_right.begin(), sort_right.end());
    for (int i=0;i<sort_right.size();i++){
        int nn = sort_right[i].back();
        data[nn].really = i;
    }
    for (int i=0;i<=m;i++){
        answer.push_back(0);
    }
    make_centroid(0, 1);
    for (int i=0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}