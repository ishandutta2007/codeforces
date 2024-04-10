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

int a , b;
string s;

int main(){
    cin >> a >> b;
    if (2 * a + 2 < b){
	 cout << -1 << endl;
	 return 0;
    }
    if (a > b + 1){
	 cout << -1 << endl;
	 return 0;
    }
    string s = "";
    while (a < b && a > 0){
	 s += "110";
	 a -= 1;
	 b -= 2;
    }
    if (b == a){
	 for (int i = 0 ; i < a ; i++)
	     s += "10";
	 a = b = 0;
    }	 
    if (a > b){
	 string temp = "";
	 for (int i = 0 ; i < b ; i++)
	     temp += "01";
	 temp += '0';
	 s = temp + s;
	 a -= b;
	 b = 0;
    }
    if (b > 0)  for (int i = 0 ; i < b ; i++)   s+='1';
    cout << s << endl;
    return 0;
}