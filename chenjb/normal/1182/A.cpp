#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n%2==1){ puts("0"); return 0; }
    n/=2;
    cout<<(1ll<<n)<<endl;
    return 0;
}