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
    int k;
    cin >> k;
    if (s.size() % k != 0){
	 cout << "NO" << endl;
	 return 0;
    }
    bool fl = 0; 
    int i = s.size() / k;
    for (int j = 0 ; j < s.size() / i ; j++){
	 int b = j * i , a = (j + 1) * i - 1;
	 for (int k = 0 ; k <= i/2 ; k++){
	     if (s[b + k] != s[a - k])	  fl = 1;
	     if (fl == 1)    break;

	 }
	 if (fl == 1)	break;
    }
    if (fl == 0){
	 cout << "YES" << endl;
	 return 0;
    }
    cout << "NO" << endl;
    return 0;
}