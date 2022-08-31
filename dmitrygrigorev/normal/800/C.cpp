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
#define int long long
using namespace std;
int n, m, ai;
set<int> data;
map<int, vector<int> > nod;
vector<vector<int> > mas;
vector<int> nums;
int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x % y);
}
int gcde(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcde(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.insert(ai);
    }
    for (int i=1;i<m;i++){
        if (data.count(i)) continue;
        int g = gcd(i, m);
        if (!nod.count(g)){
            vector<int> help;
            help.push_back(i);
            nod[g] = help;
        }
        else nod[g].push_back(i);
    }
    int nole = 0;
    if (!data.count(0)){
        nole = 1;
    }
    for (int i=1;i<m;i++){
        if (nod.count(i)){
            mas.push_back(nod[i]);
            nums.push_back(i);
        }
    }
    int sz = mas.size();
    if (sz == 0){
        if (nole == 1){
            cout << 1 << endl;
            cout << 0 << endl;
        }
        else cout << 0 << endl;
        return 0;
    }
    int dp[sz];
    for (int i=0;i<sz;i++){
        dp[i] = mas[i].size();
    }
    int maximum = 0;
    int ind = 0;
    for (int i=0;i<sz;i++){
        if (dp[i] > maximum){
            ind = i;
        }
        maximum = max(maximum, dp[i]);
        for (int j=0;j<i;j++){
            if (nums[i] % nums[j] == 0){
                int ssz = mas[i].size();
                dp[i] = max(dp[i], dp[j] + ssz);
                if (dp[i] > maximum){
                    ind = i;
                }
                maximum = max(maximum, dp[i]);
            }
        }
    }
    cout << maximum + nole << endl;
    int now = ind;
    vector<int> indexes;
    while (true){
        indexes.push_back(now);
        bool ch = true;
        for (int i=0;i<sz;i++){
            if (dp[now] - dp[i] == mas[now].size() && nums[now] % nums[i] == 0){
                now = i;
                ch = false;
                break;
            }
        }
        if (ch) break;
    }
    sort(indexes.begin(), indexes.end());
    vector<int> go;
    for (int i=0;i<indexes.size();i++){
        int ii = indexes[i];
        for (int j=0;j<mas[ii].size();j++){
            go.push_back(mas[ii][j]);
        }
    }
    now = 1;
    for (int i=0;i<go.size();i++){
        int new_el = go[i];
        int gg = gcd(now, m);
        new_el /= gg;
        now /= gg;
        int mm = m / gg;
        int xx, yy;
        gcde(now, mm, xx, yy);
        xx = (xx % mm + mm) % mm;
        cout << (xx * new_el) % m << " ";
        now = go[i];
    }
    if (nole == 1){
        cout << 0;
    }
    return 0;
}