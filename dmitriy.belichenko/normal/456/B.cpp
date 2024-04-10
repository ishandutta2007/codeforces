#include<vector>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<set>
#include<map>
#include<iomanip>
#include<string>
#include<iostream>
#include<math.h>
#define count count1557
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;



int main()
{
   

    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = 0;
    if(s.size() >= 2)
    n = ((int)s[s.size()-2]- int('0'))*10 +((int)s[s.size()-1]- (int)('0'));
    else n =((int)s[s.size()-1]- (int)('0'));
    if( n % 4 == 0) cout << (4);
    if( n % 4 == 1 ) cout <<(1 + 2 + 3 + 4) % 5;
    if( n % 4 == 2 ) cout <<(1 + 4 + 4 + 1) % 5;
    if( n % 4 == 3 ) cout <<(1 + 3 + 2 + 4) % 5;

}