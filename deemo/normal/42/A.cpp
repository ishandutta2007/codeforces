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

int main(){
	read_fast;
	int n, v;
	cin >> n >> v;
	vector<int>	vec(n), sec(n);
	for (int i = 0; i < n; i++)
		cin >> sec[i];
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	double b = 0, e = vec[0], mid, ret;
	for (int i = 0; i < 100; i++){
		mid = (b + e)/ 2;
		
		bool fl = 1;
		{
			for (int i = 1; i < n; i++){
				double t = double(sec[i])/ sec[0];
				t *= mid;
				if (t >= vec[i])	fl = 0;
			}
		}
		if (fl){
			ret = mid;
			b = mid;
		}
		else	e = mid;
	}
	double sum = e;
	for (int i = 1; i < n; i++){
		double t = double(sec[i])/ sec[0];
		t *= e;
		sum += t;
	}	

    setprecision(8);
	cout << min(double(v), sum) << endl;
	return 0;
}