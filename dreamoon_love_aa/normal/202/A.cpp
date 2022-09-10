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
    string str,an="";
    cin>>str;
    n=str.size();
    for(i=1;i<(1<<n);i++){
        string tmp="";
        for(j=0;j<n;j++)
            if((i>>j)&1)tmp+=str[j];
        for(j=0;j<tmp.size();j++)
            if(tmp[j]!=tmp[tmp.size()-1-j])break;
        if(j==tmp.size()){
            an=max(an,tmp);
        }
    }
    cout<<an<<endl;
    return 0;
}