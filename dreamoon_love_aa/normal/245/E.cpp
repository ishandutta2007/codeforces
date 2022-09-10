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
char s[1000000];
int main(){
    int i,j,k=0,n,ma=0,mi=0;
    gets(s);
    for(i=0;s[i];i++){
        if(s[i]=='+'){
            k++;
        }
        else{
            k--;
        }
        ma=max(ma,k);
        mi=min(mi,k);
    }
    cout<<ma-mi<<endl;
    return 0;
}