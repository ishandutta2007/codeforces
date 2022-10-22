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
	string str, cf = "CODEFORCES*";
	string cff = "*CODEFORCES";
	cin >> str;
	int l = -1, r = -1;
	for(int i = 0;i < str.size();i++){
		if(cf[i] != str[i])break;
		l = i;
	}
	l++;
	for(int i = 0;i < str.size();i++){
		if(cff[cff.size() - i - 1] != str[str.size() - i - 1])break;
		r = i;
	}
	r++;
	if(l + r >= 10)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}