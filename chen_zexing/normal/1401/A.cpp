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
long long a[30][30];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        if(a<b) cout<<b-a<<endl;
        else if((a-b)%2) printf("1\n");
        else printf("0\n");
    }
    return 0;
}