#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct Pair{
	int first, second;
	Pair(int a, int b): first(a), second(b){}
};

bool operator < (Pair a, Pair b){
	if (a.second != b.second)
		return	a.second > b.second;
	return	a.first < b.first;
}

struct Snowman{
	int a, b, c;
	Snowman(int first, int second, int third): a(first), b(second), c(third){}
};

int n;
map<int, int>	mp;
set<Pair>	st;
vector<Snowman>	ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int t;	scanf("%d", &t);
		int x = mp[t];
		st.erase(Pair(t, x));
		x++;
		mp[t] = x;
		st.insert(Pair(t, x));
	}

	vector<int>	sec(3);
	vector<Pair> vec;
	while (st.size() >= 3){
		set<Pair>::iterator it = st.begin();
		vec.clear();

		for (int i = 0; i < 3; i++){
			sec[i] = (*it).first;
			int t = (*it).second - 1;
			if (t != 0)	vec.push_back(Pair(sec[i], t));
			it++;
		}
		for (int i = 0; i < 3; i++)
			st.erase(st.begin());
		for (int i = 0; i < vec.size(); i++)
			st.insert(vec[i]);
		sort(sec.begin(), sec.end());
		reverse(sec.begin(), sec.end());
		ans.push_back(Snowman(sec[0], sec[1], sec[2]));
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
	return 0;
}