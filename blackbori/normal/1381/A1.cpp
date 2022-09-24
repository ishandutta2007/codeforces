#include <bits/stdc++.h>

using namespace std;

void tc()
{
	vector <int> V;
	int n, i, s, e, f;
	string A, B;

	cin >> n >> A >> B;

	s = 0; e = n - 1;
	for(i = n - 1, f = 0; i >= 0; i --){
		if(!f){
			if(A[e] != B[i]){
				if(A[s] != B[i]) V.push_back(i + 1);
				else V.push_back(1), V.push_back(i + 1);
				f = !f; s ++;
			}
			else e --;
		}
		else{
			if(A[s] == B[i]){
				if(A[e] == B[i]) V.push_back(i + 1);
				else V.push_back(1), V.push_back(i + 1);
				f = !f; e --;
			}
			else s ++;
		}
	}

	cout << V.size();
	for(int &t: V) cout << " " << t;
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	
	for(; t --; ) tc();

	return 0;
}