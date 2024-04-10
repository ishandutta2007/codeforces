#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>

using namespace std;

int n , m;
const int max_n = 20 + 5;
vector< pair<int , int> >	vec[max_n][max_n];

void input(){
    cin >> n >> m;
    char c;    

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> c;
	 if ( c == '>' )
	     for ( int j = 0 ; j < m - 1 ; j++ )
		  vec[i][j].push_back(make_pair(i , j + 1));
	 else
	     for ( int j = m - 1 ; j > 0 ; j-- )
		  vec[i][j].push_back(make_pair(i , j - 1));
    }
    
    for ( int j = 0 ; j < m ; j++ ){
	 cin >> c;
	 if ( c == 'v' )
	     for ( int i = 0 ; i < n - 1 ; i++ )
		  vec[i][j].push_back(make_pair(i + 1 , j));
	 else
	     for ( int i = n - 1 ; i > 0 ; i-- )
		  vec[i][j].push_back(make_pair(i - 1 , j));
    }	 
}

bool mark[max_n][max_n];
int counter;

void clear_Mark(){
    for ( int i = 0 ; i < n ; i++ )
	 for ( int j = 0 ; j < m ; j++ )
	     mark[i][j] = 0;
}

void dfs(int y , int x){
    mark[y][x] = 1;
    counter += 1;
    
    pair<int , int> temp;
    for ( int i = 0 ; i < vec[y][x].size() ; i++ ){
	 temp = vec[y][x][i];
	 if ( mark[temp.first][temp.second] == 0 )
	     dfs(temp.first , temp.second);
    }
}

int flag;

void get_Ans(){
    for ( int i = 0 ; i < n ; i++ ){
	 for ( int j = 0 ; j < m ; j++ ){
	     clear_Mark();
	     counter = 0;
	     dfs(i , j);
	     if ( counter != n * m ){
		  flag = 1;
		  return;
	     }
	 }
    }
}

int main(){
    input();
    get_Ans();
    if ( flag == 0 )	   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
    
}