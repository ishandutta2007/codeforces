#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[2005],n;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int f1=0,f0=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2) f1=1;
            else f0=1;
        }
        if(f1&&f0) printf("YES\n");
        else if(f1){
            if(n%2) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}