#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main()
 {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
	    int a, b;
	    cin >> a >> b;
	    int ans = b - a;
        if(ans < 0) {
            cout << -ans << endl;
            continue;
        }
	    int bits = a & ~b;
	    int cnt = 1;
	    while(cnt <= bits) {
	        cnt *= 2;
	    }
        unsigned long long cnt2 = 1;
        for(int i = 0; i < bits; i++) {
            cnt2 *= 2;
            if(cnt2 > bits) break;
        }
	    int ans2 =  -(b & (cnt - 1)) + 1 + (a & (cnt - 1));

        if(ans2 < ans) {
            ans = ans2;
        }
        int ans4 = b - a + 6;
		while ((ans > ans4) || ((b & cnt) == 0) || ((a & cnt) > 0))
		{
			cnt = cnt << 1;
		}
        int ans3 = b - a + 9;
        ans = min(ans, ans3);
 		int ans5 = cnt - (a & (cnt - 1)) + 1;
        if(ans5 < ans) {
            ans = ans5;
        }
		
		cout << ans << endl;
	}
	return 0;
}