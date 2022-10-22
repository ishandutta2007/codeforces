#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 6 + 1;

int n, k, cnt;
string s, tt;
char t[200][200];

void gen(int cur = 0){
	if (cur == n){
		tt = s;
		for (int i = 0; i < n - 1; i++){
			char a = tt[0], b = tt[1];
			if (t[a][b] == 0)	return;
			tt.erase(tt.begin());
			tt.erase(tt.begin());
			tt = t[a][b] + tt;
		}	
		if (tt == "a")	cnt++;
		return;
	}

	for (char i = 'a'; i <= 'f'; i++)
		s[cur] = i, gen(cur + 1);
}

int main(){
	cin >> n >> k;
	s.resize(n);
	for (int i = 0; i < k; i++){
		char a, b, c;	cin >> a >> b >> c;
		t[a][b] = c;
	}
	gen();
	cout << cnt << "\n";
	return	0;
}