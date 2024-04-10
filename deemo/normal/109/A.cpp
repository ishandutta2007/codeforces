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
    long long ans1 , ans2 = -1;
    cin >> n;
    for (int i = 0 ; i <= 10 ; i++){
	 for (int j = 0 ; j <= 1e6 ; j++){//7
	     long long temp = i * 4 + j * 7;
	     if (temp == n){
		  ans1 = i;
		  ans2 = j;
	     }
	     if (temp > n)	break;
	     if (ans2 != -1)	break;
	 }
	 if (ans2 != -1)  break;
    }	     
    if (ans2 == -1){
	 cout << -1 << endl;
	 return 0;
    }

    for (int i = 0 ; i < ans1 ; i++)
	 cout << 4;
    for (int j = 0 ; j < ans2 ; j++)
	 cout << 7;
    cout << endl;

    return 0;
}