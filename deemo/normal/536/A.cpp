#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

long long int A , B , n , t , l , m;

bool check(long long int r){
    if ( t < A + ((r - 1) * B) )	return false;
    if ( ( (r - l + 1) * (2 * A + ((r - 1) + (l - 1)) * B) ) / 2 > t * m )	return false;
    return true;
}

long long int bin_search(long long int a , long long int b){
    if ( a == b )   return	a;
    
    long long int mid = floor((a + b) / 2);
    if ( check(mid + 1) )	return	 bin_search(mid + 1 , b);
    return  bin_search(1 , mid);

}

int main(){
    cin >> A >> B >> n;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> l >> t >> m;

	 //nemikhoreh:
	 if ( check(l) == false ){
	     cout << -1 << endl;
	     continue;
	 }

	 //hade aksar r:
	 long long int r = bin_search(1 , t * m);
	 cout << r << endl;
    }
    return 0;
}