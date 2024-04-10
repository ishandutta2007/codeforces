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

bool fl = 1;
int n , k;
char arr[200][200];
int vec[300];
int guess[300];
vector<int> ans;
bool mark[300];

bool check(){
    for (int i = 0 ; i < n ; i++)
	 if (vec[i] == guess[i])  return  true;
    return  false;
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++)
	 for (int j = 0 ; j < n ; j++)
	     cin >> arr[i][j];
    for (int i = 0 ; i < n ; i++)
	 cin >> guess[i];
    
    int ind;
    while (check()){
	 ind = -1;
	 if (k == n){
	     fl = 0;
	     break;
	 }

	 for (int i = 0 ; i < n ; i++){
	     if (mark[i] == 1)   continue;
	     if (guess[i] == vec[i]){
		  ind = i;
		  break;
	     }
	 }
	 if (ind == -1)  break;
	 mark[ind] = 1;
	 k++;

	 for (int i = 0 ; i < n ; i++)
	     if (arr[ind][i] == '1') vec[i] += 1;
	 ans.push_back(ind + 1);
	 	 
    }
    if (fl == 1){
	 cout << k << endl;
	 for (int i = 0 ; i < k ; i++){
	     if (i != k - 1)	cout << ans[i] << " ";
	     else    cout << ans[i] << endl;
	 }
    }
    else    cout << -1 << endl;
    return 0;
}