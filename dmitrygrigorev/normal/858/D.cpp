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
using namespace std;
struct V{int go[10]; bool twice; int who;};
vector<V> bor;
int ans;
string str;
int add(int vertex, int s){
    if (bor[vertex].go[s] != -1){
        return bor[vertex].go[s];
    }
    else{
        V v;
        for (int i=0; i < 10; i++){
            v.go[i] = -1;
        }
        v.twice = false;
        v.who = -1;
        bor.push_back(v);
        bor[vertex].go[s] = bor.size() - 1;
        return bor.size() - 1;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    V v;
    for (int i=0; i < 10; i++){
        v.go[i] = -1;
    }
    v.twice = false;
    v.who = -1;
    bor.push_back(v);
    vector<string> vv;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        vv.push_back(s);
        for (int st=0; st < 9; st++){
            int now = 0;
            for (int j=st; j < 9; j++){
                now = add(now, s[j] - '0');
                if (bor[now].who == -1){
                    bor[now].who = i;
                }
                else if (bor[now].who != i){
                    bor[now].twice = true;
                }
            }
        }
    }
    for (int i=0; i < n; i++){
        ans = 100;
        string stra;
        for (int j=0; j < 9; j++){
            str = "";
            int now = 0;
            for (int k=j; k < 9; k++){
                str += vv[i][k];
                now = bor[now].go[vv[i][k] - '0'];
                if (!bor[now].twice){
                    if (str.size() < ans){
                        ans = str.size();
                        stra = str;
                    }
                    break;
                }
            }
        }
        cout << stra << endl;
    }
    return 0;
}