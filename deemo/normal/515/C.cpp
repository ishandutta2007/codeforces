#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iomanip>

using namespace std;

long long int n;
string a;
long long int aa;
int arr[20];

void input(){
    cin >> n;
    cin >> a;
}   

void add(int x){
    if ( x == 0 || x == 1 )	return;
    
    for ( int i = 2 ; i <= x ; i++ )
	 arr[i] += 1;
}

void cal(int x){
    for ( int i = 0 ; i < a.size() ; i++ )
	 if ( a[i] == x + 48 )	add(x);
    
}   

void init(){
    for ( int i = 0 ; i < 10 ; i++ )
	 cal(i);
}   

string ans;

void get(int x){
    int flag = 0;
    for ( int i = x ; i >= 2 ; i-- )
	 if ( arr[i] > 0 )	flag += 1;
    if ( flag != x - 1 )	return;

    for ( int i = x ; i >= 2 ; i-- )
	 arr[i] -= 1;
    ans += x + 48;
}

void get_Ans(){
    ans = "";

    arr[3] += 2 * arr[9];
    arr[2] += 3 * arr[8];
    while ( arr[7] > 0 )	get(7);
    arr[2] += arr[6];
    arr[3] += arr[6];
    while ( arr[5] > 0 )	get(5);
    arr[2] += 2 * arr[4];
    while ( arr[3] > 0 )	get(3);
    while ( arr[2] > 0 )	get(2);    

    if ( ans == "" )	   ans = "1";
}

int main(){
    input();
    init();
    get_Ans();
    cout << ans << endl;
    return 0;
}