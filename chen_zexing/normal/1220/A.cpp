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
char s[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++) if(s[i]=='n') cnt++;
        for(int i=1;i<=cnt;i++) printf("1 ");
        for(int i=1;i<=(n-cnt*3)/4;i++) printf("0 ");
    }
    return 0;
}