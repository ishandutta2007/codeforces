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

int n , k;
long long ans;
const int max_n = 1e5 + 200;
vector<int> vec[max_n];
int par[max_n];

int main(){
    cin >> n >> k;
    int temp , t;
    for (int i = 0 ; i < k ; i++){
	 cin >> temp;
	 for (int j = 0 ; j < temp ; j++){
	     cin >> t;   
	     vec[i].push_back(t);
	 }
    }
    for (int i = 0 ; i < k ; i++)
	 for (int j = 0 ; j < vec[i].size() ; j++){
	     if (j == vec[i].size() - 1)
		  par[vec[i][j]] = -1;
	     else    par[vec[i][j]] = vec[i][j + 1];
	 }

    for (int i = 1 ; i < n ; i++){
	 if (par[i] == i + 1)    continue;
	 if (par[i] != -1)	ans++;
	 if (par[i + 1] != -1){
	     par[i + 1] = -1;
	     ans++;
	 }
	 par[i] = i + 1;
	 ans++;
	 continue;
    }
    cout << ans << endl;
    return 0;
}