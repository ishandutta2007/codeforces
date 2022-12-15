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
char s[25],t[25];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        scanf("%s",s);
        scanf("%s",t);
        int l1=strlen(s),l2=strlen(t),fl=-1;
        for(int i=1;i<=l1;i++){
            int f=1;
            if(l1%i||l2%i) continue;
            for(int j=i;j<l1;j++)
                if(s[j]!=s[j-i])
                    f=0;
            for(int j=i;j<l2;j++)
                if(t[j]!=t[j-i])
                    f=0;
            for(int j=0;j<i;j++)
                if(s[j]!=t[j])
                    f=0;
            if(!f) continue;
            fl=i;
        }
        if(fl==-1) puts("-1");
        else{
            for(int i=1;i<=(l1*l2)/fl/fl;i++)
                for(int j=0;j<fl;j++)
                    printf("%c",s[j]);
            puts("");
        }
    }
    return 0;
}