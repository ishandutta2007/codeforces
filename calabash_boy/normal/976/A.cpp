//
// Created by calabash_boy on 18-4-30.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
char s[maxn];
int n;
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    if (n==1){
        printf("%s\n",s);
        return 0;
    }
    int cnt =0;
    for (int i=1;i<n;i++){
        cnt+=s[i]=='0';
    }
    printf("1");
    for (int i=0;i<cnt;i++){
        printf("0");
    }
    printf("\n");
    return 0;
}