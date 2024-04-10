/*
    It's so unreal..
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

int n;
const int max_n = 400;
vector<int> ad_list[max_n] , leaves[max_n];
vector<int> order;
int mark[max_n] , ind = 0;
queue<int>  ans;

void init(int v){
    mark[v] = 1;
    if (ad_list[v].size() == 1 && v != 1){
	 leaves[v].pb(v);
	 return;
    }
    for (int i = 0 ; i < ad_list[v].size() ; i++){
	 if (mark[ad_list[v][i]])	 continue;
	 init(ad_list[v][i]);
	 for (int j = 0 ; j < leaves[ad_list[v][i]].size() ; j++)
	     leaves[v].pb(leaves[ad_list[v][i]][j]);
    }
}

void solve(int v){
    mark[v] = 2;
    ans.push(v);
    if (ad_list[v].size() == 1 && v != 1){
	 ind++;
	 return;
    }
    for (int i = 0 ; i < ad_list[v].size() ; i++){
	 int temp = ad_list[v][i];
	 if (mark[temp] == 2)    continue;
	 for (int j = 0 ; j < leaves[temp].size() ; j++)
	     if (leaves[temp][j] == order[ind] || ind >= order.size()){
		  solve(temp);
		  ans.push(v);
		  i = -1;
		  break;
	     }
    }	 
}

int main(){
    read_fast;
    {
	 cin >> n;
	 int a , b;
	 int t = n - 1;
	 while (t--){
	     cin >> a >> b;
	     ad_list[a].pb(b);
	     ad_list[b].pb(a);
	 }
	 t = 2;   
	 for (int i = 1 ; i <= n ; i++)
	     if (ad_list[i].size() > 2)  t += ad_list[i].size() - 2;

	 if (ad_list[1].size() == 1) t--;
	 while(t--){
	     cin >> a;
	     order.pb(a);
	 }   
    }
    init(1);	  
    solve(1);
    if (ans.size() != 2 * n - 1){
	 cout << -1 << endl;
	 return  0;
    }
    while (!ans.empty()){
	 cout << ans.front() << " ";
	 ans.pop();
    }
    cout << endl;
    return 0;
}