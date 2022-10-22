#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> T;
int ans[105000];
P a[105000];
int tmp[105000];
T student[105000];
int n, m, s;
bool solve(int x){
	long long p = 0, t = 0;
	priority_queue<P, vector<P>, greater<P> > pq;
	for(int i = m - 1;i >= 0;i -= x){
		while(t < n && student[t].first >= a[i].first)pq.push(student[t].second),t++;
		if(pq.empty())return false;
		p += pq.top().first;
		for(int j = i;j >= 0 && j > (i - x);j--)tmp[a[j].second] = pq.top().second;
		pq.pop();
	}
	if(p > s)return false;
	for(int i = 1;i <= m;i++)ans[i] = tmp[i];
	return true;
}

int main(){
	cin >> n >> m >> s;
	for(int i = 0;i < m;i++)cin >> a[i].first;
	for(int i = 0;i < m;i++)a[i].second = i + 1;
	for(int i = 0;i < n;i++)cin >> student[i].first;
	for(int i = 0;i < n;i++)cin >> student[i].second.first;
	for(int i = 0;i < n;i++)student[i].second.second = i + 1;
	sort(student, student + n, greater<T>());	
	sort(a, a + m);
	int top = m + 1, bottom = 0;
	while(top - bottom > 1){
		int mid = (top + bottom) / 2;
		if(solve(mid))top = mid;
		else bottom = mid;
	}
	if(top == m + 1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 1;i <= m;i++){
		if(i - 1)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}