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

int a , b;
int t , ans;

int main(){
    cin >> a >> b;
    while (a > 0){
	 a -= 1;
	 t++;
	 ans += 1;
	 if (a == 0)
	     if (t >= b){
		  t -= b;
		  a += 1;
	     }
    }
    cout << ans << endl;
    return 0;
}