#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })
#define Edge pair<pair<int, int>, int>
#define type first.second
#define weight first.first
#define id second

const int MAX = 1e5 + 200;

int n, m;
Edge vec[MAX];
pair<int, int>	ans[MAX];
vector<pair<int, int>>	sec;
int sz;

bool cmp(Edge a, Edge b){
	if (a.weight != b.weight)
		return	a.weight < b.weight;
	return	a.type > b.type;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &vec[i].weight, &vec[i].type);
		vec[i].id = i;
	}		
	sort(vec, vec + m, cmp);
	
	for (int i = 0; i < m; i++){
		Edge temp = vec[i];
		if (temp.type == 0){
			if (sec.empty()){
				printf("-1\n");
				return 0;
			}
			else{
				ans[temp.id] = sec.back();
				sec.pop_back();
			}
			continue;
		}
		
		if (sz == 0){
			sz = 2;
			ans[temp.id] = {1, 2};
		}
		else{
			for (int j = 1; sec.size() < MAX && j < sz; j++)
				sec.push_back({sz + 1, j});
			ans[temp.id] = {sz + 1, sz};
			sz++;
		}	
	}

	for (int i = 0; i < m; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}