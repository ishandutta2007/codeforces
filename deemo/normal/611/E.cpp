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

const int MAXN = 2e5 + 20;

int n, sum, ans;
int x[4];
int vec[MAXN], d[MAXN], gec[MAXN];
multiset<int>	st;

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < 3; i++){
		cin >> x[i];
		sum += x[i];
	}
	sort(x, x + 3);

	d[0] = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i] > sum){
			cout << -1 << "\n";
			return 0;
		}
		if (vec[i] > sum - x[0]){
			ans++;
			continue;
		}	
		st.insert(vec[i]);
	}

	while (st.size()){
		multiset<int>::iterator it = st.end();	it--;
		if (*it > x[2]){
			int y;
			if (sum - x[2] >= *it)	y = x[2];
			else if (sum - x[1] >= *it)	y = x[1];
			else	y = x[0];
			st.erase(it);
			it = st.upper_bound(y);
			if (it != st.begin()){
				it--;
				st.erase(it);
			}
		}
		else{
			st.erase(it);
			if (st.size()){
				it = st.begin();
				if (*it <= x[1]){
					it = st.upper_bound(x[1]);
					it--;
					st.erase(it);
					it = st.upper_bound(x[0]);
					if (it != st.begin()){
						it--;
						st.erase(it);
					}
				}
				else{
					it = st.upper_bound(x[0] + x[1]);
					if (it != st.begin()){
						it--;
						st.erase(it);
					}
				}
			}
		}
		ans++;
	}
	cout << ans << endl;
    return 0;
}