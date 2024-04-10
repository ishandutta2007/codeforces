#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int D[10101];
string S;
int n, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, a, b, c, s;
	
	cin >> n >> S;
	
	for(i=0; i<n; i++){
		cin >> a >> b;
		if(S[i] == '0') c = 0;
		else c = 1;
		
		for(j=0, s=-1; j<=10000; j++){
			s ++;
			if(s == b){
				c = !c; s -= a;
			}
			D[j] += c;
		}
	}
	
	for(i=0; i<=10000; i++){
		ans = max(ans, D[i]);
	}
	
	cout << ans << "\n";
	
	return 0;
}