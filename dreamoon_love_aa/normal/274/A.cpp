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
#define SIZE 100000
struct data{
    int x,y;
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
}a[SIZE];
bool used[SIZE];
int main(){
    int i,j,k,n;
    cin>>n>>k;
    if(k==1){
        printf("%d\n",n);
        return 0;
    }
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int cnt=0;
        while(x%k==0){
            x/=k;
            cnt++;
        }
        a[i]=(data){x,cnt};
    }
    sort(a,a+n);
    int an=0;
    for(i=0;i<n;i++){
        if(!i||a[i].x!=a[i-1].x){
            an++;
            used[i]=1;
        }
        else{
            if(a[i].y!=a[i-1].y+1||used[i-1]!=1){
                an++;
                used[i]=1;
            }
        }
    }
    cout<<an<<endl;
    return 0;
}