/*
    My tea's gone cold, I'm wondering why I got out of bed at all
    the morning rain clouds up my window and I can't see at all
    and even if I could it'll all be gray but your picture on my wall
    it reminds me that it's not so bad, it's not so bad..
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
set<int>    st;
map<int , vector<int>>  mp;
vector<int> sec;

void show(int v , int par){
    if (v == sec[0]){
	 cout << v << " ";
	 return;
    }
    for (int i = 0 ; i < mp[v].size() ; i++){
	 if (mp[v][i] == par)    continue;
	 show(mp[v][i] , v);
    }
    cout << v << " ";
}

int main(){
    {
	 cin >> n;
	 int a , b;  
	 for (int i = 0 ; i < n ; i++){
	     cin >> a >> b;
	     st.insert(a);
	     st.insert(b);
	     mp[a].pb(b);
	     mp[b].pb(a);
	 }
    }
    for (auto i:st)
	 if (mp[i].size() == 1)  sec.pb(i);
    show(sec[1] , -1);
    cout << endl;
    return 0;
}