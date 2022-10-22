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

    for (int i = 0 ; i < s.size() ; i++){
	 if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
	     cout << "YES" << endl;
	     return 0;
	 }
    }    
    cout << "NO" << endl;

    return 0;
}