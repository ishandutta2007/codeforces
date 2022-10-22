#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>

using namespace std;

int ans;
string s;

void input(){
    cin >> s;

}


void get_Ans(){
    char a = s[0];
    char b = s[1];
    int ans1 = 0 , ans2 = 0;

    if ( a == '0' ) ans1 = 2;
    if ( a == '1' ) ans1 = 7;
    if ( a == '2' ) ans1 = 2;
    if ( a == '3' ) ans1 = 3;
    if ( a == '4' ) ans1 = 3;
    if ( a == '5' ) ans1 = 4;
    if ( a == '6' ) ans1 = 2;
    if ( a == '7' ) ans1 = 5;
    if ( a == '8' ) ans1 = 1;
    if ( a == '9' ) ans1 = 2;

    if ( b == '0' ) ans2 = 2;
    if ( b == '1' ) ans2 = 7;
    if ( b == '2' ) ans2 = 2;
    if ( b == '3' ) ans2 = 3;
    if ( b == '4' ) ans2 = 3;
    if ( b == '5' ) ans2 = 4;
    if ( b == '6' ) ans2 = 2;
    if ( b == '7' ) ans2 = 5;
    if ( b == '8' ) ans2 = 1;
    if ( b == '9' ) ans2 = 2;

    ans = ans1 * ans2;
    cout << ans << endl;

    

}


int main(){
    input();
    get_Ans();
    return 0;

}