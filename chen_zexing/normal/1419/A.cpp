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
char s[1005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        if(n%2){
            int f=0;
            for(int i=1;i<=n;i+=2)
                if((s[i]-'0')%2)
                    f=1;
            if(f) printf("1\n");
            else printf("2\n");
        }
        else{
            int f=0;
            for(int i=2;i<=n;i+=2)
                if((s[i]-'0')%2==0)
                    f=1;
            if(f) printf("2\n");
            else printf("1\n");
        }
    }
    return 0;
}