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
int K = 1000000007;
using namespace std;
struct Three{int red; int black; int kl;};
vector<int> starts;
vector<vector<int> > data, klay, colour;
vector<bool> used;
vector<pair<int, int> > e1, e2;
int n, ui, vi, xi, ci, ans1, ans2, wh, maximum, middle, asz1, asz2;
vector<int> rmq1, rmq2, where1, where2, sz1, sz2;
vector<vector<Three> > ways;
int gcd(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
bool get_worst(int vertex, int last, int dist){
    bool ret = false;
    if (dist > maximum){
        wh = vertex;
        maximum = dist;
        ret = true;
    }
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (last == to || used[to]) continue;
        bool res = get_worst(to, vertex, dist + 1);
        if (res) ret = true;
        if (res && maximum / 2 == dist) middle = vertex;
    }
    return ret;
}
void dfs(int vertex, int last, int rd, int bl, int kk, int length, int &ml){
    Three th = {rd, bl, kk};
    if (min(rd, bl) * 2 >= max(rd, bl)){
        ans1 *= kk;
        ans1 %= K;
    }
    ways.back().push_back(th);
    ml = max(ml, length);
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last || used[to]) continue;
        int new_red = rd + (colour[vertex][i] == 0);
        int new_black = bl + (colour[vertex][i] == 1);
        int new_kl = (kk * klay[vertex][i]) % K;
        dfs(to, vertex, new_red, new_black, new_kl, length+1, ml);
    }
}
int ex(int a, int b){
    int res = 1;
    int st = a;
    for (int i=0; i < 40; i++){
        int b_and = (1LL << i) & b;
        if (b_and != 0){
            res *= st;
            res %= K;
        }
        st *= st;
        st %= K;
    }
    return res;
}
int get_prefix(int i, int l, int r, int value){
    if (r - l == 1){
        if (e1[l].first <= value){
            asz1 += sz1[i];
            return rmq1[i];
        }
        return 1;
    }
    int mid = (l + r) / 2;
    if (e1[mid-1].first <= value){
        asz1 += sz1[2*i+1];
        return (rmq1[2*i+1] * get_prefix(2*i+2, mid, r, value)) % K;
    }
    return get_prefix(2*i+1, l, mid, value);
}
int get_suffix(int i, int l, int r, int value){
    if (r - l == 1){
        if (e2[l].first > value){
            asz2 += sz2[i];
            return rmq2[i];
        }
        return 1;
    }
    int mid = (l + r) / 2;
    if (e2[mid-1].first <= value) return get_suffix(2*i+2, mid, r, value) % K;
    asz2 += sz2[2*i+2];
    return (get_suffix(2*i+1, l, mid, value) * rmq2[2*i+2]) % K;
}
int add_prefix(int i, int l, int r, int ind, int vv){
    if (r - l == 1){
        rmq1[i] = vv;
        sz1[i] = 1;
    }
    else{
        int mid = (l + r) / 2;
        if (ind < mid) add_prefix(2*i+1, l, mid, ind, vv);
        else add_prefix(2*i+2, mid, r, ind, vv);
        rmq1[i] = (rmq1[2*i+1] * rmq1[2*i+2]) % K;
        sz1[i] = sz1[2*i+1] + sz1[2*i+2];
    }
}
int add_suffix(int i, int l, int r, int ind, int vv){
    if (r - l == 1){
        rmq2[i] = vv;
        sz2[i] = 1;
    }
    else{
        int mid = (l + r) / 2;
        if (ind < mid) add_suffix(2*i+1, l, mid, ind, vv);
        else add_suffix(2*i+2, mid, r, ind, vv);
        rmq2[i] = (rmq2[2*i+1] * rmq2[2*i+2]) % K;
        sz2[i] = sz2[2*i+1] + sz2[2*i+2];
    }
}
void get_centroid(int vertex){
    middle = vertex;
    maximum = -1;
    get_worst(vertex, -1, 0);
    maximum = -1;
    get_worst(wh, -1, 0);
    int worst = middle;
    int max_length = 0;
    rmq1.clear();
    rmq2.clear();
    where1.clear();
    where2.clear();
    ways.clear();
    e1.clear();
    e2.clear();
    sz1.clear();
    sz2.clear();
    for (int i=0; i < data[worst].size(); i++){
        int to = data[worst][i];
        if (used[to]) continue;
        vector<Three> help;
        ways.push_back(help);
        dfs(to, worst, (colour[worst][i] == 0), (colour[worst][i] == 1), klay[worst][i], 1, max_length);
    }
    int counter = 0;
    for (int i=0; i < ways.size(); i++){
        for (int j=0; j < ways[i].size(); j++){
            Three th = ways[i][j];
            e1.push_back(make_pair(th.black - 2*th.red, counter));
            e2.push_back(make_pair(th.red - 2*th.black, counter));
            where1.push_back(0);
            where2.push_back(0);
            counter++;
        }
    }
    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());
    for (int i = 0; i < counter; i++){
        where1[e1[i].second] = i;
        where2[e2[i].second] = i;
    }
    int SZ = counter;
    for (int i=0; i < 4*SZ; i++){
        rmq1.push_back(1);
        rmq2.push_back(1);
        sz1.push_back(0);
        sz2.push_back(0);
    }
    counter = 0;
    for (int i=0; i < ways.size(); i++){
        for (int j=0; j < ways[i].size(); j++){
            asz1 = 0;
            asz2 = 0;
            Three th = ways[i][j];
            ans1 *= get_prefix(0, 0, SZ, 2 * th.red - th.black) % K;
            ans1 %= K;
            ans2 *= get_suffix(0, 0, SZ, 2 * th.black - th.red) % K;
            ans2 %= K;
            ans1 *= ex(th.kl, asz1 - asz2);
            ans1 %= K;
        }
        for (int j=0; j < ways[i].size(); j++){
            Three th = ways[i][j];
            add_prefix(0, 0, SZ, where1[counter], th.kl);
            add_suffix(0, 0, SZ, where2[counter], th.kl);
            counter ++;
        }
    }
    used[worst] = true;
    for (int i=0; i < data[worst].size(); i++){
        int to = data[worst][i];
        if (used[to]) continue;
        get_centroid(to);
    }
}
int32_t main(){
    //freopen("2.txt", "w", stdout);
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> h1, h2, h3;
        data.push_back(h1);
        klay.push_back(h2);
        colour.push_back(h3);
        used.push_back(false);
    }
    for (int i=0; i < n - 1; i++){
        cin >> ui >> vi >> xi >> ci;
        data[ui-1].push_back(vi - 1);
        data[vi-1].push_back(ui - 1);
        klay[ui-1].push_back(xi);
        klay[vi-1].push_back(xi);
        colour[ui - 1].push_back(ci);
        colour[vi - 1].push_back(ci);
    }
    ans1 = 1, ans2 = 1;
    get_centroid(0);
    int x, y;
    gcd(ans2, K, x, y);
    x %= K;
    x *= ans1;
    x %= K;
    x += K;
    x %= K;
    cout << x << endl;
    return 0;
}