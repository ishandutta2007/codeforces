#include <iostream>
using namespace std;
int main()
{
    long long int a,b,c,n,m;
    cin >> a >> b >> c;
    n=a/c,m=b/c;
    if(a%c!=0) n++;
    if(b%c!=0) m++;
    cout << n*m;
    return 0;
}