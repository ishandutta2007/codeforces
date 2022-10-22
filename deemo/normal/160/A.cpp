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

int n , temp , sum;
vector<int> vec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 sum += temp;
    }
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    
    int i = 0 , t = 0;
    while (sum / 2 >= t){
	 t += vec[i];
	 i++;
    }
    cout << i << endl;
    return 0;
}