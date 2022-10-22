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
#include<iomanip>

using namespace std;

int n;
long long sum;
int x1 , x2 , yy1 , yy2;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> x1 >> yy1 >> x2 >> yy2;
	 sum += (x2 - x1 + 1) * (yy2 - yy1 + 1);
    }
    cout << sum << endl;
    return 0;
}