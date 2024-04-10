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

int main(){
    long long int a , b , s;
    cin >> a >> b >> s;
    long long int t = abs(a) + abs(b);
    if ( t % 2 == s % 2 && s >= t ) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}