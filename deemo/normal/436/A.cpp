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

int n , x;
const int max_n = 2000 + 20;
int t[max_n];
int h[max_n];
int m[max_n];
int g;
short mark[max_n];

void input(){
    cin >> n >> x;
    for ( int i = 0 ; i < n ; i++ )
	 cin >> t[i] >> h[i] >> m[i];
}

int get(int p){
    int ret = 0 , maxi , ind;
    
    for ( int i = 0 ; i < n ; i++ ){
	 maxi = -1;
    
	 for ( int j = 0 ; j < n ; j++ ){
	     if ( t[j] != p )    continue;
	     if ( h[j] > x )	    continue;
	     if ( mark[j] == g ) continue;
	     
	     if ( m[j] > maxi || maxi == -1 ){
		  maxi = m[j];
		  ind = j;
	     }
	 }
	 if ( maxi == -1 )	return	 ret;
    
	 mark[ind] = g;
	 ret += 1;
	 x += maxi;
	 if ( p == 0 )   p = 1;
	 else	  p = 0;
    }
    return ret;
}

int main(){
    input();
    int ans1 , ans2;
    int temp = x;
    g = 1;
    ans1 = get(0);

    x = temp;
    g = 2;
    ans2 = get(1);

    cout << max(ans1 , ans2) << endl;
    return 0;
}