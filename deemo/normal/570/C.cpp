/*
    God save us everyone 
    will we burn inside the fires of a thousand suns?
    for the sins of our hands 
    the sins of our tongues
    the sins of our fathers
    the sins of our young..
*/

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
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

int n , q , ans;
string s;

int main(){
    read_fast;
    cin >> n >> q;
    cin >> s;
    int x;
    char c;

    for (int i = 0 ; i < n - 1 ; i++)
	 if (s[i] == s[i + 1] && s[i] == '.')    ans++;

    for (int i = 0 ; i < q ; i++){
	 cin >> x >> c;
	 if (n == 1){
	     cout << 0 << endl;
	     continue;
	 }
	 x--;
	 if (c == '.'){
	     if (s[x] != '.'){
		  if (x == 0){
		      if (s[1] == '.')	 ans++;
		  }
		  else    if (x == n - 1){
		      if (s[x - 1] == '.')    ans++;
		  }
		  else{
		      if (s[x - 1] == '.' || s[x + 1] == '.') ans++;
		      if (s[x - 1] == '.' && s[x + 1] == '.') ans++;
		  }	 
	     } 
	 }
	 else{
	     if (s[x] == '.'){
		  if (x == 0){
		      if (s[1] == '.')	 ans--;
		  }
		  else    if (x == n - 1){
		      if (s[x - 1] == '.')    ans--;
		  }
		  else{
		      if (s[x - 1] == '.' || s[x + 1] == '.') ans--;
		      if (s[x - 1] == '.' && s[x + 1] == '.') ans--;
		  }
	     }
	 }
	 s[x] = c;
	 cout << ans << endl;
    }
    return 0;
}