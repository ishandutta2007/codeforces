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

int n , x , a , b , flag;

int main(){
    cin >> n >> x;
    cin >> a >> b;
    for (int i = 0 ; i < n - 1 ; i++){
	 int p = 7 - x;
	 cin >> a >> b;
	 if (a == p || b == p || a == x || b == x)   flag = 1;
	 if (flag == 1)  break;
    }
    if ( flag == 1) cout << "NO" << endl;
    else    cout <<"YES" << endl;
    return 0;
}