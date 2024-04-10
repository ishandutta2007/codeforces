#include <bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <vector <int>> Q;
	vector <pii> V, Y;
	int n, d, i, j, l, a, b, c, f;

	cin >> n;

	for(i = 1; i <= n; i ++){
		cin >> d;
		V.emplace_back(d, d + 1);
	}

	for(; ; ){
		f = 0;
		for(i = 0; i < V.size(); i ++){
			for(j = i + 1; j < V.size(); j ++){
				if(V[i].first == V[j].second){
					f = 1; break;
				}
			}
			if(f) break;
		}
		if(i == V.size()){
			break;
		}
		a = b = c = 0;
		for(l = 0; l < i; l ++) a += V[l].second - V[l].first;
		for(; l < j; l ++) b += V[l].second - V[l].first;
		for(l ++; l < V.size(); l ++){
			c += V[l].second - V[l].first;
			Y.push_back(V[l]);
		}

		vector <int> X;
		if(a) X.push_back(a);
		if(b) X.push_back(b);
		X.push_back(V[j].second - V[j].first);
		if(c) X.push_back(c);
		Q.push_back(X);

		Y.emplace_back(V[j].first, V[i].second);
		for(l = i + 1; l < j; l ++) Y.push_back(V[l]);
		for(l = 0; l < i; l ++) Y.push_back(V[l]);
		swap(V, Y); Y.clear();
	}

	cout << Q.size() << "\n";
	for(auto &X: Q){
		cout << X.size();
		for(auto &t: X) cout << " " << t;
		cout << "\n";
	}

	return 0;
}