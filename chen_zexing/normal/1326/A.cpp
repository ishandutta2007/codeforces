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
    while(T--){
        int n;
        cin>>n;
        if(n==1) puts("-1");
        else{
            printf("2");
            for(int i=1;i<n;i++) printf("3");
            puts("");
        }
    }
    return 0;
}