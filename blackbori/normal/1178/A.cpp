#include <bits/stdc++.h>

using namespace std;

vector <int> V;
int A[111];
int n, s, v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(i=1; i<=n; i++){
		cin >> A[i];
		s += A[i];
	}
	
	v = A[1]; V.push_back(1);
	
	for(i=2; i<=n; i++){
		if(A[i] + A[i] <= A[1]){
			v += A[i];
			V.push_back(i);
		}
	}
	
	if(v + v > s){
		cout << (int)V.size() << "\n";
		
		for(int &t: V){
			cout << t << " ";
		}
		
		cout << "\n";
	}
	else cout << "0\n";
	
	return 0;
}