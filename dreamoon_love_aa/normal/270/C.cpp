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
#define SIZE 100010
struct data{
    int x,y;
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
}a[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i].x>>a[i].y;
    sort(a,a+n);
    int an=a[n-1].x+1;
    for(i=0;i<n;i++){
        for(j=0;(1ll<<(j*2))<a[i].y;j++);
        an=max(an,a[i].x+j);
    }
    cout<<an<<endl;
    return 0;
}