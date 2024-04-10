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
#define SIZE 1000000
int a[SIZE];
int main(){
    int i,j,k,n,m,mi=10000000;
    cin>>m;
    for(i=0;i<m;i++){
        int x;
        cin>>x;
        mi=min(mi,x);
    }
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int cnt=mi+2;
    int an=0;
    for(i=n-1;i>=0;i--){
        cnt--;
        if(cnt>=2)an+=a[i];
        if(cnt==0)cnt=mi+2;
    }
    cout<<an<<endl;
    return 0;
}