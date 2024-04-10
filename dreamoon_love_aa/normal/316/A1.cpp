#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[100010];
int ha[256];
int main(){
    int i,j,k,n,qq=0;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='?')qq++;
        else if(s[i]>'0'||s[i]>'9')ha[s[i]]++;
    }
    if(s[0]=='?'){
        qq--;
        k=10;
        long long res=9;
        for(i='A';i<='J';i++){
            if(ha[i]){
                res*=k;
                k--;
            }
        }
        cout<<res;
        for(i=0;i<qq;i++)printf("0");
        puts("");
    }
    else if(s[0]<'0'||s[0]>'9'){
        k=10;
        long long res=1;
        for(i='A';i<='J';i++){
            if(ha[i]){
                res*=min(k,9);
                k--;
            }
        }
        cout<<res;
        for(i=0;i<qq;i++)printf("0");
        puts("");
    }
    else{
        k=10;
        long long res=1;
        for(i='A';i<='J';i++){
            if(ha[i]){
                res*=k;
                k--;
            }
        }
        cout<<res;
        for(i=0;i<qq;i++)printf("0");
        puts("");
    }
    return 0;
}