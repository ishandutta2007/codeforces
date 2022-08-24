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
#define int long long
using namespace std;
int counter;
int go[200001][26];
int last;
int suf[200001], len[200001], ans[200001];
bool clodne[200001];
int reb;
map<int, int> num;
string id = "abcdefghijklmnopqrstuvwxyz";
void add(int number){
    int newlast = counter; len[newlast] = len[last] + 1; int p = last; counter++;
    while (p!=-1 && go[p][number] == -1){
        go[p][number] = newlast;
        reb ++;
        p = suf[p];
    }
    if (p == -1){
        suf[newlast] = 0;
    }
    else{
        int q = go[p][number];
        if (len[q] == len[p] + 1){
            suf[newlast] = q;
        }
        else{
            int r = counter; counter ++;
            clodne[r] = true;
            for (int i=0;i<26;i++){
                go[r][i] = go[q][i];
                if (go[r][i] != -1) reb++;
            }
            suf[r] = suf[q];
            suf[q] = r;
            suf[newlast] = r;
            len[r] = len[p] + 1;
            while (p!=-1 && go[p][number] == q){
                go[p][number] = r;
                p = suf[p];
            }
        }
    }
    last = newlast;
}
int32_t main()
{
    int m;
    cin >> m;
    for (int i=0;i<m;i++){
        string s;
        cin >> s;
        for (int j=0;j<200001;j++){
            clodne[j] = false;
            ans[j] = 1;
            suf[j] = -1;
            len[j] = -1;
            for (int k=0;k<26;k++){
                go[j][k] = -1;
            }
        }
        len[0] = 0;
        counter = 1;
        last = 0;
        for (int j=0;j<s.size();j++){
            for (int k=0;k<26;k++){
                if (id[k] == s[j]) add(k);
            }
        }
        reb = 0;
        vector<vector<int> > ll;
        for (int i=1;i<counter;i++){
            if (clodne[i]){
                ans[i] = 0;
            }
        }
        for (int i=1;i<counter;i++){
            vector<int> help; help.push_back(len[i]); help.push_back(i);
            ll.push_back(help);
        }
        sort(ll.begin(), ll.end(), greater<vector<int> > ());
        for (int i=0;i<ll.size();i++){
            int v = ll[i][1];
            ans[suf[v]] += ans[v];
        }
        vector<int> in;
        vector<int> zero, sz;
        for (int i=0;i<counter;i++){
            in.push_back(0);
            sz.push_back(0);
        }
        sz[0] = 1;
        zero.push_back(0);
        for (int i=0;i<counter;i++){
            for (int j=0;j<26;j++){
                if (go[i][j] != -1) in[go[i][j]] ++;
            }
        }
        while (zero.size() > 0){
            int v = zero.back();
            if (v != 0) reb += ans[v] * ans[v] * sz[v];
            zero.pop_back();
            for (int i=0;i<26;i++){
                if (go[v][i] != -1) {
                in[go[v][i]] --;
                sz[go[v][i]] += sz[v];
                if (in[go[v][i]] == 0){
                    zero.push_back(go[v][i]);
                }
                }
            }
        }
        cout << reb << endl;
    }
    return 0;
}