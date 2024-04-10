#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int a[4] = {6,8,4,2};

int main() {	
	int n;
	cin >> n;
	if(n == 0) cout << "1\n";
	else cout << a[n&3] << "\n";


}