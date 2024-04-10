#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string s[101010],ans;
int n,sz;
vector <int> K[2020202];

int main()
{
	cin.sync_with_stdio(0);

	int i,j,a,b,rp=-1,rm,p = -1,m;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> s[i];
		cin >> a;
		for(;a--;){
			cin >> b; b--;
			K[b].push_back(i);
			sz = max(sz,(int)(b+s[i].size()));
		}
	}

	for(rm=i=0;i<sz;i++){
		if(p != -1 && i-m == s[p].size()) p = -1;

		for(j=0;j<K[i].size();j++){
			if(i+s[K[i][j]].size() > rm){
				rp = K[i][j];
				rm = i+s[K[i][j]].size();
			}
		}
		if(p == -1 && rp != -1){
			p = rp; m = rm - s[p].size();
			rp = -1;
		}

		if(p == -1) ans.push_back('a');
		else ans.push_back(s[p][i-m]);
	}

	cout << ans << endl;

	return 0;
}