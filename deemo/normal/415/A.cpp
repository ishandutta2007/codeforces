#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>

using namespace std;

int n , m;
vector<int> vec;
int mark[200];
int temp;

int main(){
    cin >> n >> m;
    for ( int i = 0 ; i < m ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for ( int i = 0 ; i < vec.size() ; i++ ){
	 for ( int j = n ; j >= vec[i] ; j-- )
	     if ( mark[j] == 0 ) mark[j] = vec[i];
    }

    for ( int i = 1 ; i < n ; i++ ){
	 cout << mark[i] << " ";
    }
    cout << mark[n] << endl;

    return 0;
}