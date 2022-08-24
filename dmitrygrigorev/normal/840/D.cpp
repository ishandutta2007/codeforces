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
using namespace std;
struct Vertex{int l; int r; int summ;};
vector<Vertex> rmq;
vector<int> place, data, go, when;
int counter;
bool cmp(int f, int s){
	if (data[f] < data[s]) return true;
	return false;
}
int create(int l, int r){
	Vertex v;
	if (r - l == 1){
		v = {-1, -1, 0};
	}
	else{
		int mid = (l + r) / 2;
		int ls = create(l, mid);
		int rs = create(mid, r);
		v = {ls, rs, 0};
	}
	rmq.push_back(v);
	counter++;
	return counter-1;
}
int open(int i, int l, int r, int ind){
	Vertex v;
	if (r - l == 1){
		v = {-1, -1, 1};
	}
	else{
		int mid = (l + r) / 2;
		if (ind < mid){
			int ls = open(rmq[i].l, l, mid, ind);
			v = {ls, rmq[i].r, rmq[ls].summ + rmq[rmq[i].r].summ};
		}
		else{
			int rs = open(rmq[i].r, mid, r, ind);
			v = {rmq[i].l, rs, rmq[rs].summ + rmq[rmq[i].l].summ};
		}
	}
	rmq.push_back(v);
	counter++;
	return counter-1;
}
int get(int f, int s, int l, int r, int p){
	if (r - l == 1){
		return data[go[l]];
	}
	int mid = (l + r) / 2;
    int lf = rmq[f].l;
    int rf = rmq[s].l;
    int diff = rmq[rf].summ - rmq[lf].summ;
    if (diff < p){
		return get(rmq[f].r, rmq[s].r, mid, r, p-diff);
	}
	return get(lf, rf, l, mid, p);
}
int lb(vector<int> &v, int num){
	int left = -1;
	int right = v.size();
	while (right - left > 1){
		int mid = (left + right) / 2;
		if (v[mid] < num) left = mid;
		else right = mid;
	}
	return left+1;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, ai;
	cin >> n >> q;
	vector<vector<int> > v;
	for (int i=0; i < n; i++){
		vector<int> help;
		v.push_back(help);
	}
	for (int i=0; i < n; i++){
		go.push_back(i);
		when.push_back(i);
		cin >> ai;
		data.push_back(ai);
		v[ai-1].push_back(i);
	}
	sort(go.begin(), go.end(), cmp);
	for (int i=0; i < n; i++){
        when[go[i]] = i;
	}
	counter = 0;
	create(0, n);
	place.push_back(counter-1);
	for (int i=0; i < n; i++){
		open(counter-1, 0, n, when[i]);
		place.push_back(counter-1);
	}
	for (int i=0; i < q; i++){
		vector<int> cands;
		int li, ri, k;
		cin >> li >> ri >> k;
		int minimum = (ri - li + 1) / k + 1;
		for (int j=0; j <= ri-li; j+=minimum){
            int num = li + j;
            int st = get(place[li-1], place[ri], 0, n, j+1);
            cands.push_back(st);
		}
		sort(cands.begin(), cands.end());
		bool otv = false;
		for (int j=0; j < cands.size(); j++){
			int ll = lb(v[cands[j]-1], li-1);
			int rr = lb(v[cands[j] - 1], ri);
			int good = rr - ll;
			if (good >= minimum){
				cout << cands[j] << "\n";
				otv = true;
				break;
			}
		}
		if (!otv) cout << -1 << "\n";
	}
    return 0;
}