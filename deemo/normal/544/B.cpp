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

int n , k;

int main(){
    cin >> n >> k;
    int temp = int(ceil(double(n * n) / double(2)));
    if (k > temp){
	 cout << "NO" << endl;
	 return  0;
    }
    cout << "YES" << endl;
    for (int i = 0 ; i < n ; i++){
	 for (int j = 0 ; j < n ; j++){
	     if ((i + j) % 2 == 0 && k > 0){
		  cout << 'L';
		  k--;
	     }
	     else    cout << 'S';
	 }
	 cout << endl;
    }
    return 0;
}