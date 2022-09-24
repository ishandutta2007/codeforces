#include <bits/stdc++.h>

using namespace std;

vector <int> K;
int n, k;

int query(int t)
{
	vector <int> V;
	int i, a, b;
	
	for(i = 1; i < t; i ++) V.push_back(i);
	for(i ++; i <= k + 1; i ++) V.push_back(i);
	
	cout << "?";
	
	for(int &x: V) cout << " " << x;
	
	cout << "\n"; cout.flush();
	
	cin >> a >> b;
	
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n >> k;
	
	for(i = 1; i <= k + 1; i ++){
		K.push_back(query(i));
	}
	
	sort(K.rbegin(), K.rend());
	
	for(i = 0; K[0] == K[i]; i ++);
	
	cout << "!" << " " << i << "\n";
	
	cout.flush();
	
	return 0;
}