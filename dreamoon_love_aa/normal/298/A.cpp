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
int main(){
    int i,j,k,n,minL=100000,maxL=0,minR=100000,maxR=0;
    string str;
    cin>>n>>str;
    for(i=0;i<n;i++){
        if(str[i]=='L'){
            minL=min(minL,i);
            maxL=i;
        }
        else if(str[i]=='R'){
            minR=min(minR,i);
            maxR=i;
        }
    }
    minL++;
    minR++;
    maxL++;
    maxR++;
    if(maxL==1&&maxR==1){
        printf("1 1\n");
    }
    else if(maxL==1){
        printf("%d %d\n",minR,maxR+1);
    }
    else if(maxR==1){
        printf("%d %d\n",maxL,minL-1);
    }
    else{
        printf("%d %d\n",minR,minL-1);
    }

    return 0;
}