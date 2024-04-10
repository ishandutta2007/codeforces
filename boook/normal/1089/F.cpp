#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k)  for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define IOS cin.tie(0) , cout.sync_with_stdio(0)

int n;
vector<int> v;
int main(){
	IOS;
	cin >> n;
	int val = n;
	REP(i , 2 , val + 1){
		if(i * i > n) break;
		if(val % i == 0){
			while(val % i == 0) val /= i;
			v.push_back(i);
		}
	}
	if(val != n && val != 1) v.push_back(val);
	REP(i , 1 , v.size()){
		int pre = v[i - 1] , now = v[i];
		if(__gcd(pre , now) == 1){
			cout << "YES" << endl;
			int v1 = n / pre , v2 = n / now;
			REP(j , 0 , n + 1){
				if((n - 1 - pre * j) % now == 0){
					int sum = (n - 1 - pre * j) / now;
					cout << 2 << endl;
					cout << sum << " " << v2 << endl;
					cout <<   j << " " << v1 << endl;
					return 0;
				}
			}
			cout << "no ans" << endl;
			assert(0);
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}