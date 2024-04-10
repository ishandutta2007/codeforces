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

int ans , n , flag;
int arr[4000];

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
	 cin >> arr[i];

    for (int i = 0 ; i < n ; i++){
	 flag = 0;
	 if (arr[i] == 0)	continue;
	 for (int j = i ; j < n ; j++){
	     if (arr[i] == arr[j])	 flag++;
	     if (flag == 3){
		  cout << -1 << endl;
		  return 0;
	     }
	 }
	 if (flag == 2)	ans++;
    }
    cout << ans << endl;
    return 0;
}