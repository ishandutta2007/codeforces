#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<utility>

using namespace std;

int n , t;
const int max_n = 2000 + 40;
double p;
double pr[max_n][2];
int mark[max_n];

void input(){
    cin >> n >> p >> t;
}

int first = 0 , second = 1;

void clear(int j){
    for ( int i = 0 ; i <= n ; i++ )
	 pr[i][j] = 0;
}

void get_Ans(){
    mark[0] = 2;
    pr[0][first] = 1;
    for ( int i = 0 ; i < t ; i++){
	 for ( int j = 0 ; j <= n ; j++ ){
	     if ( mark[j] == 1 ){
		  mark[j] = 2;
		  continue;
	     }
	     
	     if ( mark[j] == 0 ) continue;

	     if ( j + 1 > n ){
		  pr[j][second] += pr[j][first];
		  continue;
	     }

	     mark[j + 1] += 1;
	     pr[j + 1][second] += pr[j][first] * p;
	     pr[j][second] += pr[j][first] * (1 - p);
	 }

	 if ( i % 2 == 0 )	first = 1;
	 else	  first = 0;
	 if ( i % 2 == 0 )	second = 0;
	 else	  second = 1;
	 clear(second);
    }
}

long double ans;

void show_Ans(){
    for ( int i = 0 ; i <= n ; i++ ){
	 if ( mark[i] == 0 )	continue;
	 ans += pr[i][first] * i;
    }
    cout << ans << endl;
}

int main(){
    cout << fixed << setprecision(6);
    input();
    get_Ans();
    show_Ans();
    return 0;
}