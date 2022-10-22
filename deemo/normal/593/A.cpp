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
	int n;
	cin >>  n;
	vector<string>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int ans = 0;
	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++){
			int temp = 0;
			for (int k = 0; k < n; k++){
				string t = vec[k];
				bool fl = 0;
				for (int w = 0; w < t.size(); w++)
					if (t[w] - 'a' != i && t[w] - 'a' != j){
						fl = 1;
						break;
					}
				if (!fl)	temp += t.size();
			}
			ans = max(ans, temp);
		}
    cout << ans << endl;
	return 0;
}