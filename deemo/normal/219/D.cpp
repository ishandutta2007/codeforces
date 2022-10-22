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

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

int n;
const int max_n = 3e5;
vector<int> vec[2][max_n];
bool mark[max_n];
int d[max_n];

void dfs(int v , bool type){
    if (mark[v])    return;
    mark[v] = 1;
    for (int i = 0 ; i < vec[0][v].size() ; i++){
	 if (type){
	     if (mark[vec[0][v][i]]) continue;
	     d[vec[0][v][i]] = d[v] + 1;
	 }
	 dfs(vec[0][v][i] , type);
    }
    for (int i = 0 ; i < vec[1][v].size() ; i++){
	 if (mark[vec[1][v][i]]) continue;
	 if (!type)  d[0]++;
	 else	  d[vec[1][v][i]] = d[v] - 1;
	 dfs(vec[1][v][i] , type);
    }
}

int main(){
    read_fast;
    cin >> n;
    int a , b;
    for (int i = 0 ; i < n - 1 ; i++){
	 cin >> a >> b;
	 a--;	  b--;
	 vec[0][a].pb(b);
	 vec[1][b].pb(a);
    }
    dfs(0 , 0);
    for (int i = 0 ; i < n ; i++)
	 mark[i] = 0;
    dfs(0 , 1);
    int t = *min_element(d , d + n);
    cout << t << endl;
    for (int i = 0 ; i < n ; i++)
	 if (d[i] == t)  cout << i + 1 << " ";
    cout << endl;
    return 0;
}