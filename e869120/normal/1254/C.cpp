#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; vector<long long> Answer;
vector<pair<long long, long long>> vec1, vec2;
vector<pair<long long, long long>> a1, a2, a3, a4;

int main() {
	cin >> N;

	// Step 1
	for (int i = 3; i <= N; i++) {
		cout << "1 1 2 " << i << endl;
		long long v1; cin >> v1;
		cout << "2 1 2 " << i << endl;
		long long v2; cin >> v2;
		if (v2 == -1) vec1.push_back(make_pair(v1, i));
		if (v2 == 1) vec2.push_back(make_pair(v1, i));
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	Answer.push_back(1);

	// Step 2
	if (vec1.size() >= 1) {
		long long maxv = vec1[vec1.size() - 1].second;
		for (int i = 0; i < vec1.size(); i++) {
			if (vec1[i].second == maxv) continue;
			cout << "2 1 " << maxv << " " << vec1[i].second << endl;
			long long v3; cin >> v3;
			if (v3 == -1) a1.push_back(vec1[i]);
			if (v3 == 1) a2.push_back(vec1[i]);
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end()); reverse(a2.begin(), a2.end());
		for (int i = 0; i < a1.size(); i++) Answer.push_back(a1[i].second);
		Answer.push_back(maxv);
		for (int i = 0; i < a2.size(); i++) Answer.push_back(a2[i].second);
	}
	Answer.push_back(2);

	// Step 3
	if (vec2.size() >= 1) {
		long long maxv = vec2[vec2.size() - 1].second;
		for (int i = 0; i < vec2.size(); i++) {
			if (vec2[i].second == maxv) continue;
			cout << "2 1 " << maxv << " " << vec2[i].second << endl;
			long long v3; cin >> v3;
			if (v3 == -1) a3.push_back(vec2[i]);
			if (v3 == 1) a4.push_back(vec2[i]);
		}
		sort(a3.begin(), a3.end());
		sort(a4.begin(), a4.end()); reverse(a4.begin(), a4.end());
		for (int i = 0; i < a3.size(); i++) Answer.push_back(a3[i].second);
		Answer.push_back(maxv);
		for (int i = 0; i < a4.size(); i++) Answer.push_back(a4[i].second);
	}

	// Output
	cout << "0"; for (int i = 0; i < Answer.size(); i++) cout << " " << Answer[i];
	cout << endl;
	return 0;
}