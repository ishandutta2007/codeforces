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

int a , b , n , ans;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 if (b - a >= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}