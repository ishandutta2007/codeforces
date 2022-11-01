#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;
int a[maxn];
long long b[maxn];
int pre[maxn];
string str;
long long ans = 0;
int blk = 300;
int f[maxn];

int main(){
	int i, j, k;
	
	cin >> str;
	n = str.length();
	
	for(i=0;i<str.length();i++){
		a[i + 1] = str[i] - '0';
		pre[i + 1] = pre[i] + a[i + 1];
	}
	
	for(k=1;k<=blk;k++){
		for(i=0;i<=n;i++){
			b[i] = 1ll * k * pre[i] - i;
		}
		
		sort(b, b + n + 1);
		
		for(i=0;i<=n;i+=j){
			for(j=0;i+j<=n;j++){
				if(b[i] != b[i + j])break;
			}
			ans += 1ll * j * (j - 1) / 2;
		}
	}
	
	for(i=n;i>0;i--){
		if(a[i]){
			f[i] = 0;
		}else{
			f[i] = f[i + 1] + 1;
		}
	}
	
	for(i=1;i<=n;i++){
		int l = i + f[i];
		int r = l + 1 + f[l + 1] - 1;
		for(j=1;j*(blk+1)<=n and r <= n;j++){
			ans += max(0, (r - i + 1) / j - max((l - i) / j, blk));
			l = l + 1 + f[l + 1];
			r = l + 1 + f[l + 1] - 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}