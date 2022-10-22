#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<utility>

using namespace std;

int n , flag;
char jadval[300];

int main(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
	 cin >> jadval[i];

    flag = 1;
    for ( int i = 1 ; i < n ; i++ ){
	 flag = 0;
	 for ( int j = 0 ; j < n ; j++ ){
	     flag = 0;
	     for ( int k = 0 ; k <= 4 ; k++ )
		  if ( jadval[j + k * i] == '.' || j + k * i >= n ) flag = 1;
	     if ( flag == 0 )    break;
	 }
	 if ( flag == 0 )	break;
    }

    if ( flag == 0 )	   cout << "yes" << endl;
    else    cout << "no" << endl;
    

    return 0;
}