#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int n;

int main(){
    cin >> n;
    if ( n == 1 || n == 2 ){
	 cout << 1 << endl;
	 cout << 1 << endl;
	 return 0;
    }
    if ( n == 3 ){
	 cout << 2 << endl;
	 cout << 1 << " " << 3 << endl;
	 return 0;
    }
    cout << n << endl;
    for ( int i = 2 ; i <= n ; i += 2 )
	 cout << i << " ";
    for ( int i = 1 ; i <= n ; i += 2 ){
	 if ( i == n || i == n - 1 )
	     cout << i << endl;
	 else	  cout << i << " ";
    }
    return 0;
}