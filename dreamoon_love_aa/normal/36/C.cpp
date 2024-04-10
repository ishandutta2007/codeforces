#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define SIZE 3000
using namespace std;
int h[SIZE],r[SIZE],R[SIZE];
double bb[SIZE];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,j;
    double an=0,now;
    scanf("%d",&n);
    now=0;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&h[i],&r[i],&R[i]);
        bb[i]=0;
        for(j=0;j<i;j++){
            if(r[i]>=R[j])bb[i]=max(bb[i],bb[j]+h[j]);
            else{
                bb[i]=max(bb[i],bb[j]);
                if(h[i]*(R[j]-r[j])<h[j]*(R[i]-r[i])){
                    if(R[i]>=r[j]){
                        if(R[i]<=R[j]){
                            bb[i]=max(bb[i],bb[j]+1.*h[j]*(R[i]-r[j])/(R[j]-r[j])-h[i]);
                        }
                        else{
                            bb[i]=max(bb[i],bb[j]+h[j]-1.*h[i]*(R[j]-r[i])/(R[i]-r[i]));
                        }
                    }
                }
                else{
                    if(r[i]>r[j]){
                        bb[i]=max(bb[i],bb[j]+1.*h[j]*(r[i]-r[j])/(R[j]-r[j]));
                    }
                }
            }
        }
        an=max(an,bb[i]+h[i]);
    }
    printf("%.8lf\n",an);
    return 0;
}