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

int n , m;
int ans;

void get(int &maxi , int &mini){
    while ( maxi > mini ){
	 if ( mini <= 0 || (maxi <= 1 ) )	return;
	 
	 ans += 1;
	 mini -= 1;
	 maxi -= 2;
    }
}   

int main(){
    cin >> n >> m;

    if ( n > m )    get(n , m);
    else    if ( m > n )    get(m , n);

    while ( n > 0 && m > 0 && ( n > 1 || m > 1 ) ){
	 if ( n >= m ){
	     n -= 2;
	     m -= 1;
	 }

	 else{
	     n -= 1;
	     m -= 2;
	 }

	 ans += 1;

    }

    cout << ans << endl;

    return 0;
}