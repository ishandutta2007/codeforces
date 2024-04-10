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
bool valid(int x,int y){
    char s[15];
    int i,tmp=0;
    sprintf(s,"%d",x);
    for(i=0;s[i];i++){
        if(s[i]=='4'||s[i]=='7'){
            tmp*=10;
            tmp+=s[i]-'0';
        }
    }
    return tmp==y;
}
int main(){
    int i,j,k,n,a,b;
    cin>>a>>b;
    a++;
    while(!valid(a,b))a++;
    cout<<a<<endl;
    return 0;
}