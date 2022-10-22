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

int n , a = -1 , b = -1 , fl , ans;
string s , t;
vector<int> vec;
int c[200] , d[200] , mark[200][200];

int main(){
    cin >> n;
    cin >> s >> t;
    for (int i = 0 ; i < s.size() ; i++)
	 if (s[i] != t[i]){
	     vec.push_back(i);
	     mark[s[i]][t[i]] = i + 1;
	     c[s[i]] = i + 1;
	     d[t[i]] = i + 1;
	 }

    ans = vec.size();
    if (ans == 0 || ans == 1){
	 cout << ans << endl;
	 cout << -1 << " " << -1 << endl;
	 return 0;
    }

    for (int i = 'a' ; i <= 'z' ; i++){
	 for (int j = 'a' ; j <= 'z' ; j++){
	     if (mark[i][j] == 0)	 continue;
	     if (mark[j][i] == 0)	 continue;
	     ans -= 2;
	     a = mark[i][j];
	     b = mark[j][i];
	     break;
	 }
	 if (a != -1)	   break;
    }

    if (a != -1){
	 cout << ans << endl;
	 cout << a << " " << b << endl;
	 return 0;
    }

    for (int i = 'a' ; i <= 'z' ; i++){
	 if (c[i] == 0)  continue;
	 if (d[i] == 0)  continue;
	 a = c[i];
	 b = d[i];
	 ans -= 1;
	 break;
    }
    cout << ans << endl;
    cout << a << " " << b << endl;

    return 0;
}