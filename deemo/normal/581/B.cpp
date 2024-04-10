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
	int n;	cin >> n;
	vector<int>	vec(n), ans;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	int maxi = 0;
	for (int i = n - 1; i >= 0; i--){
		if (i == n - 1)	ans.push_back(0);
		else	ans.push_back(max(0, maxi - vec[i] + 1));
		maxi = max(maxi, vec[i]);
	}
	for (int i = n - 1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << endl;
    return 0;
}