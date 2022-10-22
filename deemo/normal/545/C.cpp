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

int n , a , b , fl , ans;
vector<pair<int , int>> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 vec.push_back({a , b});
    }
    for (int i = 0 ; i < n ; i++){
	 if (i == 0 || i == n - 1)	 ans++;
	 else{
	     if (fl == 0 && vec[i].second < vec[i].first - vec[i - 1].first){
		  ans++;
		  continue;
	     }
    	     if (vec[i].second < vec[i + 1].first - vec[i].first){
		  ans++;
		  vec[i].first += vec[i].second;
		  continue;
	     }
	 }
    }
    cout << ans << endl;
    return 0;
}