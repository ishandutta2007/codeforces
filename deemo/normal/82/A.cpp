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
    int n;
    cin >> n;
    int i = 5;
    while (i <= n){
	 n -= i;
	 i *= 2;
    }
    if (n == 0){
	 cout << "Howard" << endl;
	 return 0;
    }
    if (n <= i / 5){
	 cout << "Sheldon" << endl;
	 return 0;
    }	 
    if (n <= 2 * i / 5){
	 cout << "Leonard" << endl;
	 return 0;
    }
    if (n <= 3 * i / 5){
	 cout << "Penny" << endl;
	 return 0;
    }
    if (n <= 4 * i / 5){
	 cout << "Rajesh" << endl;
	 return 0;
    }
    cout << "Howard" << endl;
    return 0;
}