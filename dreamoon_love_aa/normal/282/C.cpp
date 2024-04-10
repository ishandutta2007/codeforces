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
int zero(string & s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')return 0;
    }
    return 1;
}
int main(){
    int i,j,k,n1,n2;
    string s1,s2;
    cin>>s1>>s2;
    n1=s1.size();
    n2=s2.size();
    if(n1!=n2)puts("NO");
    else{
        int x=zero(s1);
        int y=zero(s2);
        if(!(x^y))puts("YES");
        else puts("NO");
    }
    return 0;
}