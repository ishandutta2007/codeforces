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
	int k;
	cin >> k;
	vector<int>	c(30, 0);
	int cnt = 0, g = -1, sum = 0;
	for (int i = 0; i < k; i++){
		cin >> c[i];
		sum += c[i];
		if (c[i] % 2 == 1)	cnt++;

		if (g == -1)	
			g = c[i];
		else
			g = __gcd(g, c[i]);
	}

	if (cnt > 1){
		cout << 0 << endl;
		for (int i = 0; i < k; i++)
			for (int j = 0; j < c[i]; j++)
				cout << char(i + 'a');
		cout << "\n";
		return	0;
	}

	string s1 = "", s2 = "";
	if (g % 2 == 0){
		for (int i = 0; i < k; i++){
			c[i] /= g;
			for (int j = 0; j < c[i]; j++)
				s1 += i + 'a';
		}
		s2 = s1;
		reverse(s2.begin(), s2.end());
	}
	else{
		sum /= g;
		s1.resize(sum);
		int cur = 0;
		for (int i = 0; i < k; i++){
			c[i] /= g;
			if (c[i] % 2 == 1)	
				s1[sum/2] = i + 'a';
			for (int j = 1; 2 * j <= c[i]; j++, cur++)
				s1[cur] = s1[sum - cur- 1] = i + 'a';
		}
		s2 = s1;
	}
	cout << g << "\n";
	for (int i = 0; i < g; i++)
		if (i % 2 == 0)
			cout << s1;
		else
			cout << s2;
	cout << "\n";
    return 0;
}