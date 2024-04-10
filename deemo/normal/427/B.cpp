#include<iostream>

using namespace std;

int ans;
int n , t , c , temp , fl;

int main(){
    cin >> n >> t >> c;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 if ( temp <= t ){
	     fl++;
	     if ( i != n - 1 )   continue;
	 }
    
	 if ( fl >= c )  ans += fl - c + 1; 
	 fl = 0;
    }
    cout << ans << endl;
    return 0;	  
}