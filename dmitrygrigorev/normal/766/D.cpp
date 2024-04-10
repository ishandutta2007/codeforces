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
struct Polina{string str;int father;int ant;int r;};
vector<Polina> data;
int n, m, q, o;
set<string> s1, s2;
string s, ss;
map<string, int> mm;
int get(int vertex){
    if (data[vertex].father == vertex) return vertex;
    data[vertex].father = get(data[vertex].father);
    return data[vertex].father;
}
int u(int first, int second){
    if (first == -1) return second;
    if (second == -1) return first;
    if (data[first].r < data[second].r){
        data[first].father = second;
        return second;
    }
    if (data[first].r > data[second].r){
        data[second].father = first;
        return first;
    }
    if (data[first].r == data[second].r){
        data[first].father = second;
        data[second].r ++;
        return second;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        cin >> s;
        mm[s] = i;
        Polina polina;
        polina.str = s;
        polina.father = i;
        polina.r = 1;
        polina.ant = -1;
        data.push_back(polina);
    }
    for (int i=0;i<m;i++){
        cin >> o >> s >> ss;
        if (o == 1){
            if (data[get(mm[s])].ant == get(mm[ss])) {cout << "NO" << endl;continue;}
            cout << "YES" << endl;
            int ff = get(mm[s]);
            int jj = get(mm[ss]);
            int vv = u(ff, jj);
            int vvv = u(data[ff].ant, data[jj].ant);
            data[vv].ant = vvv;
            data[vvv].ant = vv;
        }
        else{
            if (get(mm[s]) == get(mm[ss])) {cout << "NO" << endl;continue;}
            cout << "YES" << endl;
            if (data[get(mm[s])].ant == get(mm[ss])) continue;
            int ff = get(mm[s]);
            int jj = get(mm[ss]);
            int vv = u(ff, data[jj].ant);
            int vvv = u(jj, data[ff].ant);
            data[vv].ant = vvv;
            data[vvv].ant = vv;
        }
    }
    for (int i=0;i<q;i++){
        cin >> s >> ss;
        if (get(mm[s]) == get(mm[ss])) {cout << 1 << endl; continue;}
        if (get(mm[s]) == data[get(mm[ss])].ant){cout <<2 <<endl; continue;}
        cout << 3 << endl;
    }
    return 0;
}