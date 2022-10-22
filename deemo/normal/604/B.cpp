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

int n, k;
int a[max_n];
deque<int>	saf;

bool ok(int s){
	saf.resize(n);
	copy(a, a + n, saf.begin());
	
	int cnt = 0;
	while (saf.size()){
		int x = saf.front();	saf.pop_front();
		while (saf.size() && saf.back() + x > s){
			cnt++;
			saf.pop_back();
		}
		if (saf.size())	saf.pop_back();
		cnt++;
	}
	return	cnt <= k;
}

int main(){
	read_fast;
	cin >> n >> k;
	int b = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b = max(b, a[i]);
	}
	int e = 3e6, mid, ret = 1e8;
	while (b <= e){
		mid = (b + e)/ 2;
		if (ok(mid)){
			ret = mid;
			e = mid - 1;
		}
		else	b = mid + 1;
	}	
	cout << ret << endl;
    return 0;
}