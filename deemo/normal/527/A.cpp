#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

int main(){
    long long a , b , c , t , ans = 0;
    cin >> a >> b;
    
    while (b != 0){
	 c = a / b;
	 ans += c;
	 t = b;
	 b = a % b;
	 a = t;
    }
    cout << ans << endl;

    return 0;
}