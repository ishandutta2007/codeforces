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
#include <bitset>
#include <time.h>
#include <queue>
#include <deque>
#define int long long
using namespace std;
struct Vertex{int go[5]; int term;};
vector<Vertex> bor;
vector<bool> pos;
vector<int> ch;
int answer;
int add(int now, int number){
    if (bor[now].go[number] != -1){
        return bor[now].go[number];
    }
    bor[now].go[number] = bor.size();
    Vertex v;
    for (int i=0; i < 5; i++){
        v.go[i] = -1;
    }
    v.term = 0;
    bor.push_back(v);
    return bor.size() - 1;
}
void get(string s, int number, int sost){
    if (number == s.size()){
        if (pos[sost]) return;
        ch.push_back(sost);
        pos[sost] = true;
        answer += bor[sost].term;
        return;
    }
    if (s[number] != '?'){
        int g = bor[sost].go[s[number] - 'a'];
        if (g == -1) return;
        get(s, number+1, g);
    }
    else{
        get(s, number+1, sost);
        for (int i=0; i < 5; i++){
            int g = bor[sost].go[i];
            if (g == -1) continue;
            get(s, number+1, g);
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Vertex v;
    for (int i=0; i < 5; i++){
        v.go[i] = -1;
    }
    v.term = 0;
    bor.push_back(v);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        int now = 0;
        for (int j=0; j < s.size(); j++){
            now = add(now, s[j] - 'a');
        }
        bor[now].term++;
    }
    for (int i=0; i < bor.size(); i++){
        pos.push_back(false);
    }
    for (int i=0; i < m; i++){
        string s;
        cin >> s;
        answer = 0;
        get(s, 0, 0);
        cout << answer << endl;
        for (int j=0; j < ch.size(); j++){
            pos[ch[j]] = false;
        }
        ch.clear();
    }
    return 0;
}