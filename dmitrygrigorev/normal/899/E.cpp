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
struct Vertex{int l; int r; int pr; int sz; int value; int lc; int ln; int rc; int rn; int ind; int C;};
vector<Vertex> decart;
pair<int, int> SP = make_pair(-1, -1);
void update(int vertex){
    if (vertex == -1) return;
    int sz = 1;
    int L = decart[vertex].l, R = decart[vertex].r;
    int LSZ = 0;
    if (L != -1){
        LSZ = decart[L].sz;
        sz += decart[L].sz;
    }
    if (R != -1){
        sz += decart[R].sz;
    }
    decart[vertex].sz = sz;
    if (L != -1){
        decart[vertex].lc = decart[L].lc;
        decart[vertex].ln = decart[L].ln;
        if (decart[L].ln == decart[L].sz){
            if (decart[vertex].value == decart[vertex].lc) {
                decart[vertex].ln++;
                if (R != -1 && decart[R].lc == decart[vertex].lc) decart[vertex].ln += decart[R].ln;
            }
        }
    }
    else{
        decart[vertex].lc = decart[vertex].value;
        decart[vertex].ln = 1;
        if (R != -1 && decart[R].lc == decart[vertex].lc) decart[vertex].ln += decart[R].ln;
    }
    if (R != -1){
        decart[vertex].rc = decart[R].rc;
        decart[vertex].rn = decart[R].rn;
        if (decart[R].rn == decart[R].sz){
            if (decart[vertex].value == decart[vertex].rc) {
                decart[vertex].rn++;
                if (L != -1 && decart[L].rc == decart[vertex].rc) decart[vertex].rn += decart[L].rn;
            }
        }
    }
    else{
        decart[vertex].rc = decart[vertex].value;
        decart[vertex].rn = 1;
        if (L != -1 && decart[L].rc == decart[vertex].rc) decart[vertex].rn += decart[L].rn;
    }
    int var = 1;
    int sdv = 0;
    int num = decart[vertex].value;
    if (L != -1 && decart[L].rc == num){
        var += decart[L].rn;
        sdv = decart[L].rn;
    }
    if (R != -1 && decart[R].lc == num) var += decart[R].ln;
    decart[vertex].ind = LSZ - sdv;
    decart[vertex].C = var;
    if (L != -1 && decart[L].C >= decart[vertex].C){
        decart[vertex].C = decart[L].C;
        decart[vertex].ind = decart[L].ind;
    }
    if (R != -1 && decart[R].C > decart[vertex].C){
        decart[vertex].C = decart[R].C;
        decart[vertex].ind = decart[R].ind + LSZ + 1;
    }
}
Vertex g(int val){
    Vertex nv = {-1, -1, rand(), 1, val, -1, -1, -1, -1, -1, -1};
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
int32_t main(){
    int n;
    cin >> n;
    int base = -1;
    for (int i=0; i < n; i++){
        int A;
        cin >> A;
        g(A);
        base = merg(base, decart.size() - 1);
    }
    int ans = 0;
    while (base != -1){
        int ind = decart[base].ind;
        int cous = decart[base].C;
        pair<int, int> p = split(base, ind);
        pair<int, int> p1 = split(p.second, cous);
        base = merg(p.first, p1.second);
        ans++;
    }
    cout << ans << endl;
    return 0;
}