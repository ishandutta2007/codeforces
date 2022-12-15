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
        char s[55];
        scanf("%s",s);
        int l=strlen(s),f=0;
        for(int i=0;i<l;i++){
            if(f==0){
                f^=1;
                if(s[i]=='a'){
                    printf("b");
                    continue;
                }
                printf("a");
            }
            else{
                f^=1;
                if(s[i]=='z'){
                    printf("y");
                    continue;
                }
                printf("z");
            }
        }
        puts("");
    }
    return 0;
}