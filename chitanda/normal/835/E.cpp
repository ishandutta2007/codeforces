#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, x, y, xx;
int tag[10];

int main(){
	scanf("%d%d%d", &n, &x, &y);
	int t = -1;
	for(int i = 0; i < 10; ++i){
		int cnt = 0;
		vector<int> v;
		for(int j = 1; j <= n; ++j)
			if(j >> i & 1){
				cnt++;
				v.pb(j);
			}
		if(!cnt) continue;
		printf("? %d", cnt);
		for(auto x : v) printf(" %d", x);
		puts("");
		fflush(stdout);
		scanf("%d", &xx);
		int aim = cnt & 1 ? y : x ^ y;
		if(xx == aim){
			tag[i] = 1;
			t = i;
		}
	}
	int ans1 = 0, ans2 = 1 << t;
	for(int i = 0; i < 10; ++i){
		if(i == t) continue;
		int cnt = 0;
		vector<int> v;
		for(int j = 1; j <= n; ++j)
			if((j >> i & 1) && (j >> t & 1)){
				cnt++;
				v.pb(j);
			}
		if(!cnt){
			if(tag[i]) ans1 += 1 << i;
			continue;
		}
		printf("? %d", cnt);
		for(auto x : v) printf(" %d", x);
		puts("");
		fflush(stdout);
		scanf("%d", &xx);
		int aim = cnt & 1 ? y : x ^ y;
		if(aim == xx){
			if(tag[i]) ans2 += 1 << i;
			else ans1 += 1 << i, ans2 += 1 << i;
		}else{
			if(tag[i]) ans1 += 1 << i;
		}
	}
	printf("! %d %d\n", ans1, ans2);
	fflush(stdout);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}