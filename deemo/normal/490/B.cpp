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

const int max_n = 1000 * 1000 + 20;
int n;
int ans[max_n];
int dback[max_n];
int dfor[max_n];
int ba , front;
bool mark[max_n];

void init(){
    for ( int i = 0 ; i < max_n ; i++ ){
	 dback[i] = -1;
	 dfor[i] = -1;
    }		  
}

int main(){
    cin >> n;
    init();
    int a , b;

    for ( int i = 0 ; i < n ; i++ ){
	 cin >> a >> b;
	 dback[a] = b;
	 dfor[b] = a;
	 mark[a] = 1;
	 mark[b] = 1;
    }

    for ( int i = 0 ; i < max_n ; i++ )
	 if ( dfor[i] == -1 && mark[i] == 1 ){

	     front = i;
	     for ( int j = 0 ; j < max_n ; j++ ){
		  if ( j == i )   continue;
		  if ( dfor[j] == 0 && mark[j] == 1 ){
		      ba = j;
		      break;
		  }
	     }
	     break;
	 }

    ans[0] = front;
    ans[1] = ba;

    int p = front , q = ba;
    for ( int i = 2 ; i < n ; i++ ){
	 if ( i % 2 == 0 ){
	     ans[i] = dback[p];
	     p = dback[p];
	 } 
	 if ( i % 2 == 1 ){
	     ans[i] = dback[q];
	     q = dback[q];
	 }
    }

    for ( int i = 0 ; i < n - 1 ; i++ )
	 cout << ans[i] << " ";
    cout << ans[n - 1] << endl;

    return 0;
}