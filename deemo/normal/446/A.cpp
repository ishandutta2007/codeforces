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

int n , temp;
const int max_n = 1e5 + 10;
int dp[max_n];
int d[max_n];
int maxi;
vector<int> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for (int i = 0 ; i < n ; i++){
	 if (i == 0) d[i] = 1;
	 else{
	     if (vec[i] <= vec[i - 1])    d[i] = 1;
	     else    d[i] = d[i - 1] + 1;
	 }
    }	 

    for (int i = 0 ; i < n ; i++){
	 if (d[i] == i + 1 || d[i] == i){
	     dp[i] = i + 1;
	     continue;
	 }
	 int temp = max(d[i - 1] + 1 , d[i] + 1);

	 if (vec[i - d[i] + 1] - 1 > vec[i - d[i] - 1]){
	     dp[i] = max(d[i] + 1 + d[i - d[i] - 1] , temp); 
	     continue;
	 }

	 if (i - d[i] + 2 <= i && vec[i - d[i]] + 1 < vec[i - d[i] + 2]){
	     dp[i] = max(d[i - d[i]] + d[i] , temp);
	     continue;
	 } 

	 dp[i] = max(d[i - 1] + 1 , temp);
    }
    for (int i = 0 ; i < n ; i++)
	 maxi = max(dp[i] , maxi);
    cout << maxi << endl;

    return 0;
}