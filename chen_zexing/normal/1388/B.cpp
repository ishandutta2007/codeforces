#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int t=n/4+(n%4>0);
        for(int i=1;i<=n-t;i++) printf("9");
        for(int i=n-t+1;i<=n;i++) printf("8");
        printf("\n");
    }
}