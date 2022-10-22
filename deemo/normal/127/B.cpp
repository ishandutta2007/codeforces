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

int n , temp , arr[200];
vector<int> vec;
int ans;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 arr[temp] += 1;
    }

    for (int i = 1 ; i <= 100 ; i++)
	 if (arr[i] > 1) vec.push_back(arr[i]);
    
    sort(vec.begin() , vec.end());
    if (vec.size() == 0){
	 cout << 0 << endl;
	 return 0;
    }
    
    while (vec[vec.size() - 1] >= 2){
	 if (vec.size() == 1){
	     ans += vec[vec.size() - 1] / 4;
	     break;
	 }
	 if (vec[vec.size() - 2] >= 2){
	     ans++;
	     vec[vec.size() - 1] -= 2;
	     vec[vec.size() - 2] -= 2;
	 }
	 else{
	     ans += vec[vec.size() - 1] / 4;
	     break;
	 }
	 sort(vec.begin() , vec.end());
    }
    cout << ans << endl;
    
    return 0;
}