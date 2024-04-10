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

typedef long long ll;
int n , a , c , d , b , maxi , ans1 , ans2 , ind;

int main(){
    cin >> n;
    maxi = 1e9;
    for (int i = 0 ; i < 4 ; i++){
	 cin >> a >> b >> c >> d;
	 a = min(a , b); c = min(c , d);
	 if (a + c < maxi){
	     maxi = a + c;
	     ans1 = a;
	     ans2 = c;
	     ind = i + 1;
	 }
    }	     
    if (maxi > n){
	 cout << -1 << endl;
	 return  0;
    }
    cout << ind << " " << ans1 << " " << (n - ans1) << endl;
    return 0;
}