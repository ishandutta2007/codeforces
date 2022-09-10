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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    string str;
    cin>>n;
    cin>>str;
    vector<int>d[2];
    for(i=0;i<n/2;i++){
        if(str[i]=='L')printf("%d %d\n",i+1,i+1+n/2);
        else printf("%d %d\n",i+1+n/2,i+1);
    }
    return 0;
}