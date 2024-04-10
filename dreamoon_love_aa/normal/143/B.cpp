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
    int i,j,k,n;
    bool neg=0;
    string str;
    cin>>str;
    if(str[0]=='-'){
        neg=1;
        str=str.substr(1);
    }
    for(i=0;i<str.size();i++){
        if(str[i]>='1'&&str[i]<='9')break;
    }
    if(i==str.size())neg=0;
    for(i=0;i<str.size()&&str[i]!='.';i++);
    if(i==str.size()){
        str+=".00";
    }
    else{
        for(j=1;j<3&&i+j<str.size();j++);
        str=str.substr(0,i+j);
        while(j<3){
            str+='0';
            j++;
        }
    }
    if(neg)putchar('(');
    putchar('$');
    for(j=0;j<str.size();j++){
        if(j&&i-j>=3&&(i-j)%3==0)putchar(',');
        putchar(str[j]);
    }
    if(neg)puts(")");
    else puts("");
    return 0;
}