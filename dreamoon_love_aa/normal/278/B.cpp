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
string str[30];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    for(i=0;i<26;i++){
        char c=i+'a';
        for(j=0;j<n;j++){
            for(k=0;k<str[j].size();k++)
                if(str[j][k]==c)break;
            if(k<str[j].size())break;
        }
        if(j==n){
            printf("%c\n",c);
            return 0;
        }
    }
    for(i=0;i<26;i++){
        for(int ii=0;ii<26;ii++){
            char c1=i+'a';
            char c2=ii+'a';
            for(j=0;j<n;j++){
                for(k=0;k+1<str[j].size();k++)
                    if(str[j][k]==c1&&str[j][k+1]==c2)break;
                if(k+1<(int)str[j].size())break;
            }
            if(j==n){
                printf("%c%c\n",c1,c2);
                return 0;
            }
        }
    }
    return 0;
}