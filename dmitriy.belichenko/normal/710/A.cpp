#include<iostream>
using namespace std;
int main()
{
int b;
char a;
cin >> a >> b;
int ans = 0;
if( a > 'a' && a < 'h' && b > 1 && b < 8 ) ans = 8;
if( a > 'a' && a < 'h' &&( b == 1 || b == 8)) ans = 5;
if( (a == 'a' || a == 'h' ) &&( b > 1 && b < 8) ) ans = 5;
if( (a == 'a' || a == 'h') && ( b == 1 || b==8 )     ) ans = 3;
cout << ans;

}