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
	string s1, s2;
	cin >> s1 >> s2;
	cout << min(abs(s1[0] - s2[0]), abs(s1[1] - s2[1])) + abs(abs(s1[0] - s2[0]) - abs(s1[1] - s2[1])) << endl;
	if (s1[0] < s2[0] && s1[1] < s2[1])
		for (; s1[0] != s2[0] && s1[1] != s2[1]; s1[0]++, s1[1]++)
			cout << "RU" << endl;
	if (s1[0] < s2[0] && s1[1] > s2[1])
		for (; s1[0] != s2[0] && s1[1] != s2[1]; s1[0]++, s1[1]--)
			cout << "RD" << endl;
	if (s1[0] > s2[0] && s1[1] < s2[1])
		for (; s1[0] != s2[0] && s1[1] != s2[1]; s1[0]--, s1[1]++)
			cout << "LU" << endl;
	if (s1[0] > s2[0] && s1[1] > s2[1])
		for (; s1[0] != s2[0] && s1[1] != s2[1]; s1[0]--, s1[1]--)
			cout << "LD" << endl;
	for (;s1[0] < s2[0]; s1[0]++)
		cout << "R" << endl;
	for (; s1[0] > s2[0]; s1[0]--)
		cout << "L" << endl;
	for (; s1[1] < s2[1]; s1[1]++)
		cout << "U" << endl;
	for (; s1[1] > s2[1]; s1[1]--)
		cout << "D" << endl;
	return 0;
}