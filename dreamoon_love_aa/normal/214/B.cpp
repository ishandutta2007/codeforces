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
int d[10];
void print(){
    int i,j;
    for(i=1;i<10;i++)
        if(d[i]>0)break;
    if(i==10){
        puts("0");
        return;
    }
    for(i=9;i>=0;i--){
        for(j=0;j<d[i];j++)printf("%d",i);
    }
    puts("0");
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        d[k]++;
    }
    if(d[0]==0){
        puts("-1");
        return 0;
    }
    d[0]--;
    k=0;
    for(i=0;i<10;i++)k+=i*d[i];
    if(k%3==0){
        print();
        return 0;
    }
    else{
        for(i=1;i<=9;i++){
            if((k-i)%3==0&&d[i]>0){
                d[i]--;
                print();
                return 0;
            }
        }
        for(i=1;i<=9;i++)
            for(j=1;j<=i;j++){
                if(i==j){
                    if(d[i]>=2&&(k-i-j)%3==0){
                        d[i]-=2;
                        print();
                        return 0;
                    }
                }
                else if(d[i]>0&&d[j]>0&&(k-i-j)%3==0){
                    d[i]--;
                    d[j]--;
                    print();
                    return 0;
                }
            }
        int K=k;
        for(i=1;i<=9;i++)
            for(j=1;j<=i;j++){
                for(k=1;k<=j;k++){
                    d[i]--;
                    d[j]--;
                    d[k]--;
                    if(d[i]<0||d[j]<0||d[k]<0){
                        d[i]++;
                        d[j]++;
                        d[k]++;
                        continue;
                    }
                    if((K-i-j-k)%3==0){
                        print();
                        return 0;
                    }
                }
            }
    }
    puts("-1");
    return 0;
}