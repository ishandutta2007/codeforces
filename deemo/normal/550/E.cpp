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

using namespace std;

const int max_n = 2 * 1e5 + 100;
char c[max_n];
int n;
vector<char>	  s;

int main(){
    cin >> n;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 scanf("%d" , &temp);
	 c[i] = char(temp + 48);
    }
    if (c[n - 1] == '1'){
	 cout << "NO" << endl;
	 return 0;
    }

    if (n == 2){
	 if (c[0] == '0'){
	     cout << "NO" << endl;
	     return 0;
	 }
    }

    int ans = int(c[0]) - 48;
    int d = 0;

    while (ans != 0 && d < n){
	 s.push_back(c[d]);
	 s.push_back('-');
	 s.push_back('>');
	 if (ans == 1 && c[d + 1] == '0') ans = 0;
	 else	  ans = 1;
	 d++;
    }	
    if (d == n - 2){
	 cout << "NO" << endl;
	 return  0;
    }	  
    if (d < n - 1){
	 if (d != 0){
	     s.push_back(c[d]);
	     s.push_back('-');
	     s.push_back('>');
	 }
	 if (d != 0) d++;
	 if (d == 0){
	     s.push_back('0');
	     s.push_back('-');
	     s.push_back('>');
	     d++;
	 }
	 if (d != n - 1){
	     s.push_back('(');
	     int tans = int(c[d]) - 48;
	     for (d ; d < n - 2 ; d++){
		  s.push_back(c[d]);
		  s.push_back('-');
		  s.push_back('>');
		  if (tans == 1 && c[d + 1] == '0') tans = 0;
		  else	  tans = 1;
	     }
	     s.push_back(c[n - 2]);
	     s.push_back(')');
	     s.push_back('-');
	     s.push_back('>');
	 }
    }
    s.push_back(c[n - 1]);
    if (ans == 0){
	 cout << "YES" << endl;
	 for (int i = 0 ; i < s.size() ; i++)
	     cout << s[i];
	 cout << endl;
    }
    else    cout << "NO" << endl;

    return 0;
}