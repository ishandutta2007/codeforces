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

int a[200005], pos[200005];

int DC(int l, int r) {
	if(l == r - 1) return 0;
	int m = (l + r) / 2;
	int ans = DC(l, m) + DC(m, r), pre = 0, post = 0;
	for(int i=m-1,j=m;i>=l&&j<r;) {
		pre = max(pre, a[j]);
		post = max(post, a[i]);
		if(pre < post) {
			while(j+1<r&&a[j+1]<post)
				pre=max(pre,a[++j]);
			while(i>=l) {
				if(m <= pos[post-a[i]] && pos[post-a[i]] <= j) {
					ans++;
//					cout << i << ", " << pos[post-a[i]] << " " << post << endl;
				}
				if (i-1>=l&&a[i-1]<=post)
					--i;
				else
					break;
			}
		} else {
			while(i-1>=l&&a[i-1]<pre)
				post=max(post,a[--i]);
			while(j<r) {
				if(i <= pos[pre-a[j]] && pos[pre-a[j]] < m){
					ans++;
//					cout << pos[pre-a[j]] << ", " << j << " " << pre << endl;
				}
				if (j+1<r&&a[j+1]<=pre)
					++j;
				else
					break;
			}
		}
		if (i-1<l)
			j++;
		else if(j+1==r)
			i--;
		else if (a[i-1]<a[j+1])
			i--;
		else
			j++;
	}
	return ans;
}

int main()
{
	IO_OP;
	int n;
	cin >> n;
	memset(pos, 0xff, sizeof pos);
	for(int i=0;i<n;i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	cout << DC(0, n) << endl;
}