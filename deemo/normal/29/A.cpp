/*
    All systems go, sun hasn't died
    deep in my bones, straight from inside..
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

vector<pair<int , int>> vec;

int main(){
    int n;
    {
	 cin >> n;
	 int a , b;
	 for (int i = 0 ; i < n ; i++){
	     cin >> a >> b;
	     vec.pb({a , b});
	 }
    }
    bool flag = 0;
    for (int i = 0 ; i < n ; i++)
	 for (int j = i + 1 ; j < n ; j++){
	     if (vec[i].first + vec[i].second == vec[j].first)
		  if (vec[i].first == vec[j].first + vec[j].second)   flag = 1;
	 }
    if (flag)	  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}