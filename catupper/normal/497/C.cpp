#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<set>
using namespace std;
typedef tuple<int, int> P;
typedef tuple<int, int, int> T;
typedef tuple<int, int, int, int> Q;

set<T> ok;
vector<T> task;
vector<Q> actor;
int n, a, b, c, d, k, m;
int ans[108000];

void fail(){
	cout <<"NO" << endl;
	exit(0);
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		task.push_back(T(a, b, i));
	}
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> c >> d >> k;
		actor.push_back(Q(c, d, k, i));
	}
	sort(task.begin(), task.end());
	sort(actor.begin(), actor.end());
	int l = 0, r = 0;
	for(int i = 0;i < n;i++){
		while(r < actor.size() && get<0>(actor[r]) <= get<0>(task[i])){
			ok.insert(T(get<1>(actor[r]), get<2>(actor[r]), get<3>(actor[r])));
			r++;
		}
		auto it = ok.lower_bound(T(get<1>(task[i]), 0, 0));
		if(it == ok.end())fail();
		auto tmp = *it;
		ok.erase(it);
		if(--get<1>(tmp)){
			ok.insert(tmp);
		}
		ans[get<2>(task[i])] = get<2>(tmp);
	}
	cout << "YES" << endl;
	for(int i = 0;i < n;i++)cout << ans[i] << " \n"[i==n-1] ;
	return 0;	
}