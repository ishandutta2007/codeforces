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
int a[SIZE];
long long an;
int main(){
    int i,j,k,b,n;
    cin>>k>>b>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    if(b==0){
        for(i=1;i<=n;i+=j){
            if(a[i]){
                j=1;
            }
            else{
                for(j=1;i+j<=n&&a[i+j]==0;j++);
                an+=(long long)j*(j+1)/2;
            }
        }
        cout<<an<<endl;
    }
    else{
        if(b==k-1){
            for(i=1;i<=n;i+=j){
                if(a[i]){
                    j=1;
                }
                else{
                    for(j=1;i+j<=n&&a[i+j]==0;j++);
                    an-=(long long)j*(j+1)/2;
                }
            }
        }
        a[0]=0;
        map<int,int>H;
        int now=0;
        for(i=0;i<=n;i++){
            now+=a[i];
            while(now>=k-1)now-=k-1;
            int tmp=(now-b+k-1)%(k-1);
            an+=H[tmp];
            H[now]++;
        }
        cout<<an<<endl;
    }
    return 0;
}