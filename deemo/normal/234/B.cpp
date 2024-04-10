#include<fstream>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<string>

using namespace std;

int n , k;
vector< pair<int , int> >	vec;

bool help(pair<int , int> a , pair<int , int> b){
    if ( a.first < b.first )    return true;
    if ( a.first == b.first && a.second < b.second )	return true;
    return false;
}

bool help2(pair<int , int> a , pair<int , int> b){
    if ( a.second < b.second )  return true;
    return false;
}

int main(){
    ifstream fin("input.txt");
    fin >> n >> k;
    int a;

    for ( int i = 0 ; i < n ; i++ ){
	 fin >> a;
	 vec.push_back( make_pair(a , i + 1) );
    }
    sort(vec.begin() , vec.end() , help);

    ofstream fout("output.txt");
    reverse(vec.begin() , vec.end());
   
    fout << vec[k - 1].first << endl;
    vector< pair<int , int> >   ans; 
    for ( int i = 0 ; i < k ; i++ ){
	 ans.push_back(vec[i]);
    }    
    sort(ans.begin() , ans.end() , help2);   
 
    for ( int i = 0 ; i < ans.size() - 1 ; i++ ){
	 fout << ans[i].second << " ";
    }
    fout << ans[ans.size() - 1].second << endl;

    return 0;

}