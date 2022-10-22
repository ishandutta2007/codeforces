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
vector<int> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for (int i = 0 ; i < n ; i++){
	 int ret = 0;
	 for (int j = 0 ; j < n ; j++){
	     if (i == j) continue;
	     if (vec[j] > vec[i])	 ret++;
	 }
	 if (i == n - 1) cout << ret + 1 << endl;
	 else	  cout << ret + 1 << " ";
    }
    
    return 0;
}