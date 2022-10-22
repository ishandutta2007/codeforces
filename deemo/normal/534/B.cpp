#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int v1 , v2 , t , d;

int main(){
    cin >> v1 >> v2;
    cin >> t >> d;
    int i = 1 , ans = v1;
    while ( (v1 + d) - (t - i - 1) * d <= v2 && i < t ){
	 v1 += d;
	 i += 1;
	 ans += v1;
    }

    if ( v1 - (t - i) * d < v2 ){
	 v1 = v2 + (t - i - 1) * d;
	 ans += v1;
	 i++;
    }

    for ( int j = i + 1 ; j <= t ; j++ ){
	 v1 -= d;
	 ans += v1;
    }

    cout << ans << endl;

    return 0;
}