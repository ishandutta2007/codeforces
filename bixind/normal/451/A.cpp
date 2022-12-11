#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if (a>b) a = b;
    if ((a % 2) == 0) cout<<"Malvika"; else cout<<"Akshat";
    return 0;
}