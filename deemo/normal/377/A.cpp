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

using namespace std;

int n , m , k;
vector<pair<int , int>> sec[500 * 500 + 10];
queue<pair<int , int>>	   saf;
vector<pair<int , int>> ans;
char arr[510][510];
bool mark[510][510];
int maxi;
pair<int , int> p;

void input(){
    cin >> n >> m >> k;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < m ; j++){
	     cin >> arr[i][j];
	     if (arr[i][j] == '.')	 p = {i,j};
	 }
}

void check(int y , int x , int counter){
    if (y < 0 || y >= n || x < 0 || x >= m) return;
    if (arr[y][x] == '#')	return;
    if (mark[y][x] == 1)	return;
    mark[y][x] = 1;
    saf.push({y , x});
    sec[counter].push_back({y , x});
    maxi = counter;
}

void bfs(){
    saf.push(p);
    mark[p.first][p.second] = 1;
    sec[0].push_back(p);

    int counter = 0 , size;
    pair<int , int>  fr;
    while(!saf.empty()){
	 size = saf.size();
	 counter += 1;
	 for (int i = 0 ;i < size ; i++){
	     fr = saf.front();
	     saf.pop();
	 
	     check(fr.first + 1 , fr.second , counter);
	     check(fr.first - 1 , fr.second , counter);
	     check(fr.first , fr.second + 1 , counter);
	     check(fr.first , fr.second - 1 , counter);	 
    
	 }
    }

}

void get(){
    int i = 0;
    while (i < k){
	 while (!sec[maxi].empty() && i < k){
	     ans.push_back(sec[maxi].back());
	     sec[maxi].pop_back();
	     i++;
	 }
	 maxi--;
    }

    for (int i = 0 ; i < ans.size() ; i++)
	 arr[ans[i].first][ans[i].second] = 'X';

    for (int i = 0 ; i < n ; i++){
	 for (int j = 0 ; j < m ; j++)
	     cout << arr[i][j];
	 cout << endl;
    }
}

int main(){
    input();
    bfs();
    get();
    return 0;
}