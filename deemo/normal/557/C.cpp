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

typedef long long ll;
ll ans;
int n;
const int max_n = 2 * 1e5 + 200;
vector<pair<int , int>> vec;
int arr[max_n];
int p[max_n];

bool help(pair<int , int>	a , pair<int , int> b){
    if (a.first < b.first)	return	 true;
    if (a.first == b.first && a.second > b.second)  return  true;
    return  false;
}

int main(){
    cin >> n;
    int temp;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back({temp , 0});
    }
    for (int i = 0 ; i < n ; i++)
	 cin >> vec[i].second;
    sort(vec.begin() , vec.end() , help);

    p[n] = 0;
    for (int i = vec.size() - 1 ; i >= 0 ; i--)
	 p[i] = vec[i].second + p[i + 1];

    ans = 1e10;
    for (int i = 0 ; i < vec.size() ; ){
	 int j = i;
	 while (j < vec.size() - 1 && vec[j].first == vec[j + 1].first)  j++;
	 int t = j - i + 1;
	 int temp = p[j + 1] , z = max(0 , (j + 1) - (2 * t - 1));
	 for (int k = 1 ; k <= 201 ; k++){
	     if (z == 0)	break;
	     temp += min(z , arr[k]) * k;
	     z -= min(z , arr[k]);
	 }
	 if (temp < ans) ans = temp;
	 for (int k = i ; k <= j ; k++)
	     arr[vec[k].second] += 1;
	 i = j + 1;
    }
    cout << ans << endl;
    return 0;
}