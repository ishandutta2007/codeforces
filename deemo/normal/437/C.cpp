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

long long int n , m , temp , ans , a , b;
vector<pair<int , int>> vec;
vector<int> sec[1100];
int arr[1100];
bool mark[1100][1100];

bool operator <(pair<int , int> a , pair<int , int> b){
    if (a.first < b.first)	return true;
    if (a.first == b.first && a.second < b.second)  return true;
    return false;
}

int main(){
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
	 cin >> temp;
	 vec.push_back({temp , i});
    }
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < vec.size() ; i++)
	 arr[vec[i].second] = i;

    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b;
	 a = arr[a];
	 b = arr[b];
	 sec[a].push_back(b);
	 sec[b].push_back(a);
    }

    for (int i = vec.size() - 1 ; i >= 0 ; i--){
	 for (int j = 0 ; j < sec[i].size() ; j++){
	     if (mark[i][sec[i][j]] == 0){
		  mark[i][sec[i][j]] = 1;
		  mark[sec[i][j]][i] = 1;
		  ans += vec[sec[i][j]].first;
	     }
	 }
    }
    cout << ans << endl;
    return 0;
}