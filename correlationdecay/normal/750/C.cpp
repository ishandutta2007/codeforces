#include <bits/stdc++.h>
using namespace std;
const long long INF  = 1e18;
int main(){
	int n;
	cin >> n;
	long long  L = -INF, R = +INF;
	long long cur = 0;
	while(n--){
		int a, b;
		cin >> a >> b;
		if(b == 1){
			L = max(L, 1900LL-cur);
		}
		else{
			R= min(R,1899LL - cur);
		}
		cur += a;
		if(L>R){
			puts("Impossible");
			return 0;
		}
	}
	if(R >= INF){
		puts("Infinity");
	}
	else{
		cout <<R + cur<<endl;
	}
	//system("pause");
	return 0;
}