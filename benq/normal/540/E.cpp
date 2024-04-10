#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define F0R(i, a) for (int i=0; i<a; i++)

int n, tree[1000000];
ll ans;
vi nums;
vector<pii> todo;
map<int,int> pos, pos2, code;

void modify(int ind, int l, int r, int pos) {
	if (l>pos || r<pos) return;
	if (l == pos && r == pos) {
		tree[ind] = 1;
		return;
	}
	modify(2*ind,l, (l+r)/2,pos);
	modify(2*ind+1,(l+r)/2+1, r,pos);
	tree[ind] = tree[2*ind]+tree[2*ind+1];
}

int query(int ind, int l, int r, int a, int b) {
	if (l>b || r<a) return 0;
	if (a <= l && r <= b) return tree[ind];
	return query(2*ind,l,(l+r)/2,a,b)+query(2*ind+1,(l+r)/2+1,r,a,b);
}

int main() {
	cin >> n;
	F0R(i,n) {
		int a,b,c;
		scanf("%d%d",&a,&b);
		if (!pos[a]) pos[a] = a, nums.pb(a);
		if (!pos[b]) pos[b] = b, nums.pb(b);
		c = pos[b], pos[b] = pos[a], pos[a] = c;
	}
	
	sort(nums.begin(),nums.end());
	F0R(i,nums.size()) code[nums[i]] = i+1, pos2[pos[nums[i]]] = nums[i];
	F0R(i,nums.size()) {
		int a = pos2[nums[i]], b = nums[i];
		if (a > b) swap(a,b);
		ans += (b-a-(code[b]-code[a]));
	}
	
	F0R(i,nums.size()) {
		ans += query(1,1,nums.size(),code[pos2[nums[i]]],nums.size());
		modify(1,1,nums.size(),code[pos2[nums[i]]]);
	}
	cout << ans;
}