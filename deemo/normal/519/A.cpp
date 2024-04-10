#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

int t1 , t2;

int main(){
    char c;

    for (int i = 0 ; i < 8 ; i++ )
	 for ( int j = 0 ; j < 8 ; j++ ){
	     cin >> c;

	     if ( c >= 65 && c <= 90 ){
		  if ( c == 'Q' ) t1 += 9;//white
		  if ( c == 'R' ) t1 += 5;
		  if ( c == 'B' ) t1 += 3;
		  if ( c == 'N' ) t1 += 3;
		  if ( c == 'P' ) t1 += 1;

	     }
	     if ( c >= 97 && c <= 122 ){
		  if ( c == 'q' ) t2 += 9;
		  if ( c == 'r' ) t2 += 5;//black
		  if ( c == 'b' ) t2 += 3;
		  if ( c == 'n' ) t2 += 3;
		  if ( c == 'p' ) t2 += 1;
	     }
	 }

    if ( t1 == t2 ) cout << "Draw" << endl;
    if ( t1 > t2 )  cout << "White" << endl;
    if ( t1 < t2 )  cout << "Black" << endl;
    return 0;
}