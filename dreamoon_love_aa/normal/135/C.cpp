#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100004
char s[SIZE];
vector<string>an;
int main(){
    int i,j,k,n,one=0,zero=0,len,qq,re,re1,re2,one_change=0,zero_change=0;
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]=='1')one++;
        else if(s[i]=='0')zero++;
    }
    qq=len-one-zero;
    re=len-2;
    re1=(re+1)/2;
    re2=re/2;
    if(one<=re1)an.pb("00");
    if(zero<=re2)an.pb("11");
    if(one+qq>re1&&zero+qq>re2){
        if(one<=re1)one_change=1;
        if(zero<=re2)zero_change=1;
        if(s[len-1]=='1'){
            an.pb("01");
        }
        else if(s[len-1]=='0'){
            an.pb("10");
        }
        else{
            if(one_change)an.pb("01");
            if(zero_change)an.pb("10");
        }
    }
    sort(an.begin(),an.end());
    for(i=0;i<an.size();i++)
        cout<<an[i]<<endl;
    return 0;
}