#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << a*b + b*(c-1) + (a-1)*(c-1);
    return 0;
}