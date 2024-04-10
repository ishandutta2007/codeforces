#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << "> " << #x << " is " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200005], cnt[200005], p[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a+n);
	n = unique(a, a+n)-a;
	for(int i=0;i<n;i++)
		p[i] = cnt[a[i]] + (i ? p[i-1] : 0);
	int mx = 0, l, r;
	for(int i=0;i<n;i++) {
		if(cnt[a[i]] == 0) continue;
		int j = i+1;
		while(j < n && a[j] == a[j-1]+1 && cnt[a[j]]>1) j++;
		j--;
		if(j+1 < n && a[j+1] == a[j]+1 && cnt[a[j+1]]) j++;
		int len = p[j] - (i ? p[i-1] : 0);
		if(len > mx) {
			mx = len;
			l = a[i], r = a[j];
		}
		if(i!=j)
			i = j-1;
		else
			i = j;
	}
	cout << mx << endl;
	// debug(l);
	// debug(r);
	while(cnt[l]-- > 0)
		cout << l << " ";
	for(int i=l+1;i<r;i++)
		cout << i << " ";
	while(cnt[r]-- > 0)
		cout << r << " ";
	for(int i=r-1;i>l;i--) {
		for(int j=0;j<cnt[i]-1;j++)
			cout << i << " ";
	}
}