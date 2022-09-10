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
struct data{
    int x,y;
    void scan(){cin>>x>>y;}
    bool operator<(const data& b)const{
        return y>b.y||(y==b.y&&x>b.x);
    }
}a[1000];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++)a[i].scan();
    sort(a,a+n);
    int now=1;
    for(i=0;now&&i<n;i++){
        now--;
        now+=a[i].y;
        an+=a[i].x;
    }
    printf("%d\n",an);
    return 0;
}