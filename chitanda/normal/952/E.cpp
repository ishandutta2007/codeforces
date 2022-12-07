#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

int n;
string name[110], tp[110];

int main(){
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; ++i){
		cin >> name[i] >> tp[i];
		if(tp[i] == "hard") ++cnt1;
		else ++cnt2;
	}
	int res = 1;
	if(cnt1 > cnt2) swap(cnt1, cnt2);
	while((res * res + 1) / 2 < cnt2 || res * res / 2 < cnt1) ++res;
	cout << res;
	
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}