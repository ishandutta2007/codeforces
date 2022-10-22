#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXVAL = 2e6 + 10;

int n;
vector<int>	vec, sec;
bool pr[2 * MAXVAL];
int cnt[2 * MAXVAL];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXVAL; i++)
		if (!pr[i])
			for (int j = i + i; j < MAXVAL; j += i)	pr[j] = 1;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		if (x&1)
			vec.push_back(x);
		else
			sec.push_back(x);
		cnt[x]++;
		if (n == 1){
			cout << 1 << "\n";
			cout << x << "\n";
			return 0;
		}
	}
	sort(vec.begin(), vec.end());
	sort(sec.begin(), sec.end());
	if (sec.empty()){
		if (cnt[1]){
			cout << cnt[1] << "\n";
			for (int i = 0; i < cnt[1]; i++)
				cout << 1 << " ";
			cout << "\n";
		}
		else{
			cout << 1 << "\n";
			cout << vec[0] << "\n";
		}
	}
	else if (vec.empty()){
		cout << 1 << "\n";
		cout << sec[0] << "\n";
		return 0;
	}
	else{
		if (cnt[1]){
			for (int i = 0; i < sec.size(); i++)
				if (!pr[sec[i] + 1]){
					cout << cnt[1] + 1 << "\n";
					for (int j = 0; j < cnt[1]; j++)
						cout << 1 << " ";
					cout << sec[i] << "\n";
					return 0;
				}
			if (cnt[1] > 1){
				cout << cnt[1] << "\n";
				for (int w = 0; w < cnt[1]; w++)
					cout << 1 << " ";
				cout << "\n";
				return 0;
			}
		}
		for (int u:vec)
			for (int v:sec)
				if (!pr[u + v]){
					cout << 2 << "\n";
					cout << u << " " << v << "\n";
					return 0;
				}
		cout << 1 << "\n";
		cout << vec[0] << "\n";
	}
	return 0;
}