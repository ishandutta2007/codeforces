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
int d[100000];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    an=n;
    for(i=0;i<n;i++)cin>>d[i];
    an+=d[0];
    for(i=1;i<n;i++){
        if(d[i-1]<=d[i])an+=d[i]-d[i-1]+1;
        else an+=d[i-1]-d[i]+1;
    }
    cout<<an<<endl;
    return 0;
}