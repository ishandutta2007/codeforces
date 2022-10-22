#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

int main(){
    int n , temp;
    vector<int> vec[5];

    cin >> n;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec[temp].push_back(i + 1);
    }
    
    int ans = min( min(vec[1].size() , vec[2].size()) , vec[3].size() );
    cout << ans << endl;
    
    int a , b , c;
    for ( int i = 0 ; i < ans ; i++ ){
	 a = vec[1].back();
	 b = vec[2].back();
	 c = vec[3].back();
	 cout << a << " " << b << " " << c << endl;
	 vec[1].pop_back();
	 vec[2].pop_back();
	 vec[3].pop_back();
    }	 
    
    return 0;
}