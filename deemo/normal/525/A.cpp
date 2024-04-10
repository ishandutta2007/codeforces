#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>

using namespace std;

int k[200];
int n , ans;

int main(){
    cin >> n;
    char a , b;
    
    for ( int i = 0 ; i < n - 1 ; i++ ){
	 cin >> a >> b;
	 k[a] += 1;
	 if ( k[b + 32] > 0 ) k[b + 32] -= 1;
	 else	  ans++;
    }

    cout << ans << endl;
    return 0;
}