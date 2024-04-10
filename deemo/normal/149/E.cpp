#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int max_n = 1e5 + 20;

string s, p;
int m, cnt, k;
int first[max_n], last[max_n], f[max_n], g[max_n], ans[max_n], rev_ans[max_n];

bool ok(){
	fill(first, first+p.size() + 2, -2);
	fill(last, last+p.size() + 2, -2);
	f[1] = k = 0;
	for (int i = 1 ; i < p.size() ; i++){
		while (k && p[i] != p[k])	k = f[k];
		if (p[k] == p[i])	k++;
		f[i + 1] = k;
	}
	k = 0;	
	first[0] = -1;
	for (int i = 0; i < s.size(); i++){
		while (k && p[k] != s[i])	k = f[k];
		if (s[i] == p[k])	k++;
		ans[i] = k;
		if (first[k] == -2)	first[k] = i;
		if (k == p.size())	k = f[k];
	} 
	reverse(p.begin(), p.end());
	reverse(s.begin(), s.end());
	g[1] = k = 0;
	for (int i = 1; i < p.size(); i++){
		while (k && p[i] != p[k])	k = g[k];
		if (p[k] == p[i])	k++;
		g[i + 1] = k;
	}	
	k = 0;
	last[0] = s.size();
	for (int i = 0 ; i < s.size() ; i++){
		while (k && s[i] != p[k])	k = g[k];
		if (p[k] == s[i])	k++;
		rev_ans[i] = k;
		if (last[k] == -2)	last[k] = s.size() - i - 1;
		if (k == p.size())	k = g[k];
	}

	for (int i = 1 ; i < p.size() ; i++){
		if (first[i] == -2)	continue;
		if (last[p.size() - i] == -2)	continue;
		if (first[i] < last[p.size() - i])	return	true;
	}
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> m;
	while (m--){
		cin >> p;
		if (ok())	cnt++;
		reverse(s.begin(), s.end());
	}
	cout << cnt << endl;
	return	0;
}