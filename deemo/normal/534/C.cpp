#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

long long int n , sum;
long long int x; 
vector<long long int> vec;

int main(){
    long long int temp;
    cin >> n >> sum;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
	 x += temp;//jame kolle dice ha
    }

    long long int ans;
    for ( int i = 0 ; i < n ; i++ ){
	 temp = x - vec[i];//jame dice ha be joz dice i om
	 ans = 0;
	 if ( sum - temp - 1 > 0 )	 ans += sum - temp - 1;
	 if ( vec[i] - (sum - (n - 1)) > 0 ) ans += vec[i] - (sum - (n - 1));
	 if ( i == n - 1 )	cout << ans << endl;
	 else	  cout << ans << " ";
    }

    return 0;
}