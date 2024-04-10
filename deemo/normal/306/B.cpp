#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define Thing pair<pair<int, int>, int>
#define left first.first
#define right first.second
#define id second

const int MAXM = 2e5 + 10;
const int MAXVAL = 2e6 + 10;

int n, m;
Thing vec[MAXM];
vector<int>	ans;
bool pic[MAXM];
pair<int, int>	weed[4 * MAXVAL];

bool cmp(Thing a, Thing b){
	if (a.left != b.left)
		return	a.left < b.left;
	if (a.right != b.right)
		return	a.right > b.right;
	return	a.id < b.id;
}

void water(int v, int b, int e, int x, int val, int ind){
	if (e - b == 1){
		weed[v] = {val, ind};
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val, ind);
	else
		water(v<<1^1, mid, e, x, val, ind);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

pair<int, int> smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	{-1, -1};

	int mid = (b + e)/ 2;
	return	max(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> vec[i].left >> vec[i].right, vec[i].right += vec[i].left - 1, vec[i].id = i;
	sort(vec, vec + m, cmp);

	for (int i = 0; i < m; ){
		int j = i, mx = 0, ind = -1;
		while (j < m && vec[i].left == vec[j].left){
			if (mx < vec[j].right)
				mx = vec[j].right, ind = j;
			j++;
		}
		water(1, 0, MAXVAL, vec[i].left, mx, ind);
		i = j;
	}

	int mx = 0;
	for (int i = 0; i < m;){
		pic[vec[i].id] = 1;
		mx = max(mx, vec[i].right);
		auto v = smoke(1, 0, MAXVAL, 0, mx + 2);

		if (v.first > mx)
			i = v.second;
		else
			i = lower_bound(vec, vec + m, make_pair(make_pair(mx + 2, -1), -1)) - vec;
	}

	for (int i = 0; i < m; i++)
		if (!pic[i])	ans.push_back(i);
	cout << ans.size() << "\n";
	for (int u:ans)
		cout << u + 1 << " ";
	cout << "\n";
	return	0;
}