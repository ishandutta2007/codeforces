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
int n, ai;
vector<vector<int> > data;
vector<deque<vector<int> > > lengths;
vector<deque<int> > treb, how;
vector<deque<vector<pair<int, int> > > > pluss;
vector<int> answer, where, ls;
vector<int> freem;
bool cmp(int first, int second){
    return (ls[first] > ls[second]);
}
void up(int deq){
    int wanted = 0;
    int hwanted = 0;
    for (int i=0; i < lengths[deq].size(); i++){
        wanted += treb[deq][i];
        hwanted += how[deq][i];
        wanted += hwanted * lengths[deq][i].size();
        treb[deq][i] = 0;
        how[deq][i] = 0;
        if (wanted > 0) pluss[deq][i].push_back(make_pair(wanted, lengths[deq][i].size() - 1));
    }
    for (int i=0; i < lengths[deq].size(); i++){
        int summ = 0;
        for (int j=0; j < pluss[deq][i].size(); j++){
            summ += pluss[deq][i][j].first;
        }
        int ind = 0;
        for (int j=0; j < lengths[deq][i].size(); j++){
            while (ind < pluss[deq][i].size() && pluss[deq][i][ind].second < j){
                summ -= pluss[deq][i][ind].first;
                ind++;
            }
            int num = lengths[deq][i][j];
            answer[num] += summ;
        }
    }
}
void clear_l(int ind){
    for (int i=0; i < lengths[ind].size(); i++){
        lengths[ind][i].clear();
    }
    lengths[ind].clear();
}
void clear_p(int ind){
    for (int i=0; i < pluss[ind].size(); i++){
        pluss[ind][i].clear();
    }
    pluss[ind].clear();
}
void dfs(int vertex, int sz){
    if (data[vertex].size() == 0){
        deque<vector<int> > d;
        deque<int> d1, d2;
        deque<vector<pair<int, int> > > pp;
        vector<pair<int, int> > hp;
        hp.push_back(make_pair(1, 0));
        pp.push_back(hp);
        vector<int> add1;
        add1.push_back(vertex);
        d.push_back(add1);
        d1.push_back(0);
        d2.push_back(0);
        if (freem.size() == 0){
        pluss.push_back(pp);
        lengths.push_back(d);
        treb.push_back(d2);
        how.push_back(d1);
        where[vertex] = lengths.size() - 1;
        }
        else{
            int hind = freem.back();
            freem.pop_back();
            pluss[hind] = pp;
            lengths[hind] = d;
            treb[hind] = d2;
            how[hind] = d1;
            where[vertex] = hind;
        }
        return;
    }
    dfs(data[vertex][0], sz+1);
    int hero = data[vertex][0];
    int when = 0;
    if (data[vertex].size() > 1){
        when = ls[data[vertex][1]] - sz;
    }
    int heros = where[hero];
    where[vertex] = heros;
    int wanted = 0;
    int hwanted = 0;
    for (int i=0; i < when; i++){
        wanted += treb[heros][i];
        hwanted += how[heros][i];
        wanted += hwanted * lengths[heros][i].size();
        treb[heros][i] = 0;
        how[heros][i] = 0;
        if (wanted > 0) pluss[heros][i].push_back(make_pair(wanted, lengths[heros][i].size() - 1));
    }
    if (when != lengths[heros].size()){
        treb[heros][when] += wanted;
        how[heros][when] += hwanted;
    }
    for (int i=1; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to, sz+1);
        int tt = where[to];
        up(tt);
        for (int j=0; j < lengths[tt].size(); j++){
            for (int k=0; k < lengths[tt][j].size(); k++){
                lengths[heros][j].push_back(lengths[tt][j][k]);
            }
        }
        clear_l(tt);
        clear_p(tt);
        treb[tt].clear();
        how[tt].clear();
        freem.push_back(tt);
    }
    vector<int> d;
    vector<pair<int, int> > pp;
    pluss[heros].push_front(pp);
    d.push_back(vertex);
    lengths[heros].push_front(d);
    treb[heros].push_front(0);
    how[heros].push_front(0);
    when++;
    int nn = 0;
    for (int i=0; i < when; i++){
        nn += lengths[heros][i].size();
        pluss[heros][i].push_back(make_pair(nn, lengths[heros][i].size()-1));
    }
    if (when != lengths[heros].size()){
        treb[heros][when] += nn;
        how[heros][when]++;
    }
}
void dfs3(int vertex, int ll){
    answer[vertex] -= ll;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs3(to, ll+1);
    }
}
int dfs2(int vertex, int ll){
    int mm = ll;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        mm = max(mm, dfs2(to, ll+1));
    }
    ls[vertex] = mm;
    return mm;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        answer.push_back(0);
        where.push_back(-1);
        ls.push_back(-1);
    }
    int dyr;
    for (int i=0; i < n; i++){
        cin >> ai;
        if (ai == 0){
            dyr = i;
            continue;
        }
        data[ai-1].push_back(i);
    }
    dfs2(dyr, 1);
    for (int i=0; i < n; i++){
        sort(data[i].begin(), data[i].end(), cmp);
    }
    dfs(dyr, 1);
    up(where[dyr]);
    dfs3(dyr, 1);
    for (int i=0; i < n; i++){
        cout << answer[i] << " ";
    }
    return 0;
}