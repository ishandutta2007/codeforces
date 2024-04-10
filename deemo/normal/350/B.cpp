#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int n;
const int max_n = 100 * 1000 + 5;
vector<int> vec;
vector<int> arr;
int jadval[max_n];

void input(){
    cin >> n;
    int temp;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 vec.push_back(temp);

    }
    
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> temp;
	 if ( temp == 0 )	arr.push_back(-1);
	 else	  arr.push_back(temp - 1);
	 jadval[temp - 1] += 1;

    }
    
}

int mark[max_n];
int k;
int max_k = -1 , ind;
int par[max_n];
int g;

void set_Dfs( int u ){
    mark[u] = 1;
    if ( arr[u] != -1 && jadval[arr[u]] < 2 ){
	 if ( mark[ arr[u] ] == 0 ){
	     set_Dfs( arr[u] );
	     k++;

	 }
    }

    if ( g == -1 ){
	 if ( u == ind ) cout << u + 1 << endl;
	 else	  cout << u + 1 << " ";

    }

}

void DFS(){
    for ( int i = 0 ; i < n ; i++ ){
	 if ( vec[i] == 1 ){
	     if ( mark[i] == 0 ){
		  k = 1;
		  set_Dfs( i );
		  if ( k > max_k || max_k == -1 ){
		      max_k = k;
		      ind = i;
		  }

	     }

	 }

    }

}

int main(){
    input();
    DFS();
    g = -1;
    for ( int i = 0 ; i < max_n ; i++ )
	 mark[i] = 0;
    par[ind] = -1;
    cout << max_k << endl;
    set_Dfs(ind);
    return 0;

}