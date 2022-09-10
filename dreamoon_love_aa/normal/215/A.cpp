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
int a[55],b[55];
int main(){
    int i,j,k,n,m,ma=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)cin>>b[i];
    k=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(b[j]%a[i]==0){
                int tmp=b[j]/a[i];
                if(tmp>ma){
                    ma=tmp;
                    k=1;
                }
                else if(tmp==ma)k++;
            }
    cout<<k<<endl;
    return 0;
}