#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[1024], b[1025];
bool used[1024];

int main()
{
	IO_OP;
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	
	vi v;
	for(int i=0;i<m;i++) {
		if(!used[b[i]]){
			v.PB(b[i]);
			used[b[i]] = 1;
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++) {
		for(int j=0;j<v.size();j++) {
			if(v[j] == b[i]){
				for (int k=j; k>0; k-- ) swap(v[k],v[k-1]);
				break;
			}
			ans += a[v[j]];
		}
	}
	cout << ans << endl;
}