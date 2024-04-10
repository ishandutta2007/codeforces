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

int n;
long long ans;

int main(){
    cin >> n;
    long long t = 9;
    while (n > 0){
	 ans += n;
	 n -= t;
	 t = t * 10;
    }
    cout << ans << endl;
    return 0;
}