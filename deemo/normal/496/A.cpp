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
int mini = 1e8 , maxi = 0 , ind;
vector<int> vec , sec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    for (int i = 0 ; i < n - 2 ; i++)
	 if (mini > vec[i + 2] - vec[i]){
	     mini = vec[i + 2] - vec[i];
	     ind = i + 1;
	 } 
    for (int i = 0 ; i < ind ; i++)
	 sec.push_back(vec[i]);
    for (int i = ind + 1 ; i < n ; i++)
	 sec.push_back(vec[i]);
    for (int i = 0 ; i < n - 2 ; i++)
	 maxi = max(maxi , sec[i + 1] - sec[i]);
    maxi = maxi;
    cout << maxi << endl;
    return 0;
}