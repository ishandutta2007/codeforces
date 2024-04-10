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

bool check(ll x){
    if (x == 0) return false;
    while (x > 0){
	 if (x % 10 != 4 && x % 10 != 7) return false;
	 x /= 10;
    }
    return true;
}

ll n , ans;

int main(){
    cin >> n;
    while (n > 0){
	 if (n % 10 == 4 || n % 10 == 7) ans++;
	 n /= 10;
    }
    if (check(ans)) cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}