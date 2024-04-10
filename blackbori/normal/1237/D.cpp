#include <bits/stdc++.h>

using namespace std;

int A[404040], N[404040], P[404040];
deque <int> D;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
		A[n + n + n + i] = A[n + n + i] = A[n + i] = A[i];
	}
	
	for(i=0; i<n+n+n+n; i++){
		P[i] = -1;
		
		for(; !D.empty() && A[D.front()] > A[i] * 2; D.pop_front()){
			N[D.front()] = i - D.front();
		}
		
		for(; !D.empty() && A[D.back()] <= A[i]; D.pop_back()){
			N[D.back()] = i - D.back();
			P[D.back()] = i;
		}
		
		D.push_back(i);
	}
	
	for(i=n+n+n+n-1; i>=0; i--){
		if(P[i] != -1) N[i] += N[P[i]];
	}
	
	for(i=0; i<n; i++){
		if(N[i] > n + n) cout << -1 << " ";
		else cout << N[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}