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

bool help(pair<int , int>	a , pair<int , int> b){
    if (a.first < b.first)	return	 true;
    if (a.first == b.first && a.second < b.second)   return  true;
    return  false;
}

int main(){
    int n , k;
    vector<int> ans;
    vector<pair<int , int>>	vec;
    cin >> n >> k;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back({temp , i + 1});
    }	 
    sort(vec.begin() , vec.end() , help);
    int sum = 0;
    for (int i = 0 ; i < vec.size() ; i++){
	 sum += vec[i].first;
	 if (sum <= k)   ans.push_back(vec[i].second);
    }
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i++){
	 if (i == ans.size() - 1)	 cout << ans[i] << endl;
	 else	  cout << ans[i] << " ";
    }
    return 0;
}