#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;
int n;
inline void output(int l,int r,int t){
    if(r-l+1==t*2){
        for(int i=l;i<l+t;i++) printf("%d %d\n",i,i+t);
        return;
    }
    else{
        int p=l;
        while(p<=r){
            for(int i=p;i<p+t;i++) printf("%d %d\n",i,i+t);
            p+=2*t;
        }
        output(l,r,t*2);
        return;
    }
}
int main() {
    cin>>n;
    if(n==1){
        printf("0\n");
        return 0;
    }
    int t=0;
    while(pow(2,t)<=n) t++;
    t--;
    cout<<pow(2,t)*t<<endl;
    output(1,pow(2,t),1);
    output(n-pow(2,t)+1,n,1);
    return 0;
}