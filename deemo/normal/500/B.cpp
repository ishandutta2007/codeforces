#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int n;
const int max_n = 300 + 20;
vector<int> vec;
vector<int> ad_list[max_n];
bool mark[max_n];

void input(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;	   
	 vec.push_back(temp);
    }

    char ch;
    for ( int i = 0 ; i < n ; i++ )
	 for ( int j = 0 ; j < n ; j++ ){
	     cin >> ch;
	     if ( ch == '1' )    ad_list[i].push_back(j);
	 }
}

vector<int> cur;
vector<int> temp_ind;

void dfs(int v){
    mark[v] = 1;
    temp_ind.push_back(v);
    cur.push_back(vec[v]);
    
    int temp;
    for ( int i = 0 ; i < ad_list[v].size() ; i++ ){
	 temp = ad_list[v][i];
	 if ( mark[temp] == 0 )  dfs(temp);
    }
}

void fix(){
    for ( int i = 0 ; i < temp_ind.size() ; i++ )
	 vec[temp_ind[i]] = cur[i];
}

void get_Ans(){
    for ( int i = 0 ; i < n ; i++ ){
	 if ( mark[i] == 0 ){
	     cur.clear();
	     temp_ind.clear();
	     dfs(i);
	     sort(cur.begin() , cur.end());
	     sort(temp_ind.begin() , temp_ind.end());
	     fix();
	 }
    }
}

void show_Ans(){
    for ( int i = 0 ; i < vec.size() - 1 ; i++ )
	 cout << vec[i] << " ";
    cout << vec[vec.size() - 1] << endl;
}

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;
}