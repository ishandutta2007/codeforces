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
char s[105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        int l,r;
        for(int i=1;i<=q;i++){
            scanf("%d%d",&l,&r);
            int f=0;
            for(int j=l-1;j>=1;j--)
                if(s[j]==s[l])
                    f=1;
            for(int j=r+1;j<=n;j++)
                if(s[j]==s[r])
                    f=1;
            if(f) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}