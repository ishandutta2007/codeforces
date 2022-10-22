#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iomanip>

using namespace std;

int n , m , bn , gn;
int b[200];
int g[200];

void input(){
    cin >> n >> m;
    cin >> bn;
    int temp;

    for ( int i = 0 ; i < bn ; i++ ){
	 cin >> temp;
	 b[temp] = 1;
    }
    
    cin >> gn;
    for ( int i = 0 ; i < gn ; i++ ){
	 cin >> temp;
	 g[temp] = 1;
    }
}

int ans;

void get_Ans(){
    ans = gn + bn;
    int aa , bb;
    for ( int i = 0 ; i < 1000 * 1000 * 25 ; i++ ){
	 aa = i % n;
	 bb = i % m;
	 if ( b[aa] == 1 && g[bb] == 0 ){
	     g[bb] = 1;
	     ans += 1;
	 }
	 if ( g[bb] == 1 && b[aa] == 0 ){
	     b[aa] = 1;
	     ans += 1;
	 }	  
	 if ( ans == n + m )	return;
    }
}

int main(){
    input();
    get_Ans();
    if ( ans == n + m ) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}