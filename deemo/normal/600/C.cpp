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

int cnt[200];

int main(){
	read_fast;
	string s;	cin >> s;
	for (int i = 0; i < s.size(); i++)		cnt[s[i]]++;
	int g = 0;
	for (int i = 'a'; i <= 'z'; i++)
		if (cnt[i] % 2 == 1)	g++;
	for (int i = 'a'; i <= 'z'; i++){
		if (cnt[i] % 2 == 0)	continue;
		if (g >= 2){
			cnt[i]++;
			g -= 2;
		}
		else{
			if (g == 1){
				g = 0;
				continue;
			}
			cnt[i]--;
		}
	}

	string a = "", b = "";
	char ch;
	for (int i = 'a'; i <= 'z'; i++){
		int x = cnt[i]/2;
		string temp = "";
		temp += char(i);
		for (int i = 0; i < x; i++)	a += temp;
		if (cnt[i] % 2 == 1)	ch = i;
	}
	b = a;
	reverse(b.begin(), b.end());
	if (s.size() % 2 == 0){
		cout << a << b << endl;
		return 0;
	}
	cout << a << ch << b << endl;
    return 0;
}