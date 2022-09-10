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
int d[1000000],dn;
int main(){
    int i,j,k,n,m;
    long long an=0;
    cin>>n>>str;
    m=str.size();
    for(i=0;i<m;i++){
        if(str[i]=='1')d[dn++]=i;
    }
    if(dn<n){
        puts("0");
        return 0;
    }
    if(n){
        for(i=n-1;i<dn;i++){
            long long ll,rr;
            if(i==dn-1)rr=m-d[i];
            else rr=d[i+1]-d[i];
            if(i==n-1)ll=d[i-n+1]+1;
            else ll=d[i-n+1]-d[i-n];
            an+=ll*rr;
        }
    }
    else{
        for(i=0;i<m;i=j){
            if(str[i]=='1'){
                j=i+1;
                continue;
            }
            for(j=i;j<m&&str[j]=='0';j++);
            an+=(long long)(j-i)*(j-i+1)/2;
        }
    }
    cout<<an<<endl;
    return 0;
}