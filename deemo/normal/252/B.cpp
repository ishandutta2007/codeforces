#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdlib>

using namespace std;

const int MAXN = 1e5 + 20;

int n;
int vec[MAXN], sec[MAXN], gec[MAXN], dek[MAXN];
map<int, vector<int>>	mp;
int cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		mp[vec[i]].push_back(i);
		if (mp[vec[i]].size() == 1)	cnt++;
	}
	if (cnt == 1 || n < 3){
		cout << -1 << endl;
		return 0;
	}

	copy(vec, vec + n, sec);
	copy(vec, vec + n, gec);
	copy(vec, vec + n, dek);
	sort(dek, dek + n);
	int z = unique(dek, dek + n) - dek;
	sort(sec, sec + n);
	sort(gec, gec + n);
	reverse(gec, gec + n);

	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++){
		if (vec[i] != sec[i])	c1++;
		if (vec[i] != gec[i])	c2++;
	}
	c1 = n - c1;
	c2 = n - c2;

	for (int i = 0; i < z; i++)
		for (int j = i + 1; j < z; j++){
			for (int u:mp[dek[i]])
				for (int v:mp[dek[j]]){
					int g1 = c1, g2 = c2;
					if (dek[i] == sec[u])	g1--;
					if (dek[i] == sec[v])	g1++;
					if (dek[j] == sec[u])	g1++;
					if (dek[j] == sec[v])	g1--;
					
					if (dek[i] == gec[u])	g2--;
					if (dek[i] == gec[v])	g2++;
					if (dek[j] == gec[u])	g2++;
					if (dek[j] == gec[v])	g2--;

					if (g1 != n && g2 != n){
						cout << u + 1 << " " << v + 1<< endl;
						return 0;
					}	
				}
		}

	cout << -1 << endl;

	return 0;
}