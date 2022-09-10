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
int d[1000];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>d[i];
    sort(d,d+n);
    for(i=0;d[i]==0;i++);
    for(;i<n;i=j){
        for(j=i;j<n&&d[j]==d[i];j++);
        if(d[i]==0)continue;
        if(j-i>2){
            puts("-1");
            return 0;
        }
        else if(j-i==2)an++;
    }
    cout<<an<<endl;
    return 0;
}