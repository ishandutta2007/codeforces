#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<utility>
#include<map>
#include<stack>

using namespace std;

int m , t , r;
vector<int>	  w;
const int max_w = 310;
const int con = 310;
int jadval[max_w + 900 + con];

void input(){
    cin >> m >> t >> r;
    int a;
    for ( int i = 0 ; i < m ; i++ ){
	 cin >> a;  
	 w.push_back(a + con);
    }
}

bool check(){
    int fl = 0;
    for ( int i = 0 ; i < w.size() ; i++ )
	 if ( jadval[w[i]] < r )	 return false;
    return true;

}

int main(){
    input();
    for ( int i = 0 ; i < max_w + con ; i++ )
	 for ( int j = i + 1 ; j < i + 1 + t ; j++ )
	     jadval[j] += 1;
    
    if ( check() == false ){
	 cout << -1 << endl;
	 return 0;
    }

    int counter = max_w + con;
    for ( int i = 0 ; i < max_w + con ; i++ ){
	 for ( int j = i + 1 ; j < i + 1 + t ; j++ )
	     jadval[j] -= 1;
	 if ( check() )  counter -= 1;
	 else{
	     for ( int j = i + 1 ; j < i + 1 + t ; j++ )
		  jadval[j] += 1;
	 }
    }
    
    cout << counter << endl;
    return 0;

}