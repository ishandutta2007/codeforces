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
long long ans;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < vec.size() ; i++){
	 for (int j = i + 1 ; j < vec.size() ; j++){
	     if (vec[j] == vec[i]){
		  vec[j] += 1;
		  ans++;
	     }
	     else    break;
	 }
    }
    cout << ans << endl;
    return 0;
}