#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define Pair pair<int, int>
using namespace std;
string s;
map<char, int>m;
int main(){
	getline(cin, s);
	for (int i=0; i<s.size(); i++)
	    if (isalpha(s[i]))
	        m[s[i]]++;
	cout << m.size();
}