#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, q, a[MAXN], fen[MAXN];

void add(int v, int val){for (; v < MAXN; v+=v&-v) fen[v]+=val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

int fs[MAXN], ls[MAXN];
vector<int> vec[MAXN];
bool ok(){
	memset(ls, -1, sizeof(ls));
	memset(fs, 63, sizeof(fs));
	for (int i = 0; i < n; i++){
		fs[a[i]] = min(fs[a[i]], i);
		ls[a[i]] = max(ls[a[i]], i);
		vec[a[i]].push_back(i);
	}

	for (int i = q; i; i--){
		for (int ind:vec[i])
			add(ind+1, 1);

		if (vec[i].size()){
			int t = get(ls[i]+1) - get(fs[i]);
			if (t != ls[i] - fs[i] + 1)
				return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	int ind = -1;
	for (int l = 0; l < n;){
		if (a[l]){
			l++;
			continue;
		}

		int r = l;
		ind = l;
		while (r < n && a[l] == a[r]) r++;

		int mx = -1;
		if (l)
			mx = max(mx, a[l-1]);
		if (r < n)
			mx = max(mx, a[r]);
		if (mx == -1)
			mx = q;

		for (int i = l; i < r; i++)
			a[i] = mx;
	
		l = r;
	}
	int mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, a[i]);
	if (mx < q){
		if (ind != -1)
			a[ind] = q;
		else{
			cout << "NO\n";
			return 0;
		}
	}
	if (ok()){
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	else
		cout << "NO\n";
	return 0;
}