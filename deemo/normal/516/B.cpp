#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

int n , m , counter;
const int max_n = 2000 + 10;
short jadval[max_n][max_n];
int ans[max_n][max_n];
bool fl[max_n][max_n];

void input(){
    cin >> n >> m;
    char ch;

    for ( int i = 1 ; i <= n ; i++ )
	 for ( int j = 1 ; j <= m ; j++ ){
	     scanf("%1s" , &ch);
	     if ( ch == '.' ){
		  jadval[i][j] = 1;//1 -> .
		  counter += 1;
	     }
	     else    jadval[i][j] = 9;//9 -> *
	 }
	     
}

bool check(){
    if ( counter % 2 != 0 )	return true;
    return false;
}

int flag , mark = 1;
queue< pair<int , int> >	saf;

bool is_bad(int y , int x){
    if ( jadval[y + 1][x] == 1 )	 return false;
    if ( jadval[y - 1][x] == 1 )	 return false;
    if ( jadval[y][x + 1] == 1 )	 return false;
    if ( jadval[y][x - 1] == 1 )	 return false;
    return true;
}

bool is_unique(int y , int x){
    int c = 0;
    if ( jadval[y + 1][x] == 1 )	 c += 1;
    if ( jadval[y - 1][x] == 1 )	 c += 1;
    if ( jadval[y][x + 1] == 1 )	 c += 1;
    if ( jadval[y][x - 1] == 1 )	 c += 1;
    return c == 1;
}

void init(){
    for ( int i = 1 ; i <= n ; i++ )
	 for ( int j = 1 ; j <= m ; j++ ){
	     if ( jadval[i][j] == 9 )    continue;

	     if ( is_bad(i , j) ){
		  flag = 1;
		  return;
	     }

	     if ( is_unique(i , j) ){
		  saf.push( make_pair(i , j) );
		  fl[i][j] = 1;
	     }
	 }
}

void put_tile(int y , int x){
    ans[y][x] = mark;
    if ( jadval[y + 1][x] == 1 ){
    	 ans[y + 1][x] = mark;
	 jadval[y + 1][x] = 2;
    }

    if ( jadval[y - 1][x] == 1 ){
	 ans[y - 1][x] = mark;
	 jadval[y - 1][x] = 2;
    }

    if ( jadval[y][x + 1] == 1 ){
	 ans[y][x + 1] = mark;
	 jadval[y][x + 1] = 2;
    }	     

    if ( jadval[y][x - 1] == 1 ){
	 ans[y][x - 1] = mark;
	 jadval[y][x - 1] = 2;
    }
    mark += 1;
    counter -= 2;
}

void update(int y , int x){
    for ( int i = y - 2 ; i <= y + 2 ; i++ ){
	 if ( i < 1 && i > n )   continue;

	 for ( int j = x - 2 ; j <= x + 2 ; j++ ){
	     if ( j < 1 && j > m )	 continue;
	     if ( jadval[i][j] != 1 )    continue;
	     if ( fl[i][j] != 0 )	 continue;

	     if ( is_unique(i , j) )     {
		  saf.push(make_pair(i , j));
		  fl[i][j] = 1;
	     }
	 }
    }
}

void get_Ans(){
    init();
    if ( flag == 1 )	   return;
    
    int y , x;
    pair<int , int> fr;
    while ( !saf.empty() ){
	 fr = saf.front();
	 y = fr.first;
	 x = fr.second;

	 if ( jadval[y][x] == 2 ){
	     saf.pop();    
	    continue;
	 }

	 if ( is_bad(y , x) ){
	     flag = 1;
	     return;
	 }
    
	 put_tile(y , x);
	 saf.pop();
	 update(y , x);
    }
    if ( counter != 0 ) flag = 1;
}

char d[max_n][max_n];

pair<int , int> find_pair(int y , int x){
    int temp = ans[y][x];
    if ( ans[y + 1][x] == temp )	 return  make_pair(y + 1 , x);
    if ( ans[y - 1][x] == temp )	 return  make_pair(y - 1 , x);
    if ( ans[y][x + 1] == temp )	 return  make_pair(y , x + 1);
    if ( ans[y][x - 1] == temp )	 return  make_pair(y , x - 1);
    return make_pair(-1 , -1);
}

void deal_with(pair<int , int>  a , pair<int , int> b){
    if ( a.first != b.first ){
	 if ( a.first < b.first ){
	     d[a.first][a.second] = '^';
	     d[b.first][b.second] = 'v';
	 }
	 else{
	     d[a.first][a.second] = 'v';
	     d[b.first][b.second] = '^';
	 }
    }
    else{
	 if ( a.second < b.second ){
	     d[a.first][a.second] = '<';
	     d[b.first][b.second] = '>';
	 }
	 else{
	     d[a.first][a.second] = '>';
	     d[b.first][b.second] = '<';
	 }
    }
    jadval[a.first][a.second] = 3;
    jadval[b.first][b.second] = 3;
    
}

void init_ans(){
    pair<int , int> temp;
    for (int i = 1 ; i <= n ; i++ )
	 for ( int j = 1 ; j <= m ; j++ ){
	     if ( jadval[i][j] == 9 ){
		  d[i][j] = '*';
		  continue;
	     }
	 
	     if ( jadval[i][j] == 3 )    continue;	 

	     temp = find_pair(i , j);
	     deal_with(make_pair(i , j) , temp);
	 }
}

void show_Ans(){
    if ( flag == 1 ){
	 cout << "Not unique" << endl;
	 return;
    }
    
    init_ans();
    for ( int i = 1 ; i <= n ; i++ ){
	 for ( int j = 1 ; j <= m ; j++ )
	     printf("%c" , d[i][j]);
	 printf("\n");
    }   
}

int main(){
    input();
    if ( check() ){
	 cout << "Not unique" << endl;
	 return 0;
    }
    get_Ans();
    show_Ans();
    return 0;
}