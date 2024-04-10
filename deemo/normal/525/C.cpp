#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>

using namespace std;

long long int ans = 1 , tans;
int flag;
int arr[1000 * 1000 + 100];
int n;
int temp;

int main(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 arr[temp] += 1;
    }

    for ( int i = 1000 * 1000 ; i > 1 ; i-- ){
	 if ( arr[i] % 2 != 0 && ( flag != 1 || arr[i] > 1 ) ){
	     arr[i] -= 1;
	     arr[i - 1] += 1;
	     flag = 1;
	     continue;
	 }
	 flag = 0;
    }

    flag = 0;
    int i = 1000 * 1000;
    while ( i >= 1 ){
	 if ( arr[i] > 1 ){
	     arr[i] -= 2;
	     ans *= i;
	     flag ++;
	 }
	 else	  i--;
	 if ( flag == 2 ){
	     flag = 0;
	     tans += ans;
	     ans = 1;
	 }
    }	 

    cout << tans << endl;

    return 0;
}