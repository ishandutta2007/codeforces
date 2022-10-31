#include <iostream>
using namespace std;
int main(){
	long long cnt[33]={0};
	int n, t, xd;
	cin >> n;
	while(n--){
		cin >> t; xd = 0;
		while(t){
			if(t&1) ++xd;
			t>>=1;
		}
		cnt[xd]++;
	}
	long long ans = 0;
	for(int i = 1; i<=32; ++i)
		ans += (cnt[i]*(cnt[i]-1))>>1;
	cout << ans << endl;
	return 0;
}