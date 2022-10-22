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
    
string s;

int main(){
    cin >> s;
    string p = "hello";
    int j = 0;
    for (int i = 0 ; i < s.size() ; i++){
	 if (p[j] == s[i])	j++;
	 if (j >= p.size())	break;
    }	 
    if (j >= p.size())  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}