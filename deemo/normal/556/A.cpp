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

int n , t1 , t2;
string s;

int main(){
    cin >> n;
    cin >> s;
    for (int i = 0 ; i < s.size() ; i++){
	 if (s[i] == '1')	t1++;
	 else	  t2++;
    }
    cout << abs(t1 - t2) << endl;
    return 0;
}