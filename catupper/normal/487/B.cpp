#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define INF (1 << 30)
typedef pair<int, int> P;
int seg[1 << 19];
int ans[1 << 19];
int a[1 << 19];

void setval(int pos, int val){
	pos += 1 << 18;
	seg[pos] = val;
	while(pos /= 2){
		seg[pos] = min(seg[pos * 2], seg[pos * 2 + 1]);
	}
}

int minval(int left, int right, int bottom = 0, int top = 1 << 18, int pos = 1){
	if(right <= bottom || top <= left)return INF;
	if(left <= bottom && top <= right)return seg[pos];
	int mid = (top + bottom) / 2;
	return min(minval(left, right, bottom, mid, pos * 2),
				minval(left, right, mid, top, pos * 2 + 1));
}


int main(){
	int n, s, l;
	multiset<P> ms;
	cin >> n >> s >> l;
	for(int i = 0;i < n;i++)cin >> a[i];
	
	fill(seg, seg + (1 << 19), INF);
	fill(ans, ans + (1 << 19), INF);
	setval(n, 0);
	
	for(int i = n - 1;i >= 0;i--){
		ms.insert(P(a[i], i));
		while(ms.rbegin()->first - ms.begin()->first > s){
			ms.erase(P(a[i + ms.size() - 1], i + ms.size() - 1));
		}
		if(l <= ms.size()){
			ans[i] = minval(i + l, i + ms.size() + 1) + 1;
			ans[i] = min(ans[i], INF);
			setval(i, ans[i]);
		}
	}
	cout << ((ans[0] == INF)?-1:ans[0]) << endl;
	return 0;
}