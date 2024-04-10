#include<iostream>

using namespace std;

int n , ans , temp , p , c;

int main(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 if ( temp == -1 )	c++;
	 else	  p += temp;
	 if ( temp == -1 ){
	     if ( p > 0 ){
		  c--;
		  p--;
	     }
	     else{
		  ans++;
		  c--;
	     }
	 }
    }
    cout << ans << endl;
    return 0;
}