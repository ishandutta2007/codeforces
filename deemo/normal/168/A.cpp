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
    int n , x , y;
    cin >> n >> x >> y;

    int ans = 0;
    while ( double(x + ans) / n * 100 < y ){
	 ans++;
    }
    cout << ans << endl;

    return 0;
}