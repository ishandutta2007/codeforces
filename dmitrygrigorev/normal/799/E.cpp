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
struct Vertex{int left; int right; int prior; int value; int counts; int summ;};
vector<Vertex> decart;
vector<int> moneys, boys, girls, coop;
vector<bool> bu, gu;
int CONST = pow(10, 18);
int n, m, k, ai, b, g;
void update(int vertex){
    if (vertex == -1){
        return;
    }
    int c = 1;
    long long ss = decart[vertex].value;
    if (decart[vertex].left != -1){
        c += decart[decart[vertex].left].counts;
        ss += decart[decart[vertex].left].summ;
    }
    if (decart[vertex].right != -1){
        c += decart[decart[vertex].right].counts;
        ss += decart[decart[vertex].right].summ;
    }
    decart[vertex].counts = c;
    decart[vertex].summ = ss;
}
pair<int, int> split(int f, int k){
    if (f == -1){
        pair<int, int> p;
        p.first = -1;
        p.second = -1;
        return p;
    }
    update(f);
    int l;
    if (decart[f].left == -1) l = 0;
    else l = decart[decart[f].left].counts;
    if (l >= k){
        pair<int, int> p = split(decart[f].left, k);
        decart[f].left = p.second;
        update(f);
        p.second = f;
        return p;
    }
    pair<int, int> p = split(decart[f].right, k - l - 1);
    decart[f].right = p.first;
    p.first = f;
    update(f);
    return p;
}
int merges(int first, int second){
    update(first);
    update(second);
    if (first == -1){
        return second;
    }
    if (second == -1){
        return first;
    }
    if (decart[first].prior > decart[second].prior){
        decart[first].right = merges(decart[first].right, second);
        update(first);
        update(second);
        return first;
    }
    decart[second].left = merges(first, decart[second].left);
    update(first);
    update(second);
    return second;
}
int get_answer(int vertex, int d){
    update(vertex);
    if (vertex == -1) return 0;
    if (decart[vertex].value >= d) return get_answer(decart[vertex].left, d);
    int ll = 0;
    if (decart[vertex].left != -1){
        update(decart[vertex].left);
        ll = decart[decart[vertex].left].counts;
    }
    return ll + 1 + get_answer(decart[vertex].right, d);
}
int add_vertex(int vertex, int number){
    int nn = get_answer(vertex, number);
    pair<int, int> p = split(vertex, nn);
    Vertex v;
    v.counts = 1;
    v.left = -1;
    v.prior = rand();
    v.right = -1;
    v.value = number;
    v.summ = number;
    decart.push_back(v);
    int b1 = merges(p.first, decart.size() - 1);
    b1 = merges(b1, p.second);
    return b1;
}
int re_vertex(int vertex, int number){
    int nn = get_answer(vertex, number);
    pair<int, int> p = split(vertex, nn);
    pair<int, int> p1 = split(p.second, 1);
    return merges(p.first, p1.second);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        cin >> ai;
        moneys.push_back(ai);
        bu.push_back(false);
        gu.push_back(false);
    }
    cin >> b;
    for (int i=0;i<b;i++){
        cin >> ai;
        bu[ai-1] = true;
    }
    cin >> g;
    for (int i=0;i<g;i++){
        cin >> ai;
        gu[ai - 1] = true;
    }
    if (b > g){
        swap(b, g);
        swap(bu, gu);
    }
    int base = -1;
    int answer = 0;
    for (int i=0;i<n;i++){
        if (gu[i] && bu[i]) {coop.push_back(moneys[i]); answer += moneys[i];}
        else{
            if (gu[i]) girls.push_back(moneys[i]);
            if (bu[i]) boys.push_back(moneys[i]);
            base = add_vertex(base, moneys[i]);
        }
    }
    sort(coop.begin(), coop.end());
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int sz = coop.size();
    int last = sz - 1;
    int ans = CONST;
    for (int i=0;i<=boys.size();i++){
        if (i > 0){
            answer += boys[i-1];
            answer += girls[i-1];
            base = re_vertex(base, boys[i-1]);
            base = re_vertex(base, girls[i-1]);
        }
        int nole = 0;
        int ost = max(nole, k - i);
        if (sz < ost) continue;
        for (int j=last;j>=ost;j--){
            answer -= coop[j];
            base = add_vertex(base, coop[j]);
        }
        last = min(sz - 1, ost - 1);
        if (k + i > m) break;
        pair<int, int> p = split(base, m - k - i);
        if (p.first != -1){
            ans = min(ans, answer + decart[p.first].summ);
        }
        else{
            ans = min(ans, answer);
        }
        merges(p.first, p.second);
    }
    if (ans == CONST) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}