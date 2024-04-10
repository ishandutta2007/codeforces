#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<map>

using namespace std;

int n;
const int max_n = 3000 + 10;
vector<int> vec;
vector<int> sec;
vector< pair<int , int> >	ans;
map<int , int> p;

void input(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 p[temp] = i;
	 vec.push_back(temp);
    }
    sec.assign(vec.begin() , vec.end());
    sort(sec.begin() , sec.end());
}

void get_Ans(){
    for ( int i = 0 ; i < n ; i++ ){
	 if ( vec[i] == sec[i] )	continue;

	 for ( int j = i ; j < n ; j++ ){
	     if ( vec[j] == sec[i] ){
		  ans.push_back( make_pair(i , j) );
		  swap(vec[i] , vec[j]);
		  break;
	     }
	 }	 
    }
}

void show_Ans(){
    cout << ans.size() << endl;
    if ( ans.size() == 0 )	return;

    for ( int i = 0 ; i < ans.size() - 1 ; i++ )
	 cout << ans[i].first << " " << ans[i].second << endl;
    cout << ans[ans.size() - 1].first << " " << ans[ans.size() - 1].second << endl;
}

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;
}