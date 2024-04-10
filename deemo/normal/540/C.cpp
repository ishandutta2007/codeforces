#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<iomanip>
#include<stack>
#include<cstdio>

using namespace std;

int flag , n , m , a , b , c , d;
const int max_n = 1100;
queue<pair<int , int>>  saf;
char arr[max_n][max_n];
int mark[max_n][max_n];


void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
	 for(int j = 0 ; j < m ; j++)
	     cin >> arr[i][j];
    cin >> a >> b;
    cin >> c >> d;
    a--;    b--;    c--;	d--;
}

void f(int y , int x){
    if (y >= n || y < 0 || x >= m || x < 0)	  return;
    
    if (mark[y][x] >= 2)	return;
    
    if (y == c && x == d)
	 if(arr[y][x] == 'X' && (a != c || b != d || mark[y][x] >= 1) ) flag = 1;

    if (mark[y][x] == 1)	return;
    mark[y][x] += 1;
    
    if(arr[y][x] == 'X' && y == a && x == b)    saf.push({y,x});
    if(arr[y][x] == 'X')	return;
    arr[y][x] = 'X';

    saf.push({y,x});
}

void bfs(){
    f(a , b);
    
    pair<int , int> fr;

    while(!saf.empty()){
	 fr = saf.front();
	 saf.pop();
	 
	 f(fr.first + 1 , fr.second);
	 f(fr.first - 1 , fr.second);
	 f(fr.first , fr.second - 1);
	 f(fr.first , fr.second + 1);
    }
}

int main(){
    input();	 
    bfs();
    if (flag == 1)  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}