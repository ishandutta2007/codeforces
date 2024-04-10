#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

int n , m , k;
const int max_n = 2000 + 20;
char jadval[max_n][max_n];
vector<int> answers;

void input(){
    cin >> n >> m >> k;
    for ( int i = 0 ; i < n ; i++ )
	 for ( int j = 0 ; j < m ; j++ )
	     cin >> jadval[i][j];
}

int cal(int x){
    int y = 1 , ret = 0;
    for ( int i = 1 ; i < n ; i++ ){
	 if ( x - i >= 0 )
	     if ( jadval[y][x - i] == 'R' )  ret += 1;
	 if ( x + i < m )
	     if ( jadval[y][x + i] == 'L' )  ret += 1;
	 if ( y + i < n )	
	     if ( jadval[y + i][x] == 'U' )  ret += 1;
	 y += 1;
    }
    return ret;
}

void get_Ans(){
    int ans;
    for ( int i = 0 ; i < m ; i++ ){
	 ans = cal(i);
	 answers.push_back(ans);
    }
}

void show_Ans(){
    for ( int i = 0 ; i < answers.size() - 1 ; i++ )
	 cout << answers[i] << " ";
    cout << answers[answers.size() - 1] << endl;
}   

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;
}