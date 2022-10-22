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

long long int C , HR , HB , WR , WB;
long long int maxi = -1;

void input(){
    cin >> C >> HR >> HB >> WR >> WB;
}

int main(){
    input();
    for ( int i = 0 ; i * WR <= C && i <= 1000 * 1000 ; i++ )
	 if ( maxi == -1 || maxi < i * HR + int( (C - i * WR) / WB ) * HB )
	     maxi = i * HR + ( (C - i * WR) / WB ) * HB;
    
    for ( int i = 0 ; i * WB <= C && i <= 1000 * 1000 ; i++ )
	 if ( maxi == -1 || maxi < i * HB + int( (C - i * WB) / WR ) * HR )
	     maxi = i * HB + ( (C - i * WB) / WR ) * HR;

    if ( maxi >= 0 )	   cout << maxi << endl;
    else    cout << 0 << endl;
    return 0;
}