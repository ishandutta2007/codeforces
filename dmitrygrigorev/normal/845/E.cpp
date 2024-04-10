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
vector<pair<int, int> > p;
int n, m, k, xi, yi;
int INF = 1e18;
bool checker(int number){
	vector<int> ye, xe;
	vector<pair<int, int> > px, py;
	for (int i=0; i < k; i++){
		px.push_back(make_pair(p[i].first, p[i].second));
		py.push_back(make_pair(p[i].second, p[i].first));
	}
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	for (int i=0; i < p.size(); i++){
		ye.push_back(max((long long)1, p[i].second - number));
		ye.push_back(min(m, ye.back() + 1));
		ye.push_back(max((int) 1, ye.back() - 2));
		ye.push_back(min(m, p[i].second + number));
		ye.push_back(min(m, ye.back() + 1));
		ye.push_back(max((int) 1, ye.back() - 2));
	}
	sort(ye.begin(), ye.end());
	int l = INF;
	int r = -INF;
	if (ye[0] != 1) l = 1;
	else{
        for (int j=0; j < ye.size(); j++){
			int mp = 0;
			for (int i=0; i < px.size(); i++){
				int f = max((int)1, px[i].second - number);
				int s = min(m, px[i].second + number);
				if (ye[j] < f || ye[j] > s) continue;
				if (px[i].first-number > mp + 1) break;
				else{
					mp = max(mp, px[i].first+number);
				}
			}
			if (mp >= n) continue;
			l = ye[j];
			break;
        }
	}
	if (ye.back() != m) r = m;
	else{
        for (int j=ye.size() - 1; j >= 0; j--){
			int mp = n+1;
			for (int i=px.size()-1; i >= 0; i--){
				int f = max((long long)1, px[i].second - number);
				int s = min(m, px[i].second + number);
				if (ye[j] < f || ye[j] > s) continue;
				if (px[i].first+number < mp-1) break;
				else{
					mp = min(mp, px[i].first-number);
				}
			}
			if (mp <= 1) continue;
			r = ye[j];
			break;
        }
	}
	if (l == INF) return true;
	if (r - l > 2 * number) return false;
	for (int i=0; i < p.size(); i++){
		xe.push_back(max((int)1, p[i].first - number));
		xe.push_back(min(n, xe.back() + 1));
		xe.push_back(max((int) 1, xe.back() - 2));
		xe.push_back(min(n, p[i].first + number));
		xe.push_back(min(n, xe.back() + 1));
		xe.push_back(max((int) 1, xe.back() - 2));
	}
	sort(xe.begin(), xe.end());
	l = INF;
	r = -INF;
	if (xe[0] != 1) l = 1;
	else{
        for (int j=0; j < xe.size(); j++){
			int mp = 0;
			for (int i=0; i < py.size(); i++){
				int f = max((int)1, py[i].second - number);
				int s = min(n, py[i].second + number);
				if (xe[j] < f || xe[j] > s) continue;
				if (py[i].first-number > mp + 1) break;
				else{
					mp = max(mp, py[i].first+number);
				}
			}
			if (mp >= m) continue;
			l = xe[j];
			break;
        }
	}
	if (xe.back() != n) r = n;
	else{
        for (int j=xe.size() - 1; j >= 0; j--){
			int mp = m+1;
			for (int i=py.size()-1; i >= 0; i--){
				int f = max((int)1, py[i].second - number);
				int s = min(n, py[i].second + number);
				if (xe[j] < f || xe[j] > s) continue;
				if (py[i].first+number < mp-1) break;
				else{
					mp = min(mp, py[i].first-number);
				}
			}
			if (mp <= 1) continue;
			r = xe[j];
			break;
        }
	}
	if (r - l > 2 * number) return false;
	return true;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i=0; i < k; i++){
        cin >> xi >> yi;
        p.push_back(make_pair(xi, yi));
	}
	sort(p.begin(), p.end());
	int left = -1;
	int right = 1e10;
	while (right - left > 1){
		int mid = (left + right) / 2;
		bool res = checker(mid);
		if (res) right = mid;
		else left = mid;
	}
	cout << right << endl;
	return 0;
}