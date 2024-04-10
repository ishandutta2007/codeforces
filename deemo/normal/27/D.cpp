/*
    I found myself in Wonderland
    Get back on my feet again..
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
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

const int max_n = 100 + 50;

int n , m;
vector<pair<int, int>>  vec;
vector<int> adj[max_n];
bool flag , mark[max_n];
bool col[max_n];
bool jad[max_n][max_n];

    void dfs(int v , bool c){
    if (mark[v]){
	 if (c != col[v])	flag = 1;
	 return;
    }
    mark[v] = 1;
    col[v] = c;
    for (int i = 0 ; i < adj[v].size() ; i++)
	 dfs(adj[v][i] , !c);
}

int main(){
    read_fast;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
	 int a , b;
	 cin >> a >> b;  
	 a--;	  b--;
	 if (a > b)  swap(a , b);
	 vec.push_back({a , b});
    }
    for (int i = 0 ; i < m ; i++)
	 for (int j = 0 ; j < m ; j++){
	     if (i == j) continue;
	     int flag = 2;
	     if (vec[i].first == vec[j].first || vec[i].first == vec[j].second)  flag = 0;
	     if (vec[i].second == vec[j].first || vec[i].second == vec[j].second)	flag = 0;
	     for (int k = vec[i].first + 1 ; flag != 0 && k < vec[i].second ; k++){
		  if (k == vec[j].first || k == vec[j].second)	 flag--;
	     }
	     if (flag == 1)   adj[i].pb(j);
	 }
    for (int i = 0 ; i < m ; i++)
	 if (!mark[i])   dfs(i , 0);
    if (flag){
	 cout << "Impossible" << endl;
	 return  0;
    }	 
    for (int i = 0 ; i < m ; i++){
	 if (col[i] == 0)	cout << 'i';
	 else	  cout << 'o';
    }	 
    cout << endl;
    return 0;
}