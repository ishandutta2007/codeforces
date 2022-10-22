#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t,n,a,b,c,d,sum;
	cin >> t;
	while(t--){
		cin >> n >> a >> b >> c >> d;
		sum = 0;
		n /= 2;
		for(int i = 0; i < n; i++){
			if(a && c > d * (bool)b){
				a--;
				sum += c;
			}else if(b){
				b--;
				sum += d;
			}
		}
		cout << sum << endl;
	}
}