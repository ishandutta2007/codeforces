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
int a[100000],n;
bool check(){
    int i;
    for(i=1;i<n;i++)
        if(a[i]>a[i-1])break;
    if(i==n)return 0;
    for(i=1;i<n;i++)
        if(a[i]<a[i-1])break;
    if(i==n)return 0;
    return 1;
}
int main(){
    int i,j,k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=1;i<n;i++)
        if(a[i]!=a[i-1])break;
    if(i>=n){
        puts("-1");
        return 0;
    }
    if(n<=100){
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++){
                if(a[i]!=a[j]){
                    swap(a[i],a[j]);
                    if(check()){
                        printf("%d %d\n",i+1,j+1);
                        return 0;
                    }
                    swap(a[i],a[j]);
                }
            }
        puts("-1");
    }
    else{
        map<int,int>H;
        for(i=0;i<n;i++){
            H[a[i]]++;
        }
        if(H.size()==2){
            int mi=10000000;
            for(map<int,int>::iterator it=H.begin();it!=H.end();it++){
                if(it->second<mi){
                    mi=it->second;
                }
            }
            for(i=0;i<n;i++){
                if(a[i]!=a[1]){
                    swap(a[i],a[1]);
                    if(check()){
                        printf("%d %d\n",min(i,1)+1,max(i,1)+1);
                        return 0;
                    }
                    swap(a[i],a[1]);
                }
            }
        }
        else{
            map<int,int>::iterator it=H.begin();
            it++;
            int x=it->first;
            for(i=0;a[i]!=x;i++);
            if(i&&a[0]!=x)printf("%d %d\n",1,i+1);
            else if(i!=n-1&&a[n-1]!=x)printf("%d %d\n",i+1,n);
            else{
                for(j=0;a[j]==x;j++);
                printf("%d %d\n",min(i,j)+1,max(i,j)+1);
            }
        }
    }
    return 0;
}