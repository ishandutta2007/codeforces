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

const int max_n = 1e5 + 10;
const int max_m = 10 + 5;
const int SQRT = 350;

int n , m , q;
char table[max_n][max_m];
pair<int , int> res[max_n][max_m];
bool mark[max_n][max_m];
int cnt[max_n][max_m] , g;

pair<int , int> dfs(int y , int x , int par_y , int par_x , int col){
    if (y < 0 || x < 0 || x >= m)	 return  {y , x};
    if (y / SQRT != col)  return  {y , x};
    if (mark[y][x]) return	res[y][x];
    mark[y][x] = 1;

    int yy = y , xx = x;
    if (table[y][x] == '^')	yy--;
    if (table[y][x] == '>')	xx++;
    if (table[y][x] == '<')	xx--;
    
    if (yy == par_y && xx == par_x) return  res[y][x] = {-2 , -2};
    return  res[y][x] = dfs(yy , xx , y , x , col);
}

void init(){
    for (int p = 0 ; p < n ; p += SQRT)
	     for (int i = p ; i < p + SQRT && i < n ; i++)
		  for (int j = 0 ; j < m ; j++)
		      res[i][j] = dfs(i , j , i , j , i / SQRT);
}

void update(int y , int x , char ch){
    int b = y / SQRT;
    table[y][x] = ch;
    for (int i = b * SQRT ; i < (b + 1) * SQRT && i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     mark[i][j] = 0;

    for (int i = b * SQRT ; i < (b + 1) * SQRT && i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     res[i][j] = dfs(i , j , i , j , b);
}

pair<int , int> get(int y , int x){
    g++;
    while (0 <= y && y < n && 0 <= x && x < m){
	 if (cnt[y][x] == g)	return	 {-2 , -2};
	 cnt[y][x] = g;
	 int t = y;
	 y = res[y][x].first;
	 x = res[t][x].second;
    }
    return  {y , x};
}

int main(){
    read_fast;
    cin >> n >> m >> q;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++)
	     cin >> table[i][j];
    init();
    while (q--){
	 char type;  int y, x;  cin >> type >> y >> x;	y--, x--;
	 if (type == 'A'){
	     pair<int , int>	temp = get(y , x);
	     temp.first++;	temp.second++;
	     cout << temp.first << " " << temp.second << endl;
	 }
	 else{
	     char ch;	   cin >> ch;
	     update(y , x , ch);
	 }
    }
    return 0;
}