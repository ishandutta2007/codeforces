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
    //cin>>T;
    while(T--){
        int n,s;
        cin>>n>>s;
        if(s<n*2) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<n;i++) printf("2 ");
            printf("%d\n",s-(n*2-2));
            puts("1");
        }
    }
    return 0;
}