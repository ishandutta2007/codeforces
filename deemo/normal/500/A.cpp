#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<string>
#include<utility>
#include<deque>
#include<stack>
#include<map>
#include<set>

using namespace std;

int n , t;
vector<int> vec;

void input(){
    cin >> n >> t;
    t--;
    int temp;
    
    for ( int i = 0 ; i < n - 1 ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);

    }

}


bool get_Ans(){
    int a = 0;
    while ( a <= t ){
	 if ( a == t )   return true;
	 a += vec[a];

    }
    return false;

}


int main(){
    input();
    bool ans = get_Ans();
    if ( ans )  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;

}