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
#define SIZE 33
int a[SIZE][SIZE],row[SIZE],col[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)cin>>a[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    int an=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(col[j]>row[i])an++;
    cout<<an<<endl;
    return 0;
}