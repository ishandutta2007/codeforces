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
#define mp make_pair
#define x first 
#define y second
pair<int,int>a[3000];
int main(){
    int i,j,k,n,an=0;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=mp(x*2,y*2);
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(mp((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2)==*lower_bound(a,a+n,mp((a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2)))an++;
    cout<<an<<endl;
    return 0;
}