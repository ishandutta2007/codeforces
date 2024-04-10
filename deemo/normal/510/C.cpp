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
#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

int n , g = 0;
string s1 , s2;
const int max_n = 200;
vector<char>	  vec[max_n];
bool flag = 0 , mark[max_n] , s_t[max_n] , f_t[max_n];
stack<char> mystack;

void find_first_dif(){
    for (int i = 0 ; i < min(size(s1) , size(s2)) ; i++)
	 if (s1[i] != s2[i]){
	     vec[s1[i]].push_back(s2[i]);
	     return;
	 }
    if (size(s1) > size(s2))    flag = 1;
}

void dfs(char v){
    g++;
    if (mark[v]){
	 if(f_t[v] == 0)  flag = 1;
	 return;
    }
    s_t[v] = g;
    mark[v] = 1;
    for (int i = 0 ; i < size(vec[v]) ; i++)
	 dfs(vec[v][i]);
    mystack.push(v);
    f_t[v] = g;
}

void run_dfs(){
    for (char c = 'z' ; c >= 'a' ; c--){
	 if (mark[c])	   continue;
	 dfs(c);
    }
}

int main(){
    read_fast;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 if (i == 0){
	     cin >> s1;
	     continue;
	 }
	 cin >> s2;
	 find_first_dif();
	 swap(s1 , s2);
    }
    if (flag){
	 cout << "Impossible" << endl;
	 return  0;
    }
    run_dfs();
    if (flag)	  cout << "Impossible" << endl;
    else{
	 while (!mystack.empty()){
	     cout << mystack.top();
	     mystack.pop();	     
	 }
	 cout << endl;
    }
    return 0;
}