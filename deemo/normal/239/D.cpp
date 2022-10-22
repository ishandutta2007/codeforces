#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n, h, vec[MAXN], sec[MAXN], p[MAXN], tn;
map<int, vector<int>>	pos;
map<int, int>	mp;
vector<int>	f, g;

int get(int ms){
	f.clear();	g.clear();
	for (int i = 0; i < n; i++)
		if ((ms >> i) & 1)	
			f.push_back(sec[i]);
		else
			g.push_back(sec[i]);
	
	int maxi = 0, mini = 1e9;
	if ((int)f.size() > 1){	
		maxi = max(maxi, f.back() + f[(int)f.size() - 2]);
		mini = min(mini, f[0] + f[1]);
	}
	if ((int)g.size() > 1){	
		maxi = max(maxi, g.back() + g[(int)g.size() - 2]);
		mini = min(mini, g[0] + g[1]);
	}
	if ((int)g.size() && (int)f.size()){
		maxi = max(maxi, g.back() + f.back() + h);
		mini = min(mini, g[0] + f[0] + h);
	}
	return	maxi - mini;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		cin >> n >> h;
		tn = n;
		for (int i = 0; i < n; i++){
			cin >> vec[i];
			pos[vec[i]].push_back(i);
		}
		copy(vec, vec + n, sec);
		sort(vec, vec + n);
		sort(sec, sec + n);
		int m = unique(sec, sec + n) - sec;

		int cnt = 1, last = vec[0];
		for (int i = 1; i < n; i++){
			if (vec[i] == last){
				if (cnt == 3)
					vec[i] = -1;
				else
					cnt++;
			}
			else{
				if (vec[i] == sec[0] || vec[i] == sec[1] || vec[i] == sec[2] || vec[i] == sec[m - 1] || vec[i] == sec[m - 2] || vec[i] == sec[m - 3]){
					last = vec[i];
					cnt = 1;
				}
				else	vec[i] = -1;
			}
		}
		m = 0;
		for (int i = 0; i < n; i++)
			if (vec[i] != -1)	
				sec[m++] = vec[i];
		n = m;
	}
	int z = 1 << n;
	int ans = INF, mask = 0;
	for (int i = 0; i < z; i++){
		int temp = get(i);
		if (temp < ans){
			ans = temp;
			mask = i;
		}
	}

	cout << ans << endl;
	for (int i = 0; i < n; i++)
		p[pos[sec[i]][mp[sec[i]]++]] = ((mask >> i) & 1) + 1;
	for (int i = 0; i < tn; i++){
		if (p[i] == 0)	p[i] = 1;
		cout << p[i] << " ";
	}
	cout << "\n";
	return 0;
}