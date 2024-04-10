#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        if(n==1) puts("9");
        else if(n==2) puts("98");
        else{
            printf("98");
            n-=2;
            for(int i=0;i<n;i++) printf("%d",(i%10+9)%10);
            puts("");
        }
    }
    return 0;
}