#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int t, h, m;

string rev(string s){
	reverse(all(s));
	for(auto &c: s){
		if(c == '2')
			c = '5';
		else if(c == '5')
			c = '2';
	}
	return s;
}

bool ok(string s){
	for(auto c: s){
		c -= '0';
		if(c == 3 or c == 4 or c == 6 or c == 7 or c == 9)
			return 0;
	}
	s = rev(s);
	int a = stoi(s.substr(0, 2)), b = stoi(s.substr(2));
	return (a < h and b < m);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &h, &m);
		int a, b;
		scanf("%d:%d", &a, &b);
		pair<int, string> ans = {1e9, "wtf"};
		for(int i = 0; i < h; i++){
			for(int j = 0; j < m; j++){
				int dif = ((i*m+j)-(a*m+b) + h*m)%(h*m);
				string s = to_string(j);
				if(size(s) < 2)
					s = "0"+s;
				s = to_string(i)+s;
				if(size(s) < 4)
					s = "0"+s;

				if(ok(s))
					ans = min(ans, {dif, s});
			}
		}
		string s = ans.second;
		s = s.substr(0, 2)+":"+s.substr(2);
		cout<<s<<'\n';
	}
}