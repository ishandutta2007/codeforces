#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define vi vector<int>

#define F0R(i, a) for (int i=0; i<a; i++)
#define b begin
#define e end

int n,x, ans=0;
vi nums;
map<int,int> pos, news;

void dp(int a, int b) {
	int c1 = 2;
	news.clear(), news[a] ++, news[b] ++;
	while (news[a+b]+1<=pos[a+b]) {
		x = a, a = b, b = a+x, news[b] ++;
		c1++;
	}
	ans = max(ans,c1);
}

int main() {
    cin >> n;
    F0R(i,n) scanf("%d",&x), nums.pb(x), pos[x] ++;
    sort(nums.b(),nums.e()), nums.erase( unique( nums.b(), nums.e() ), nums.e() );
    F0R(i,nums.size()) F0R(j,nums.size()) if (i != j || (i == j && pos[nums[i]] > 1)) dp(nums[i],nums[j]);
    cout << ans << endl;
	return 0;
}