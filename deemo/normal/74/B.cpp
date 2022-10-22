#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 50 + 10;
const int MXTM = 200 + 10;

int n, a, b;
int dir;
string s;

int main(){
	cin >> n >> b >> a;	a--, b--;
	{
		string temp;	cin >> temp;	cin >> temp;
		if (temp == "head")	dir = -1;	//left
		else	dir = 1;	//right
	}
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		char ch = s[i];
		if (ch == '1'){
			a += dir;
			if (a == n - 1 || a == 0)	dir = 0 - dir;
			
			if (dir == -1){
				if (a != n - 1)
					b = n - 1;
				else
					b = 0;
			}
			else{
				if (a != 0)
					b = 0;
				else
					b = n - 1;
			}		
		}
		else{
			if (b < a)	b = max(0, b - 1);
			else	b = min(n - 1, b + 1);

			a += dir;
			if (a == n - 1 || a == 0)	dir = 0 - dir;
			if (a == b){
				cout << "Controller " << i + 1 << endl;
				return 0;
			}
		}
	}
	cout << "Stowaway\n";
	return 0;
}