#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

int n, m, s;
int a[MAXN], b[MAXN], c[MAXN], vec[MAXN], sec[MAXN];
set<pair<int, int>>	st;
int mat[MAXN];

bool cmp(int x, int y){
	if (b[x] != b[y])
		return	b[x] > b[y];
	return	c[x] < c[y];
}

bool cmp2(int x, int y){return	a[x] > a[y];}

bool ok(int x){
	st.clear();
	int beg = 0, sum = 0;
	for (int i = 0; i < m; i += x){
		while (beg < n && b[vec[beg]] >= a[sec[i]]){
			st.insert({c[vec[beg]], vec[beg]});
			beg++;
		}
	
		if (st.empty())
			return	false;
		pair<int, int>	v = *st.begin();
		st.erase(st.begin());
		sum += v.first;
		if (sum > s)	return	false;
		for (int j = i; j < m && j < i + x; j++)
			mat[sec[j]] = v.second;
	}	
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	iota(vec, vec + n, 0);
	sort(vec, vec + n, cmp);
	iota(sec, sec + m, 0);
	sort(sec, sec + m, cmp2);

	int beg = 1, end = 1e5, ret = -1;
	while (beg <= end){
		int mid = (beg + end)/ 2;
		if (ok(mid)){
			ret = mid;
			end = mid - 1;
		}
		else	beg = mid + 1;
	}

	if (ret == -1)
		cout << "NO\n";
	else{
		ok(ret);
		cout << "YES\n";
		for (int i = 0; i < m; i++)
			cout << mat[i] + 1 << " ";
		cout << "\n";
	}
	return 0;
}