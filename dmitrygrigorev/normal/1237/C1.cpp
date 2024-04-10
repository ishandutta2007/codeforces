#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Pt
{
	int x; int y; int index;
};

bool cmp(Pt &a, Pt &b){
	pair<int, int> A = {a.x, a.y}, B = {b.x, b.y};
	return (A<B);
}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Pt> v;

	map<pair<int, int>, vector<pair<int, int> > > ms;

	for (int i=0;i<n;++i){
		int x, y, z;
		cin >> x >> y >> z;
		ms[{x, y}].push_back({z, i});
	}

	for (auto it = ms.begin(); it != ms.end(); it++){
		vector<pair<int, int> > kek = (*it).second;
		sort(kek.begin(), kek.end());
		for (int i=0;i+1<kek.size(); i+=2){
			cout << kek[i].second+1 << " " << kek[i+1].second +1 << endl;
		}
		if (kek.size() % 2 != 0){
			int x = (*it).first.first, y = (*it).first.second;
			v.push_back({x, y, kek.back().second});
		}
	}

	n = v.size();

	sort(v.begin(), v.end(), cmp);

	Pt special;
	bool is_special = false;

	int start = 0;
	while (start < n){
		int finish = start;
		while (finish < n && v[finish].x == v[start].x) finish++;
		for (int i=start; i+1 < finish; i += 2){
			cout << v[i].index+1 << " " << v[i+1].index+1 << endl;
		}
		if ((finish-start)%2!=0){
			if (is_special){
				is_special = false;
				cout << special.index+1 << " " << v[finish-1].index+1 << endl;
			}
			else{
				is_special = true;
				special = v[finish-1];
			}
		}
		start=finish;
	}
}