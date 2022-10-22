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
long long t , ans;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    for (int i = 0 ; i < n ; i++){
	 if (vec[i] >= t){
	     ans++;
	     t += vec[i];
	 }
    }    
    cout << ans << endl;
    
    return 0;
}