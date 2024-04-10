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
string str;
int main(){
    int i,j,k,n;
    cin>>str;
    for(i=0;i<str.size()&&str[i]=='1';i++);
    if(i==str.size())cout<<str.substr(1)<<endl;
    else cout<<str.substr(0,i)+str.substr(i+1,str.size()-i-1)<<endl;
    return 0;
}