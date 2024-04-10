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

int n;
const int N = 2e5+5;
vector<pii> A,B;
int match[N];

int main() {	
	scanf("%d",&n);
	A = B = vector<pii>(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&A[i].first);
		A[i].second = i;
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d",&B[i].first);
		B[i].second = i;
	}
	sort(A.begin(),A.end());
	sort(B.rbegin(),B.rend());
	for(int i = 0; i < n; ++i) {
		match[B[i].second] = A[i].first;
	}
	for(int i = 0; i < n; ++i) {
		printf("%d ",match[i]);
	}
	printf("\n");
}