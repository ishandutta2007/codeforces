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
ll x , y , mini = ll(1e14) , n , a , b;
bool flag;

int main(){
    cin >> n >> a >> b;
    if (a > b){
	 flag = 1;
	 swap(a , b);
    }
    n *= 6;

    if (a * b >= n){
	 cout << a * b << endl;
	 if (flag)   cout << b << " " << a << endl;
	 else	  cout << a << " " << b << endl;
	 return  0;
    }

    for (ll i = 1 ; i <= (sqrt(n) + 1) ; i++){
	 ll t = ll(ceil(double(n) / double(i)));
	 if (i < a)  continue;
	 if (t < b)  continue;
	 ll temp = i * t;
	 if (temp - n < mini){
	     mini = temp - n;
	     x = i;
	     y = t;
	 }
    }
    cout << x * y << endl;
    if (flag)	  cout << y << " " << x << endl;
    else    cout << x << " " << y << endl;
    return 0;
}