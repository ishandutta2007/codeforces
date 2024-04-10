#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 3e3 + 20;

int a, b, l, r;
pair<int, int>	vec[MAXN], sec[MAXN];
bool ss[MAXN];

bool check(int x){
	for (int i = 0; i < b; i++)
		for (int j = sec[i].first; j <= sec[i].second; j++)
			if (ss[j + x])
				return	true;
	return	false;
}

int main(){
	cin >> a >> b >> l >> r;
	for (int i = 0; i < a; i++){
		cin >> vec[i].first >> vec[i].second;
		for (int j = vec[i].first; j <= vec[i].second; j++)
			ss[j] = 1;
	}
	for (int i = 0; i < b; i++)
		cin >> sec[i].first >> sec[i].second;
	
	int cnt = 0;
	for (; l <= r; l++)
		cnt += check(l);
	cout << cnt << "\n";
	return	0;
}