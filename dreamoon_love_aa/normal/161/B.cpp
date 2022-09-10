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
struct data{
    long long v;
    int No;
    bool operator<(const data& b)const{return v>b.v;}
};
vector<data>d[3];
void print(long long v){
    if(v%2==0)cout<<v/2<<".0"<<endl;
    else cout<<v/2<<".5"<<endl;
}
int main(){
    int i,j,k,n;
    long long sum=0,mi=1ll<<50;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        x<<=1;
        mi=min(x,mi);
        sum+=x;
        d[y].pb((data){x,i});
    }
    sort(d[0].begin(),d[0].end());
    sort(d[1].begin(),d[1].end());
    if(k>d[1].size()){
        for(i=0;i<d[1].size();i++)sum-=d[1][i].v/2;
        print(sum);
        for(i=0;i<d[1].size();i++)printf("1 %d\n",d[1][i].No);
        for(i=0;i+d[1].size()+1<k;i++)printf("1 %d\n",d[2][i].No);
        printf("%d",d[2].size()-i);
        for(;i<d[2].size();i++)printf(" %d",d[2][i].No);
        puts("");
    }
    else{
        for(i=0;i<k-1;i++)sum-=d[1][i].v/2;
        sum-=mi/2;
        print(sum);
        for(i=0;i<k-1;i++)printf("1 %d\n",d[1][i].No);
        printf("%d",n-k+1);
        for(;i<d[1].size();i++)printf(" %d",d[1][i].No);
        for(i=0;i<d[2].size();i++)printf(" %d",d[2][i].No);
        puts("");
    }
    return 0;
}