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
string s;
int dp[1000000];
int main(){
    int i,j,k=0,n,an=100000000;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z')k++,dp[i]=1;
        if(i)dp[i]+=dp[i-1];
    }
    an=n-k;
    for(i=0;i<s.size();i++){
        an=min(an,dp[i]+(n-k)-(i+1-dp[i]));
    }
    cout<<an<<endl;
    return 0;
}