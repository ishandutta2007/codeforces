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
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%2) printf("7");
        else printf("1");
        for(int i=1;i<n/2;i++) printf("1");
        printf("\n");
    }
    return 0;
}