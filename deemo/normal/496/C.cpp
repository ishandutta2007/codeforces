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

int n , m;
string s[200];
int ans;
bool mark[400];

bool ok(int a , int b){
    string s1 = "" , s2 = "";
    for (int i = 0 ; i < m ; i++)
	 if (mark[i] == 0){
	     s1 += s[a][i];
	     s2 += s[b][i];
	 }
    return  s1 <= s2;
}

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
	 cin >> s[i];
    
    for (int i = 0 ; i < m ; i++){	 
	 bool fl = 0;
	 for (int j = 0 ; j < n - 1 ; j++){
	     if (s[j][i] <= s[j + 1][i]) continue;
	     if (ok(j , j + 1))  continue;
	     fl = 1;
	     mark[i] = 1;
	     break;
	 }
	 if (fl) ans++;
    }
    cout << ans << endl;

    return 0;
}