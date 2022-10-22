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

int c[14] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 20};

int main(){
	string s, temp;
	int x;
	cin >> x >> temp >> s;	x--;
	int cur = 4, ans = 0, y = 0, m = 0;
	for (int i = 0; i < 366; i++){
		if (s == "week"){
			if (cur % 7 == x)	ans++;
		}
		else{
			if (y == x)	ans++;
		}
		cur = (cur + 1) % 7;
		y++;
		if (y == c[m]){
			m++;
			y = 0;
		}
	}
	cout << ans << endl;
    return 0;
}