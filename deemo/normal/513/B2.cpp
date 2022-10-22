#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long double n , m;
vector<int>	  ans;
const int max_n = 100;
int mark[max_n];

int find_next(int x){
    for ( int i = x + 1 ; i <= n ; i++ )
	 if ( mark[i] != 1 )	    return i;
    for ( int i = x - 1 ; i >= 1 ; i-- )
	 if ( mark[i] != 1 )	    return i;
    return -1;
}

void get_Ans(long double a , long double b , long double k , int x){
    if ( ans.size() == n )	return;
    if ( (b - a + 1) / 2  >= k || (k == 1 && (b - a + 1) == 1) ){
	 ans.push_back(x);
	 mark[x] = 1;

	 if ( a == b )
	     get_Ans(a , floor((b + a) / 2) , k , find_next(x));
    
	 get_Ans(a , floor((b + a) / 2) , k , find_next(x));
	 return;
    }	 

    get_Ans( a + floor((b - a + 1) / 2) , b , k - floor((b - a + 1)/2) , find_next(x));
    
}

int main(){
    cin >> n >> m;
    if ( n == 1 ){
	 cout << 1 << endl;
	 return 0;
    }
    get_Ans(1 , pow(2 , n - 1) , m , 1);
    for ( int i = 0 ; i < ans.size() - 1 ; i++ )
	 cout << ans[i] << " ";
    cout << ans[ans.size() - 1] << endl;
    return 0;

}