#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

string str;

int f[maxn];
int g[maxn];

int main(){
	int i, j;
	int x, y;
	int delta = 0;
	
	cin >> str;
	n = str.length();
	str = "2" + str;
	
	x = 0, y = 0;
	
	for(i=1;i<=n;i++){
		g[i] = g[i - 1];
		if(str[i] == '0'){
			x++;
			f[i] = x;
		}else{
			y = max(x + 1, y + 1);
			f[i] = y;
			g[i] = max(g[i], f[i]);
		}
	}
	
	deque <pair <int, int> > q;
	
	for(i=1;i<=n;i++){
		if(str[i] == '1')continue;
		if(q.empty()){
			q.push_back(make_pair(g[i] - f[i], i));
		}else{
			while(q.size() and q.back().first > g[i] - f[i])q.pop_back();
			q.push_back(make_pair(g[i] - f[i], i));
		}
	}
	
	for(i=1;i<=n;i++){
		if(str[i] == '0')continue;
		while(q.size() and q.front().second < i)q.pop_front();
		if(i < n and str[i + 1] == '0')continue;
		if(q.empty() or q.front().first - delta > 0){
			str[i] = '0';
			delta++;
		}
	}
	
	if(str[n - 1] == '0' and str[n] == '1')str[n] = '0';
	
	cout << str.substr(1, n) << endl;
	
	return 0;
}