#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		bool ok = false;
		for(int i=1;i<(int)s.size();i++){
			if(s[i] != s[0]) ok = true;
		}
		if(!ok) cout << -1 << endl;
		else{
		sort(s.begin(),s.end());
			cout << s << endl;
		}
	}
	return 0;
}