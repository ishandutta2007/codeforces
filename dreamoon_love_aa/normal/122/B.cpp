#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string,int>H;
main(){
    string str;
    cin>>str;
    int i,j;
    int len=str.size();
    for(i=0;i<len;i++){
        for(j=1;i+j<=len;j++){
            if(str[i+j-1]!='4'&&str[i+j-1]!='7')break;
            H[str.substr(i,j)]++;
        }
    }
    map<string,int>::iterator it;
    string an="-1";
    int ma=0;
    for(it=H.begin();it!=H.end();it++){
        if(it->second>ma)ma=it->second,an=it->first;
    }
    cout<<an<<endl;
}