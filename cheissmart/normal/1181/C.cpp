#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

struct S{
	char a, b, c;
	int h;
	bool operator==(const S t) const {
		return a == t.a && b == t.b && c == t.c && h == t.h; 
	}
} b[1003][1003];
int c[1003][1003];
char a[1003][1003];

int main()
{
	IO_OP;
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=1;i<n-1;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j] == a[i-1][j]) continue;
			int h = 0, k, kk;
			for(k=i;k<n && a[k][j] == a[i][j];k++,h++);
			if(k >= n) continue;
			for(;k<n && a[k][j] == a[i+h][j];k++);
			k--;
			int l;
			for(l=i-1;l>=0 && a[l][j] == a[i-1][j];l--);
			l++;
			if(i-l < h ||k-(i+h-1) < h) continue;
			c[i][j] = 1;
			b[i][j] = {a[l][j], a[i][j], a[k][j], h};
		}
	} 
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(c[i][j]) {
				for(int k=j;j<m && c[i][k] && b[i][j] == b[i][k];k++)
					ans++;
			}
		}
	}
	cout << ans << endl;
}