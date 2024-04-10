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
    int a , b , n;
    cin >> a >> b >> n;
    int i = 1;
    while (n > 0){
	 if (i % 2 == 1) n -= __gcd(a , n);
	 else	  n -= __gcd(b , n);
	 i++;
    }

    if (i % 2 == 0) cout << 0 << endl;
    else    cout << 1 << endl;

    return 0;
}