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
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            int x;
            cin>>x;
            if(i==j||i+j==n-1||i*2+1==n||j*2+1==n)an+=x;
        }
    cout<<an<<endl;
    return 0;
}