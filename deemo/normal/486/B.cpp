#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int n , m;
const int max_n = 100 + 10;
bool B[max_n][max_n];
bool A[max_n][max_n];
bool ms[max_n][max_n];
int counter , fg;

void input(){
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
	 for ( int j = 1 ; j <= m ; j++ ){
	     cin >> B[i][j];
	     if ( B[i][j] == 1 ) counter += 1;
	 }
}

bool is_bad(int y){
    for ( int i = 1 ; i <= m ; i++ )
	 if ( B[y][i] == 0 )	return	 true;
    return false;
}

bool is_good(int x){
    for ( int i = 1 ; i <= n ; i++ )
	 if ( B[i][x] == 0 )	return	 false;
    return true;
}

int c;

void mark(int y , int x){
    for ( int i = 1 ; i <= n ; i++ )
	 if ( ms[i][x] == 0 ){
	     ms[i][x] = 1;
	     c += 1;
	 }

    for ( int j = 1 ; j <= m ; j++ )
	 if ( ms[y][j] == 0 ){
	     ms[y][j] = 1;
	     c += 1;
	 }
}

void get_Ans(){
    for ( int i = 1 ; i <= n ; i++ ){
	 if ( is_bad(i) )	continue;
    
	 for ( int j = 1 ; j <= m ; j++ ){
	     if ( is_good(j) ){
		  A[i][j] = 1;
		  mark(i , j);
	     }
	 }
    }
    
}

void show_Ans(){
    if ( c != counter ){
	 cout << "NO" << endl;
	 return;
    }
    
    cout << "YES" << endl;
    for ( int i = 1 ; i <= n ; i++ ){
	 for ( int j = 1 ; j <= m ; j++ )
	     cout << A[i][j] << " ";
	 cout << endl;
    }
}

int main(){
    input();
    if ( counter != 0 ) get_Ans();
    show_Ans();
    return 0;
}