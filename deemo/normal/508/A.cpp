#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<utility>
#include<map>
#include<stack>

using namespace std;

int n , m , k;
const int max_n = 1000 + 10;
bool jadval[max_n][max_n];

bool check(int a , int b){
    if ( jadval[a - 1][b - 1] == 1 && jadval[a - 1][b] == 1 && jadval[a][b - 1] == 1 )  return true;
    if ( jadval[a - 1][b] == 1 && jadval[a - 1][b + 1] == 1 && jadval[a][b + 1] == 1 )  return true;
    if ( jadval[a][b - 1] == 1 && jadval[a + 1][b] == 1 && jadval[a + 1][b - 1] == 1 )  return true;
    if ( jadval[a][b + 1] == 1 && jadval[a + 1][b] == 1 && jadval[a + 1][b + 1] == 1 )  return true;
    return false;
}

int main(){
    cin >> n >> m >> k;
    int flag = 0;
    int a , b;
    for ( int i = 0 ; i < k ; i++ ){
	 cin >> a >> b;
	 jadval[a][b] = 1;
	 if ( flag != 0 )	continue;
	 if ( check(a , b) ){
	     flag = i + 1;
	 }
    }
    if ( flag == 0 )	   cout << 0 << endl;
    else    cout << flag << endl;
    return 0;

}