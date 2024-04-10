#include<iostream>
#include<vector>

using namespace std;

int n , ans;
const int max_n = 100 * 1000 + 10;
int arr[max_n];
int pl[max_n];

void input(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ){
	 cin >> arr[i];
	 if ( arr[i] == i )	ans += 1;
	 pl[arr[i]] = i;
    }
}

int flag;

void get_Ans(){
    for ( int i = 0 ; i < n ; i++ ){
	 if ( arr[i] == i )	continue;
	 if ( pl[i] == arr[i] )  flag = 1;
    }
}

int main(){
    input();
    if ( ans == n || ans == n - 2 ){
	 cout << n << endl;
	 return 0;
    } 
    get_Ans();
    if ( flag == 1 )	   cout << ans + 2 << endl;
    else    cout << ans + 1 << endl;
    return 0;
}