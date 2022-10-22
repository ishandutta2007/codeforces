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

int cnt , n;
int arr[200][200];
int mark[200];

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < n ; j++){
	     cin >> arr[i][j];
	     if (arr[i][j] == 1 || arr[i][j] == 3)   mark[i] = 1;
	     if (arr[i][j] == 2 || arr[i][j] == 3)   mark[j] = 1;
	 }   
    for (int i = 0 ; i < n ; i++)
	 if (mark[i] == 0)	cnt++;
    cout << cnt << endl;
    for (int i = 0 ; i < n ; i++)
	 if (mark[i] == 0){
	     if (cnt != 1)
		  cout << i + 1 << " "; 
	     else    cout << i + 1 << endl;
	     cnt--;
	 }  
    return 0;
}