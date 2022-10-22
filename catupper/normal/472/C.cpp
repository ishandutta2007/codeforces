#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
typedef pair<bool, bool> P;

P able[108000];
string fs[108000];
string ss[108000];
vector<string> names;
int f[108000];
int s[108000];

int main(){  
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> fs[i] >> ss[i];
		names.push_back(fs[i]);
		names.push_back(ss[i]);
	}
	sort(names.begin(), names.end());
	for(int i = 0;i < n;i++){
		f[i] = lower_bound(names.begin(), names.end(), fs[i]) - names.begin();
		s[i] = lower_bound(names.begin(), names.end(), ss[i]) - names.begin();
	}
	int x, last;
	for(int i = 0;i < n;i++){
		cin >> x;x--;
		able[x] = P(true, true);
		if(i){                                     
			able[x] = P(false, false);
			if(able[last].first && f[last] < f[x]){
				able[x].first = true;
			}
			if(able[last].first && f[last] < s[x]){
				able[x].second = true;
			}
			if(able[last].second && s[last] < f[x]){
				able[x].first = true;
			}
			if(able[last].second && s[last] < s[x]){
				able[x].second = true;
			}
		}
		last = x;
	}
	if(able[last].first || able[last].second){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}