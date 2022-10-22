#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<cstdio>
#include<iomanip>

using namespace std;

typedef long long ll;

ll n;
const ll max_n = 500;
vector<pair<ll , ll>> vec;
vector<pair<ll , ll>> sec;
vector<pair<ll , ll>> ans;
char jadval[max_n][max_n];
char gh[max_n][max_n];
ll c , counter;
bool mark[max_n][max_n];
vector<pair<ll , ll>> p;

void input(){
    cin >> n;
    for (ll i = 0 ; i < n ; i++)
	 for (ll j = 0 ; j < n ; j++){
	     cin >> jadval[i][j];
	     if (jadval[i][j] == 'o')
		  vec.push_back({i , j});
	     if (jadval[i][j] == 'x')   
		  c++; 
	 }
    if (n == 0) cout << "NO" << endl;
    //if (n == 50) 
//	 while(1){
//	     c++;
//	 }
}

void generate(){
    for (ll i = -1 * n + 1 ; i < n ; i++)
	 for (ll j = -1 * n + 1 ; j < n ; j++){
	     if (i == j && j == 0)	 continue;
	     sec.push_back({i , j});
	 }
}

void check(){
    ll a , b , flag , cnt;
    for (ll z = 0 ; z < sec.size() ; z++){
	 a = sec[z].first;
	 b = sec[z].second;
	 flag = 0;    
	 p.clear();

	 for (ll i = 0 ; i < vec.size() ; i++){
	     ll y = vec[i].first;
	     ll x = vec[i].second;

	     if (y + a >= n || y + a < 0)	  continue;
	     if (x + b >= n || x + b < 0)	  continue;
	     if (mark[y + a][x + b] == 0 && jadval[y + a][x + b] == 'x')
		      p.push_back({y + a , x + b});

	     if (jadval[y + a][x + b] != '.')    continue;
	     flag = 1;
	     break;
	     
	 }	 
	 if (flag == 0){
	     ans.push_back(sec[z]);
	     counter += p.size();

	     for (ll i = 0 ; i < p.size() ; i++)
		  mark[p[i].first][p[i].second] = 1;
	 }

    }
}

void show_Ans(){
    if (counter != c){
	 cout << "NO" << endl;
	 return;
    }

    cout << "YES" << endl;
    ll addx , addy;
    for(ll i = 0 ; i < ans.size() ; i++){
	 addy = ans[i].first;
	 addx = ans[i].second;
	 
	 gh[n - 1 + addy][n - 1 + addx] = 1;
    }

    for (ll i = 0 ; i < 2 * n - 1 ; i++){ 
	 for (ll j = 0 ; j < 2 * n - 1 ; j++){
	     if (i == j && j == n - 1)   cout << 'o';
	     else if(gh[i][j] == 1)	 cout << 'x'; 
	     else cout << '.';
	 }
	 cout << endl;
    }
}

int main(){
    input();
    generate();
    check();
    show_Ans();
    return 0;
}