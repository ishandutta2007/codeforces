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

char c[10][10];

int main(){
	int a = 1e9, b = 1e9;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> c[i][j];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){
			if (c[i][j] == '.')	continue;
			if (c[i][j] == 'W'){
				int t = 0;
				for (int k = i; k; k--){
					if (c[k - 1][j] == 'B'){
						t = 1e9;
						break;
					}
					t++;
				}
				a = min(a, t);
			}
			if (c[i][j] == 'B'){
				int t = 0;
				for (int k = i; k <7; k++){
					if (c[k + 1][j] == 'W'){
						t = 1e9;
						break;
					}	
					t++;
				}
				b = min(b, t);
			}
		}
	if (a <= b)	cout << "A" << endl;
	else	cout << "B" << endl;
    return 0;
}