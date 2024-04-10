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
char s[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        int f1=1,f2=1;
        for(int i=0;i<n;i++){
            if(s[i]=='<') f1=0;
            if(s[i]=='>') f2=0;
        }
        if(f1||f2) printf("%d\n",n);
        else{
            int cnt=0;
            for(int i=0;i<n;i++){
                if(s[i]=='-'||s[(i+1)%n]=='-') cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}