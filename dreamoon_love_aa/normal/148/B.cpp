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
int main(){
    int i,j,k,n,vp,vd,t,f,c,an=0;
    double now;
    cin>>vp>>vd>>t>>f>>c;
    if(vp>=vd){
        puts("0");
        return 0;
    }
    now+=t*vp;
    while(1){
        double tmp=1.*now/(vd-vp);
        now+=tmp*vp;
        if(now+1e-9>c)break;
        an++;
        now+=(f+1.*now/vd)*vp;
    }
    cout<<an<<endl;
    return 0;
}