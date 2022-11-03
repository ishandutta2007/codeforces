#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

bool go(long long a,long long b) {
    if (a>b) swap(a,b);
    if (a==0) return false;
    bool lose=!go(b%a,a);
    if (!lose) {
        b-=b%a;
        if (a>1000000000||(a&1)) lose=(b/a)%2==0;
        else {
            b%=a*(a+1); b/=a;
            lose=(b>=a||b%2==0);
        }
    }
    return lose;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int T; long long a,b;
    cin >> T;
    for(int i=0;i<T;++i) {
        cin >> a >> b;
        puts(go(a,b) ? "First" :"Second");
    }
    return 0;
}