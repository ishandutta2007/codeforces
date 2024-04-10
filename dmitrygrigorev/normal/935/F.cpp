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
int INF = -1e18, GF, GL;
struct Vertex{int l; int r; int pr; int sz; int value; int p; bool F; int S; int T; bool f; int s; int t; int g; int G;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
int n, base;
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1, L = decart[vertex].l, R = decart[vertex].r;
    decart[vertex].F = decart[vertex].f;
    decart[vertex].S = decart[vertex].s;
    decart[vertex].T = decart[vertex].t;
    decart[vertex].G = decart[vertex].g;
    if (L != -1){
        sz += decart[L].sz;
        decart[vertex].F |= decart[L].F;
        decart[vertex].S = max(decart[vertex].S, decart[L].S);
        decart[vertex].T = max(decart[vertex].T, decart[L].T);
        decart[vertex].G = max(decart[vertex].G, decart[L].G);
    }
    if (R != -1){
        sz += decart[R].sz;
        decart[vertex].F |= decart[R].F;
        decart[vertex].S = max(decart[vertex].S, decart[R].S);
        decart[vertex].T = max(decart[vertex].T, decart[R].T);
        decart[vertex].G = max(decart[vertex].G, decart[R].G);
    }
    decart[vertex].sz = sz;
}
void push(int vertex){
    if (vertex == -1) return;
    int pp = decart[vertex].p;
    decart[vertex].p = 0;
    if (decart[vertex].l != -1){
        decart[decart[vertex].l].value += pp;
        decart[decart[vertex].l].p += pp;
    }
    if (decart[vertex].r != -1){
        decart[decart[vertex].r].value += pp;
        decart[decart[vertex].r].p += pp;
    }
}
void P(int vertex, int wh){
    push(vertex);
    decart[vertex].value+=wh;
    decart[vertex].p+=wh;
}
pair<int, int> split(int father, int number){
    if (father == -1) return SP;
    push(father);
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
    push(first);
    push(second);
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
void create(int a, int b, int c){
    Vertex v = {-1, -1, rand(), 1, b, 0};
    v.S = INF;
    v.T = INF;
    v.G = INF;
    if (b >= a && b >= c) v.F = true;
    else {
        v.F = false;
        if (b >= a || b >= c){
            v.S = min(b-a, b-c);
        }
        else{
            v.T = 2*(b-a+b-c);
            v.G = 2*max(b-a, b-c);
        }
    }
    v.f = v.F;
    v.s = v.S;
    v.t = v.T;
    v.g = v.G;
    decart.push_back(v);
    base = merg(base, decart.size() - 1);
}
int Get(int vertex, int sk){
    push(vertex);
    int L = decart[vertex].l;
    int R = decart[vertex].r;
    if (L!=-1){
        int sz = decart[L].sz;
        if (sz > sk) return Get(L, sk);
        sk -= sz;
    }
    if (sk==0) return decart[vertex].value;
    return Get(R, sk-1);
}
int get(int ind){
    if (ind == 0) return GF;
    if (ind == n-1) return GL;
    return Get(base, ind-1);
}
void Ch(int dind){
    int a = get(dind);
    int b = get(dind+1);
    int c = get(dind+2);
    pair<int, int> p1 = split(base, dind);
    pair<int, int> p2 = split(p1.second, 1);
    base = p1.first;
    create(a, b, c);
    base = merg(base, p2.second);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    base = -1;
    cin >> n;
    vector<int> v;
    for (int i=0; i < n; i++){
        int value;
        cin >> value;
        v.push_back(value);
    }
    GF = v[0];
    GL = v[n-1];
    int G = 0;
    for (int i=0; i < n-1; i++) G += abs(v[i+1] - v[i]);
    for (int i=1; i < n-1; i++){
        create(v[i-1], v[i], v[i+1]);
    }
    int q;
    cin >> q;
    for (int i=0; i < q; i++){
        int t;
        cin >> t;
        if (t==1){
            int L, R, X;
            cin >> L >> R >> X;
            int ans = -2*X;
            if (L==1){
                ans = max(ans, abs(X+GF-get(1)) - abs(GF - get(1)));
            }
            if (R==n){
                ans = max(ans, abs(X+GL-get(n-2)) - abs(GL - get(n-2)));
            }
            L--;
            R--;
            L = max((int)0, L-1);
            R--;
            if (R==n-2) R--;
            pair<int, int> p1 = split(base, L);
            pair<int, int> p2 = split(p1.second, R-L+1);
            //cout << decart[p2.first].F << endl;
            if (decart[p2.first].F) ans = 2*X;
            if (decart[p2.first].S > INF){
                ans = max(ans, 2*(max((int) 0, X+decart[p2.first].S)));
            }
            ans = max(ans, 2*X+decart[p2.first].T);
            if (X*2 >= abs(decart[p2.first].G)) ans = max(ans, decart[p2.first].G);
            base = merg(p2.first, p2.second);
            base = merg(p1.first, base);
            cout << ans+G << endl;
        }
        else{
            int L, R, X;
            cin >> L >> R >> X;
            if (L==1) GF += X;
            else{
                G += abs(get(L-1) + X - get(L-2)) - abs(get(L-1) - get(L-2));
            }
            if (R==n) GL += X;
            else{
                G += abs(get(R-1) + X - get(R)) - abs(get(R-1) - get(R));
            }
            L--;
            R--;
            L = max((int)0, L-1);
            R--;
            if (R==n-2) R--;
            pair<int, int> p1 = split(base, L);
            pair<int, int> p2 = split(p1.second, R-L+1);
            P(p2.first, X);
            base = merg(p2.first, p2.second);
            base = merg(p1.first, base);
            Ch(L);
            Ch(R);
            if (L!=0) Ch(L-1);
            if (R!=n-3) Ch(R+1);
        }
    }
    return 0;
}