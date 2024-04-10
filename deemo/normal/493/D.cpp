#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int n;

void input(){
    cin >> n;

}


int main(){
    input();
    if ( n % 2 == 1 )   cout << "black" << endl;
    else{
	 cout << "white" << endl;
	 cout << 1 << " " << 2 << endl;

    }
    return 0;

}