//  228

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include <queue>
#include <map>
#define debug1 cout<<"^^";
#define debug2 cout<<"&&";
#define ms(a, x) memset(a, x, sizeof(a))
#define inf 0x3f
#define INF 0x3fefefef
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N = 1e5+5;
const int mod = 1e9 + 7;

ll num;
string str;
string minn, maxn;

int main() {
//	cin >> num;
	cin >> str;
	int len = str.size();
	if(str.size() <= 11) {
		int tmp = 1;
		for(int i = 0; i < len; ++i) {
			if(str[i] == '-') {
				tmp = -1;
				continue;
			}
			num *= 10;
			num += str[i] - '0';
		}
		num *= tmp;
//		debug1 cout << num << endl;
		if(num >= -128 && num <= 127) cout << "byte" << endl;
		else if(num >= -32768 && num <= 32767) cout << "short" << endl;
		else if(num >= -2147483648 && num <= 2147483647) cout << "int" << endl;
		else cout << "long" << endl;
	} else if(str[0] != '-') {
		if(len > 19) cout << "BigInteger" << endl;
		else {
			maxn = "9223372036854775807";
			if(str <= maxn) cout << "long" << endl;
			else cout << "BigInteger" << endl;
		}
	} else {
		maxn = "9223372036854775807";
		string tmp;
		for(int i = 1; i < len; ++i) {
			tmp += str[i];
		}
		if(len > 19) cout << "BigInteger" << endl;
		else {
			if(tmp <= maxn) cout << "long" << endl;
			else cout << "BigInteger" << endl;
		}
	}
}