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
vector<int>zero,pos,neg,other;
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        if(k>0)pos.pb(k);
        else if(k<0)neg.pb(k);
        else zero.pb(k);
    }
    printf("1 %d\n",neg[0]);
    if(pos.size()>0){
        printf("1 %d\n",pos[0]);
        for(i=1;i<(int)neg.size();i++)other.pb(neg[i]);
        for(i=1;i<(int)pos.size();i++)other.pb(pos[i]);
    }
    else{
        printf("2 %d %d\n",neg[1],neg[2]);
        for(i=3;i<(int)neg.size();i++)other.pb(neg[i]);
    }
    printf("%d",(int)other.size()+(int)zero.size());
    for(i=0;i<zero.size();i++)printf(" %d",zero[i]);
    for(i=0;i<other.size();i++)printf(" %d",other[i]);
    puts("");
    return 0;
}