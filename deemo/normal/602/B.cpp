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

const int max_n = 1e5 + 100;

int n, a[max_n];
multiset<int>	st;

bool check(int x){
	st.insert(x);
	multiset<int>::iterator it = st.end();
	it--;
	if (*it - *st.begin() <= 1)	return	true;
	st.erase(st.find(x));
	return	false;
}

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b = 0, e = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		while (e < n && check(a[e]))	e++;

		ans = max(ans, e - b);
		st.erase(st.find(a[b]));
		b++;
	}
	cout << ans << endl;
    return 0;
}