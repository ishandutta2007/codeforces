#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<functional>
#include<deque>

using namespace std;

#define ZZ pair<int, pair<int, int>>
#define XX second.first
#define YY second.second

const int MAX = 10000 + 10;
const int C = 5000;

int n, q;
set<ZZ, greater<ZZ>> st;
unsigned short mp[MAX][MAX];
deque<pair<int, int>>	saf;

int main(){
	scanf("%d%d", &n, &q);
	st.insert({n, {0 + C, 0 + C}});
	if (n >= 4)	saf.push_back({0 + C, 0 + C});
	mp[0 + C][0 + C] = n;
	int maxi = C;
	while (saf.size()){
		pair<int, int>	temp = saf.front();	saf.pop_front();
		int x = mp[temp.first][temp.second] / 4;
		mp[temp.first][temp.second] %= 4;
		mp[temp.first + 1][temp.second] += x;
		mp[temp.first - 1][temp.second] += x;
		mp[temp.first][temp.second + 1] += x;
		mp[temp.first][temp.second - 1] += x;

		if (mp[temp.first + 1][temp.second] >= 4 && mp[temp.first + 1][temp.second] - x < 4)	saf.push_back({temp.first + 1, temp.second});
		if (mp[temp.first - 1][temp.second] >= 4 && mp[temp.first - 1][temp.second] - x < 4)	saf.push_back({temp.first - 1, temp.second});
		if (mp[temp.first][temp.second + 1] >= 4 && mp[temp.first][temp.second + 1] - x < 4)	saf.push_back({temp.first, temp.second + 1});
		if (mp[temp.first][temp.second - 1] >= 4 && mp[temp.first][temp.second - 1] - x < 4)	saf.push_back({temp.first, temp.second - 1});
	}
	for (int i = 0; i < q; i++){
		int a, b;	scanf("%d%d", &a, &b);	a += C;	b += C;
		if (a >= C + 200 || a <= C - 200 || b >= C + 200 || b <= C - 200)	printf("0\n");
		else printf("%d\n", mp[a][b]);
	}
	return 0;
}