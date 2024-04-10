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

int n , a , b , c;
int mini[3];
int maxi[3];

int main(){
    cin >> n;
    for (int i = 0 ; i < 3 ; i++)
	 cin >> mini[i] >> maxi[i];
    a = mini[0];
    b = mini[1];
    c = mini[2];
    n = n - (a + b + c);
    a += min(maxi[0] - mini[0] , n);
    n -= min(maxi[0] - mini[0] , n);
    b += min(maxi[1] - mini[1] , n);
    n -= min(maxi[1] - mini[1] , n);
    c += min(maxi[2] - mini[2] , n);
    cout << a << " " <<b << " " << c << endl;
    return 0;
}