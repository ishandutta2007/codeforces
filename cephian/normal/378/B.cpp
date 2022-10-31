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

const int N = 1e5+5;
int a[N],b[N],n,k;
bool A[N]={},B[N]={};

vector<int> all;
set<int> ok;

int main() {	
	scanf("%d",&n);
	k = n/2;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d",a+i,b+i);
		if(i < k) A[i] = B[i] = true;
		all.pb(a[i]);
		all.pb(b[i]);
	}
	sort(all.begin(),all.end());
	for(int i = 0; i < n; ++i) {
		ok.insert(all[i]);
	}
	for(int i = 0; i < n; ++i) {
		if(ok.count(a[i])) A[i] = true;
		if(ok.count(b[i])) B[i] = true;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		cout << A[i];
	}
	cout << "\n";
	for(int i = 0; i < n; ++i) {
		cout << B[i];
	}
	cout << "\n";
}