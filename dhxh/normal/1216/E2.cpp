#include <bits/stdc++.h>

using namespace std;

int q;
long long n;

string tos(long long x){
	string ret;
	if(x == 0)return "0";
	
	while(x){
		ret.push_back(x % 10 + '0');
		x /= 10;
	}
	
	reverse(ret.begin(), ret.end());
	
	return ret;
}

char getn(long long n){
	int i, j;
	long long l = 0, r = 0;
	long long x, y;
	
	for(i=1;i<=18;i++){
		r = r * 10 + 9;
		
		if(n <= (r - l) * i){
			x = i;
			break;
		}else{
			n -= (r - l) * i;
		}
		
		l = r;
	}
	
	l += (n - 1) / x + 1;
	y = (n - 1) % x;
	
	string ans = tos(l);
		
	return ans[y];
}

int main(){
	int i, j;
	int t;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		long long l = 0, r = 0;
		long long x, y;
		long long sum = 0;
		
		for(i=1;i<=18;i++){
			r = r * 10 + 9;
			
			if(n < sum * (r - l) + (r - l) * (r - l + 1) / 2 * i){
				x = i;
				break;
			}else{
				n -= sum * (r - l) + (r - l) * (r - l + 1) / 2 * i;
				sum += (r - l) * i;
			}
			
			l = r;
		}
		
		y = l;
		
		r -= l;
		l = 0;
		while(l + 1 < r){
			long long mid = (l + r) / 2;
			if(n > sum * mid + mid * (mid + 1) / 2 * x){
				l = mid;
			}else{
				r = mid;
			}
		}
		
		if(n > sum * r + r * (r + 1) / 2 * x){
			l = r;
		}
		n -= sum * l + l * (l + 1) / 2 * x;
		
		cout << getn(n) << endl;
	}
	
	return 0;
}