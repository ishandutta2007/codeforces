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

int n , a , b , ans , maxi;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 ans -= a;
	 ans += b;
	 maxi = max(maxi , ans);
    }
    cout << maxi << endl;
    return 0;
}