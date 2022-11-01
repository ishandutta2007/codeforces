#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

string a, b;

int f[maxn];
int g[maxn];

int main(){
	int i, j;
	int x, y;
	int ans = 0;
	
	cin >> a >> b;
	
	for(i=0,j=0;i<a.length() and j<b.length();j++){
		while(a[i] != b[j])i++;
		f[j] = i;
		i++;
	}
	
	for(i=a.length()-1,j=b.length()-1;i>=0 and j>=0;j--){
		while(a[i] != b[j])i--;
		g[j] = i;
		i--;
	}
	
	ans = max(ans, max(f[0], (int)a.length() - g[b.length() - 1] - 1));
	ans = max(ans, max((int)a.length() - f[b.length() - 1] - 1, g[0]));
	for(i=0;i+1<b.length();i++){
		ans = max(ans, g[i + 1] - f[i] - 1);
	}
	
	cout << ans << endl;
	
	return 0;
}