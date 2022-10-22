#include<bits/stdc++.h>

using namespace std;

int ln, s, t, x, y, ans = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> ln >> s >> t;
	cin >> x >> y;
	ans = abs(s-t) * y;
	int a, b;	cin >> a >> b;
	if (s <= t){
		if (a <= s)
			ans = min(ans, (t-a) * x + (b<0?2*a*x:0));
		else{
			if (s < a && a <= t){
				if (b < 0)
					ans = min(ans, (t-a)*x + 2*a*x);
				else
					ans = min(ans, 2*ln*x + (t-a)*x);
			}
			else{
				ans = min(ans, (b<0?0:(ln-a)*2*x) + a * 2 * x - (a-t) * x);
			}
		}
	}
	else{
		if (a >= s)
			ans = min(ans, (a-t) * x + (b>0?2*(ln-a)*x:0));
		else{
			if (t <= a && a <= s){
				if (b > 0)
					ans = min(ans, (a-t)*x + 2*(ln-a)*x);
				else
					ans = min(ans, 2*ln*x + (a-t)*x);
			}
			else{
				ans = min(ans, (b>0?0:a*2*x) + (ln-a) * 2 * x - (t-a) * x);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}