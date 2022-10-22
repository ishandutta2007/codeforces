#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

#define Seg pair<pair<int, int>, int>
#define left first.first
#define right first.second
#define down first.first
#define top first.second

const int INF = 1e9 + 5;

int n, m, k;
vector<Seg>	col, row;

bool cmp(Seg a, Seg b){
	if (a.second != b.second)
		return	a.second < b.second;
	return	a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--){
		int a, b, c, d;	cin >> a >> b >> c >> d;
		if (a > c || b > d)
			swap(a, c), swap(b, d);
		if (b == d)
			col.push_back({{a, c}, b});
		else
			row.push_back({{b, d}, a});
	}
	sort(col.begin(), col.end(), cmp);
	sort(row.begin(), row.end(), cmp);
	for (int i = 1; i < col.size(); i++)
		if (col[i].second == col[i - 1].second && col[i].down <= col[i - 1].top){
			col[i].down = min(col[i].down, col[i - 1].down);
			col[i].top = max(col[i].top, col[i - 1].top);
			col[i - 1].down = INF;
		}
	for (int i = 1; i < row.size(); i++)
		if (row[i].second == row[i - 1].second && row[i].left <= row[i - 1].right){
			row[i].left = min(row[i].left, row[i - 1].left);
			row[i].right = max(row[i].right, row[i - 1].right);
			row[i - 1].left = INF;
		}	

	int ans = 0;
	{
		set<int>	st;
		map<int, int>	mp;
		for (int i = 0; i < col.size(); i++)
			if (col[i].down != INF){
				if (st.count(col[i].second))
					ans ^= n - mp[col[i].second];
				st.insert(col[i].second);
				mp[col[i].second] += col[i].right - col[i].left;
				ans ^= n - mp[col[i].second];
			}
		if (st.size() % 2 != (m - 1) % 2)
			ans ^= n;

		st.clear();
		mp.clear();
		for (int i = 0; i < row.size(); i++)
			if (row[i].left != INF){
				if (st.count(row[i].second))
					ans ^= m - mp[row[i].second];
				st.insert(row[i].second);
				mp[row[i].second] += row[i].right - row[i].left;
				ans ^= m - mp[row[i].second];
			}
		if (st.size() % 2 != (n - 1) % 2)
			ans ^= m;
	}

	if (ans == 0)
		cout << "SECOND\n";
	else{
		cout << "FIRST\n";
		int l;
		for (l = 30; l >= 0; l--)
			if ((ans >> l) & 1)	break;
		{
			set<int>	st;
			map<int, int>	mp;
			for (int i = 0; i < col.size(); i++)
				if (col[i].down != INF){
					st.insert(col[i].second);
					mp[col[i].second] += col[i].right - col[i].left;
				}
			if (st.size() != m - 1)
				for (int i = 1; i < m; i++)
					if (mp.count(i) == 0){
						st.insert(i);
						break;
					}

			for (int c:st){
				int z = n - mp[c];
				if ((z >> l) & 1){
					z ^= 1 << l;
					ans ^= 1 << l;
					for (--l; l >= 0; l--){
						if ((ans >> l) & 1)
							z ^= (1<<l), ans ^= 1 << l;
					}
					vector<pair<int, int>>	gec;
					for (Seg ss:col)
						if (ss.down != INF)
							if (ss.second == c)
								gec.push_back(ss.first);

					gec.push_back({n, n});
					int cur = 0, last = 0;
					for (pair<int, int>	temp:gec){
						if (cur + temp.first - last < z){
							cur += temp.first - last;
							last = temp.second;
						}
						else{
							last = last + z - cur;
							cur = z;
							break;
						}
					}
					cout << last << " " << c << " " << n << " " << c << endl;
					return 0;
				}
			}

			st.clear();
			mp.clear();
			for (int i = 0; i < row.size(); i++)
				if (row[i].left != INF){
					st.insert(row[i].second);
					mp[row[i].second] += row[i].right - row[i].left;
				}
			if (st.size() != n - 1)
				for (int i = 1; i < n; i++)
					if (mp.count(i) == 0){
						st.insert(i);
						break;
					}

			for (int c:st){
				int z = m - mp[c];
				if ((z >> l) & 1){
					for (; l >= 0; l--){
						if ((ans >> l) & 1)
							z ^= (1<<l), ans ^= 1 << l;
					}
					vector<pair<int, int>>	gec;
					for (Seg ss:row)
						if (ss.left != INF)
							if (ss.second == c)
								gec.push_back(ss.first);

					gec.push_back({m, m});
					int cur = 0, last = 0;
					for (pair<int, int>	temp:gec){
						if (cur + temp.first - last < z){
							cur += temp.first - last;
							last = temp.second;
						}
						else{
							last = last + z - cur;
							cur = z;
							break;
						}
					}
					cout << c << " " << last << " " << c << " " << m << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}