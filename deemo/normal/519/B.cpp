#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

int n;
vector<int> vec;
vector<int> v;
vector<int> sec;
vector<int> ans;

int main(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);
    }

    for ( int i = 0 ; i < n - 1 ; i++ ){
	 cin >> temp;
	 v.push_back(temp);
    }

    for ( int i = 0 ; i < n - 2 ; i++ ){
	 cin >> temp;
	 sec.push_back(temp);
    }

    sort(vec.begin() , vec.end());
    sort(sec.begin() , sec.end());
    sort(v.begin() , v.end());


    for ( int i = 0 ; i < vec.size() ; i++ ){
	 if ( i == vec.size() - 1 ){
	     ans.push_back(vec[i]);
	     break;
	 }
    
	 if ( vec[i] == v[i] )   continue;

	 ans.push_back(vec[i]);
	 break;
    }

    for ( int i = 0 ; i < v.size() ; i++ ){
	 if ( i == v.size() - 1 ){
	     ans.push_back(v[i]);
	     break;
	 }
	 if ( v[i] == sec[i] )   continue;

	 ans.push_back(v[i]);
	 break;
    }

    cout << ans[0] << endl;
    cout << ans[1] << endl;

    return 0;
}