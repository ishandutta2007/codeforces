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
int n;
#define SIZE 100010
long long a[SIZE],an;
void go(int n,int x){
    int i,j,k;
    for(i=0;i<n;i++){
        if((a[i]>>x)&1){
            long long now=0;
            for(j=i+1;j<n;j++){
                if(!((a[j]>>x)&1)){
                    now=max(now,a[j]);
                    an=max(an,a[i]^now);
                }
                else break;
            }
            now=0;
            for(j=i-1;j>=0;j--){
                if(!((a[j]>>x)&1)){
                    now=max(now,a[j]);
                    an=max(an,a[i]^now);
                }
                else break;
            }
        }
    }
    cout<<an<<endl;
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=32;i>=0;i--){
        int one=0,zero=0;
        for(j=0;j<n;j++){
            if((a[j]>>i)&1)one++;
            else zero++;
        }
        if(one&&zero){
            go(n,i);
            return 0;
        }
    }
    return 0;
}