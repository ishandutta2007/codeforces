#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int n , m;

void input(){
    cin >> n >> m;
    int mini = -1 , maxi = -1 , temp;    

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 if ( temp < mini || mini == -1 )	  mini = temp;
	 if ( temp > maxi || maxi == -1 )	  maxi = temp;

    }
    
    int mini2 = -1;
    for ( int i = 0 ; i < m ; i++ ){
	 cin >> temp;
	 if ( temp < mini2 || mini2 == -1 )  mini2 = temp;
    
    }
    if ( mini2 <= max(mini * 2 , maxi) )	cout << -1 << endl;
    else{
	 cout << max(mini * 2 , maxi) << endl;
    }

}

int main(){
    input();
    return 0;

}