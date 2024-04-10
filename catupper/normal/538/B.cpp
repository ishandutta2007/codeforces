#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;
#define INF (1<<29)
#define MOD 1000000007

int val[108000];
string str;
int main(){
	cin >> str;
	int n = str.size();
	int res = 0;
	for(int i = 0;i < n;i++){
		val[i] = str[i] - '0';
		res = max(res, val[i]);
	}
	cout << res << endl;
	for(int i = 1;i <= res;i++){
		int ans = 0;
		if(i != 1)cout << " ";
		for(int j = 0;j < n;j++){
			ans *= 10;
			ans += val[j] >= i;
		}
		cout << ans;
	}
	cout << endl;
	return 0;
}