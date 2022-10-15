#include <bits/stdc++.h>

using namespace std;
int memo[200005];
int main(){
	//freopen("i.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int arr[n];
	string s;
	cin >> s;
	for(int i = 0;i < n;i++){
		arr[i] = s[i] - '0';
	}
	int ans = 0;
	
	fill(memo,memo+200004,-1);
	for(int k = 0;k < n;k++){
		if(k == 0){
			bool can = true;
			for(int i = 0;i < n;i++){
				if(arr[i] == 1) can = false;
			}
			if(can) ans++;
			continue;
		}
		
		int x = __gcd(k,n);
		
		if(memo[x] == -1){
			int can = 1;
			for(int i = 0;i < x;i++){
				int y = i;
				int cnt = 0;
				bool start = false;
				while(y != i || !start){
					cnt += arr[y];
					
					start = true;
					y += x;
					y %= n;
				}
				//if(x == 3) cout << cnt << "\n";
				if(cnt % 2 == 1){
					can = 0;
					break;
				}
			}
			memo[x] = can;
			ans += memo[x];
		}
		else{
			ans += memo[x];
		}
	}
	cout << ans;
	
	return 0;
}