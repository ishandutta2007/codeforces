#include <bits/stdc++.h>

using namespace std;

struct Exm{
	int first,second,third;
	bool operator>(Exm target) const{
		return first > target.first;
	}
};

int unprepared_exams[105], have_exam[105];

int main()
{
	int n, m, s, d, c;
	priority_queue<Exm, vector<Exm>, greater<Exm>> pq;
	vector<Exm> a[105];
	vector<int> ans;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> s >> d >> c;
		a[s].push_back({d, c, i});
		unprepared_exams[d]++;
		have_exam[d]++;
	}
	for(int day = 1; day <= n; day++) {
		for(auto exm:a[day]) pq.push(exm);
		if(have_exam[day]) {
			if(unprepared_exams[day]) {
				cout << -1 << endl;
				return 0;
			} else {
				ans.push_back(m+1);
			}
			continue;
		}
		if(pq.empty()) {
			ans.push_back(0);
			continue;
		}
		Exm fde = pq.top();
		fde.second--;
		pq.pop();
		ans.push_back(fde.third+1);
		if(fde.second)
			pq.push(fde);
		else {
			unprepared_exams[fde.first]--;
		}
	}
	for(int i:ans) cout << i << " ";
	cout << endl;
}