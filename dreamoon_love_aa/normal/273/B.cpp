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
long long m;
#define SIZE 200000
struct data{
    int x,y;
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
}a[SIZE];
int main(){
    int i,j,k,n;
    long long res=1;
    cin>>n;
    for(i=0;i<n;i++){cin>>a[i].x;a[i].y=i+1;}
    for(i=0;i<n;i++){cin>>a[i+n].x;a[i+n].y=i+1;}
    cin>>m;
    sort(a,a+n+n);
    for(i=0;i<n+n;i=j){
        int cnt=0;
        for(j=i+1;j<n+n&&a[i].x==a[j].x;j++){
            if(j!=i&&a[j].y==a[j-1].y)cnt++;
        }
        int num=j-i;
        for(k=1;k<=num;k++){
            if(k%2==0&&cnt>0){
                res*=k/2;
                cnt--;
            }
            else res*=k;
            res%=m;
        }
    }
    cout<<res<<endl;
    return 0;
}