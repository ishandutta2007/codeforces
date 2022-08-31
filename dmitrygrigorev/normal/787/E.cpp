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
#include <unordered_set>
#include <bitset>
using namespace std;
struct Vertex{int l;int r;int v;};
int n, ai, counter;
map<int, int> used;
vector<int> data;
vector<Vertex> rmq;
int result(int old, int l, int r, int d){
    if (r - l == 1){
        if (rmq[old].v > d) return l-1;
        return l;
    }
    int m = (l + r) / 2;
    int vv = rmq[rmq[old].l].v;
    if (vv > d) return result(rmq[old].l, l, m, d);
    return result(rmq[old].r, m, r, d-vv);
}
int change(int old, int ind, int l, int r, int d){
    if (r - l == 1){
        Vertex vert;
        vert.l = -1;
        vert.r = -1;
        vert.v = d;
        rmq.push_back(vert);
        counter ++;
        return counter - 1;
    }
    else{
        int m = (l + r) / 2;
        if (ind < m){
            int c = change(rmq[old].l, ind, l, m, d);
            Vertex vert;
            vert.l = c;
            vert.r = rmq[old].r;
            vert.v = rmq[vert.l].v + rmq[vert.r].v;
            rmq.push_back(vert);
            counter ++;
            return counter - 1;
        }
        else{
            int c = change(rmq[old].r, ind, m, r, d);
            Vertex vert;
            vert.r = c;
            vert.l = rmq[old].l;
            vert.v = rmq[vert.l].v + rmq[vert.r].v;
            rmq.push_back(vert);
            counter ++;
            return counter - 1;
        }
    }
}
int create(int l, int r){
    if (r - l == 1){
        Vertex vert;
        vert.l = -1;
        vert.r = -1;
        vert.v = 0;
        rmq.push_back(vert);
        counter ++;
        return counter - 1;
    }
    else{
        int m = (l + r) / 2;
        int c1 = create(l, m);
        int c2 = create(m, r);
        Vertex vert;
        vert.l = c1;
        vert.r = c2;
        vert.v = rmq[c1].v + rmq[c2].v;
        rmq.push_back(vert);
        counter ++;
        return counter - 1;
    }
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    counter = 0;
    create(0, n);
    vector<int> base;
    for (int i=0;i<n;i++){
        base.push_back(0);
    }
    for (int i=n-1;i>=0;i--){
        int el = data[i];
        if (used.count(el)){
            change(counter-1, used[el], 0, n, 0);
        }
        change(counter-1, i, 0, n, 1);
        used[el] = i;
        base[i] = counter - 1;
    }
    for (int k=1;k<=n;k++){
        int start = 0;
        int ans = 0;
        while (start < n){
            start = result(base[start], 0, n, k) + 1;
            ans ++;
        }
        cout << ans << " ";
    }
    return 0;
}