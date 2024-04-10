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
#define int long long
using namespace std;
const int K = 62;
struct Vertex{int l; int r; int pr; int sz; int value; bitset<K> b;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
map<char, int> mm;
map<int, char> MM;
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    int L = decart[vertex].l, R = decart[vertex].r;
    int LSZ = 0;
    if (L != -1){
        sz += decart[L].sz;
    }
    if (R != -1){
        sz += decart[R].sz;
    }
    decart[vertex].sz = sz;
    bitset<K> B;
    B[decart[vertex].value] = 1;
    if (L != -1) B |= decart[L].b;
    if (R != -1) B |= decart[R].b;
    decart[vertex].b = B;
}
Vertex g(char val){
    Vertex nv = {-1, -1, rand(), 1, mm[val]};
    decart.push_back(nv);
    update(decart.size() - 1);
}
pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    int l = 1;
    if (decart[father].l != -1){
        l += decart[decart[father].l].sz;
    }
    if (l <= number){
        pair<int, int> p = split(decart[father].r, number - l);
        decart[father].r = p.first;
        p.first = father;
        update(father);
        return p;
    }
    pair<int, int> p = split(decart[father].l, number);
    decart[father].l = p.second;
    p.second = father;
    update(father);
    return p;
}
int merg(int first, int second){
    if (first == -1) return second;
    if (second == -1) return first;
    if (decart[first].pr >= decart[second].pr){
        int v = merg(decart[first].r, second);
        decart[first].r = v;
        update(first);
        return first;
    }
    int v = merg(first, decart[second].l);
    decart[second].l = v;
    update(second);
    return second;
}
int down(int b, int ind){
    int sz = 0;
    int L = decart[b].l, R = decart[b].r;
    if (L != -1) sz = decart[L].sz;
    if (decart[b].value == ind) return sz;
    if (L == -1) return sz+1 + down(R, ind);
    if (decart[L].b[ind]) return down(L, ind);
    else return sz+1 + down(R, ind);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < 10; i++){
        char o = '0' + i;
        mm[o] = i;
        MM[i] = o;
    }
    for (int i=0; i < 26; i++){
        char o = 'a' + i;
        mm[o] = i+10;
        MM[i+10] = o;
        char t = 'A' + i;
        mm[t] = i+36;
        MM[i+36] = t;
    }
    string s;
    cin >> s;
    int base = -1;
    for (int i=0; i < s.size(); i++){
        g(s[i]);
        base = merg(base, decart.size() - 1);
    }
    for (int i=0; i < m; i++){
        int l, r;
        char ch;
        cin >> l >> r >> ch;
        int ind = mm[ch];
        pair<int, int> p = split(base, l-1);
        pair<int, int> p1 = split(p.second, r-l+1);
        int N = p1.first;
        while (N != -1 && decart[N].b[ind]){
            int I = down(N, ind);
            pair<int, int> p2 = split(N, I);
            pair<int, int> p3 = split(p2.second, 1);
            N = merg(p2.first, p3.second);
        }
        base = merg(p.first, N);
        base = merg(base, p1.second);
    }
    while (base != -1){
        pair<int, int> p = split(base, 1);
        cout << MM[decart[p.first].value];
        base = p.second;
    }
    return 0;
}