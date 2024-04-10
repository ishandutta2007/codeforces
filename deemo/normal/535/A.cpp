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

int main(){
    string s;
    cin >> s;
    string a[21] = {"zero" , "one" , "two" , "three","four","five","six","seven","eight","nine","ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen" , "twenty"};
    string b[10] = {"casd" , "ds" , "twenty" , "thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if (s.size() == 1){
	 cout << a[s[0] - 48] << endl;
	 return 0;
    }
    if (s[0] < '2'){
	 cout << a[s[1] - 48 + 10] << endl;
	 return 0;
    }
    if (s[1] == '0'){
	 cout << b[s[0] - 48] << endl;
	 return 0;
    }	 
    cout << b[s[0] - 48] << "-" << a[s[1] - 48] << endl;
    return 0;
}