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

int n , s , temp;
vector<int> vec;

int main(){
    cin >> n >> s;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    int sum = 0;
    for (int i = 0 ; i < n - 1 ; i++)
	 sum += vec[i];
    if (sum <= s)   cout << "YES" << endl;
    else    cout <<"NO" << endl;
    return 0;
}