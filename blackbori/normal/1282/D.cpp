#include <bits/stdc++.h>

using namespace std;

int n, k;

int ask(string s)
{
	cout << s << endl;
	cout.flush();
	int rt; cin >> rt;
	if(rt == 0) exit(0);
	return rt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, l, x, y;
	string s, t;
	
	x = ask("a") + 1;
	
	if(x > 300){
		s = "";
		for(i = 1; i < x; i ++){
			s += 'b';
		}
		ask(s);
	}
	
	s = "";
	for(i = 0; i < x; i ++){
		s += 'a';
	}
	
	y = ask(s);
	
	if(x == y){
		s = "";
		for(i = 1; i < x; i ++){
			s += 'b';
		}
		ask(s);
	}
	
	n = x;
	k = y; // number of b
	
	t = "";
	
	for(i = 0, j = 0; i < k; i ++){
		for(; ; ){
			s = t;
			s += 'b';
			for(l = j; l < n - k; l ++) s += 'a';
			x = ask(s);
			if(y > x) break;
			t += 'a'; j ++;
		}
		y = x; t += 'b';
	}
	
	return 0;
}