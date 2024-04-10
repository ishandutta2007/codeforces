#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

#define pb(x) push_back(x)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, cnt = 0;	cin >> n;
	vector<string>	vec;
	map<string, string>	mp, smp;

	while (n--){
		string a, b;	cin >> a >> b;
		if (smp.find(a) == smp.end()){
			cnt++;
			mp[a] = b;
			smp[b] = a;
			vec.pb(a);
			continue;
		}
		string p = smp[a];
		mp[p] = b;
		smp[b] = p;
	}	

	cout << cnt << "\n";
	for (auto s:vec)
		cout << s << " " << mp[s] << "\n";
	return 0;
}