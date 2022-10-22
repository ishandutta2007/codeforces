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

int a = -1 , b;
int temp;
vector<int> vec;

int main(){
    for (int i = 0 ; i < 6 ; i++){
	 cin >> temp;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end());
    if (vec[0] == vec[1] && vec[2] == vec[3] && vec[1] == vec[2])   a = vec[4] , b = vec[5];
    else    if (vec[1] == vec[2] && vec[3] == vec[4] && vec[2] == vec[3])   a = vec[0] , b = vec[5];
    else    if (vec[2] == vec[3] && vec[4] == vec[5] && vec[3] == vec[4])   a = vec[0] , b = vec[1];
    if (a == -1){
	 cout << "Alien" << endl;
	 return 0;
    }
    if (a == b){
	 cout << "Elephant" << endl;
	 return 0;
    }
    cout << "Bear" << endl;
    return 0;
}