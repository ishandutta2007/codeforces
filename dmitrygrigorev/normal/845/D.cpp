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
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, type, ai;
	cin >> n;
	int speed = 0;
	int now = 1000;
	int cant = 0;
	int ans = 0;
	int u = -1;
	vector<pair<int, int> > sp;
	set<int> tr;
	tr.insert(-1);
	for (int i=0; i < n; i++){
		cin >> type;
		if (type == 1 || type == 3){
			cin >> ai;
		}
		else ai = -1;
		if (type == 3 || type == 5) tr.insert(i);
        sp.push_back(make_pair(type, ai));
	}
	for (int i=0; i < n; i++){
		if (sp[i].first == 1){
			speed = sp[i].second;
			while (true){
				if (speed <= now) break;
				set<int>::iterator it = tr.upper_bound(u - 1);
                set<int>::iterator it1 = it;
                it1--;
                tr.erase(it);
                ans++;
                int num = *it1;
				u = num;
				if (u == -1){
					now = 1000;
					break;
				}
				if (sp[u].first == 5){
					now = 1000;
					break;
				}
				now = sp[u].second;
			}
		}
		if (sp[i].first == 2){
			ans += cant;
			cant = 0;
		}
		if (sp[i].first == 3){
			if (sp[i].second < speed){
				set<int>::iterator it = tr.upper_bound(i-1);
				tr.erase(it);
				ans++;
			}
			else{
				u = i;
				now = sp[i].second;
			}
		}
		if (sp[i].first == 4){
			cant=0;
		}
		if (sp[i].first == 5){
			u = i;
			now = 1000;
		}
		if (sp[i].first == 6) cant++;
	}
	cout << ans << endl;
	return 0;
}