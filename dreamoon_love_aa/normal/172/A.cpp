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
string str[1000000];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>str[i];
    for(i=0;i<str[0].size();i++){
        for(j=1;j<n;j++)
            if(str[j][i]!=str[j-1][i])break;
        if(j<n)break;
    }
    cout<<i<<endl;
    return 0;
}