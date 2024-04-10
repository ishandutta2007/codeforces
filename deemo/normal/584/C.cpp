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
	string s1, s2, s3;
	read_fast;
	int n, t;	cin >> n >> t;
	cin >> s1 >> s2;
	int z = t;
	s3 = s1;
	int cnt = 0, temp = -1;
	for (int i = 0; i < n; i++)
		if (s1[i] == s2[i])	cnt++;

	if ((n - cnt) % 2 == 1){
		if (t == 0){
			cout << -1 << endl;
			return 0;
		}

		for (int i = 0; i < n; i++)
			if (s1[i] != s2[i]){
				s3[i] = 'a';
				while (s3[i] == s1[i] || s3[i] == s2[i])	s3[i]++;
				temp = i;
				break;
			}
		t--;
	}

	int f = 0;
	for (int i = 0; i < n && t; i++){
		if (i == temp)	continue;
		if (s1[i] == s2[i])	continue;
		if (f % 2 == 0)	s3[i] = s1[i];
		else	s3[i] = s2[i];
		if (f % 2 == 1)	t--;
		f++;
	}
	for (int i = 0; i < n && t; i++){
		if (i == temp)	continue;
		if (s1[i] == s2[i]){
			if (s1[i] == 'z')
				s3[i] = 'a';
			else	
				s3[i] = 'z';
			t--;
		}
	}
	f = 0;
	for (int i = 0; i < n && t; i++){
		if (i == temp)	continue;
		if (s1[i] == s2[i])	continue;
		
		s3[i] = 'a';
		while (s3[i] == s1[i] || s3[i] == s2[i])	s3[i]++;
		if (f % 2 == 1)	t--;
		f++;
	}

	cnt = 0, f = 0;
	for (int i = 0; i < n; i++){
		if (s3[i] != s1[i])	cnt++;
		if (s3[i] != s2[i])	f++;
	}

	if (f != cnt){
		cout << -1 << endl;
		return 0;
	}	

	if (cnt != z)
		cout << -1 << endl;
	else
		cout << s3 << endl;
	return 0;
}