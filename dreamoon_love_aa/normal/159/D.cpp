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
#define SIZE 2222
long long ll[SIZE],rr[SIZE];
int main(){
    int i,j,k,n;
    long long an=0,now=0;
    string str;
    cin>>str;
    n=str.size();
    for(i=0;i<n;i++){
        ll[i]++;
        rr[i]++;
        for(j=1;i-j>=0&&i+j<n;j++){
            if(str[i-j]!=str[i+j])break;
            ll[i-j]++;
            rr[i+j]++;
        }
    }
    for(i=1;i<n;i++){
        for(j=0;i-j-1>=0&&i+j<n;j++){
            if(str[i-j-1]!=str[i+j])break;
            ll[i-j-1]++;
            rr[i+j]++;
        }
    }
    now=rr[0];
    for(i=1;i<n;i++){
        an+=now*ll[i];
        now+=rr[i];
    }
    cout<<an<<endl;
    return 0;
}