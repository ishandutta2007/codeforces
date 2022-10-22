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

int n , m , ind , maxi;
long long ans1 , ans2;
int a[2000];
int b[2000];

int main(){
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> a[i];
	 b[i] = a[i];
    }

    for (int i = 0 ; i < n ; i++){
	 maxi = -1;
	 for (int j = 0 ; j < m ; j++){
	     if (maxi == -1 || a[j] > maxi){
		  maxi = a[j];
		  ind = j;
	     }
	 }
	 a[ind] -= 1;
	 ans1 += maxi;
	 maxi = -1;
	 
	 for (int j = 0 ; j < m ; j++){
	     if ((maxi > b[j] || maxi == -1) && b[j] > 0){
		  maxi = b[j];
		  ind = j;
	     }	      
	 }
	 ans2 += maxi;
	 b[ind] -= 1;
    
    } 
    cout << ans1 << " " << ans2 << endl;

    return 0;
}