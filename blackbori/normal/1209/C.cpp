#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[202020];
string S;
int n;

void tc()
{
	int i, j, x, v1, v2, l, r, f;
	
	cin >> n >> S;
	
	for(i=0; i<=9; i++){
		v1 = 0; v2 = i;
		l = r = -1;
		f = 0;
		
		for(j=0; j<n; j++){
			x = S[j] - '0';
			if(x < i){
				if(v1 > x) f = 1;
				else v1 = x;
				r = j;
				A[j] = 1;
			}
			else if(x > i){
				if(l == -1) l = j;
				if(v2 > x) f = 1;
				else v2 = x;
				A[j] = 2;
			}
		}
		
		for(j=0; j<n; j++){
			x = S[j] - '0';
			if(x == i){
				if(j < l) A[j] = 2;
				else if(j > r) A[j] = 1;
				else f = 1;
			}
		}
		
		if(f == 0){
			for(j=0; j<n; j++) cout << A[j];
			cout << "\n"; return;
		}
	}
	
	cout << "-\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	for(; t--; ){
		tc();
	}
	
	return 0;
}