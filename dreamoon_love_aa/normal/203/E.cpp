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
#define SIZE 100000
#define MAX 1000000001
using namespace std;
struct data{
    int c,f,l;
}a[SIZE];
int main(){
    int i,j,k,n,d,S,an1=0,an2=0;
    scanf("%d%d%d",&n,&d,&S);
    for(i=0;i<n;i++)scanf("%d%d%d",&a[i].c,&a[i].f,&a[i].l);
    {
        vector<int>tmp;
        for(i=0;i<n;i++){
            if(a[i].l>=d&&a[i].c==0)tmp.pb(a[i].f);
        }
        sort(tmp.begin(),tmp.end());
        int now=0,cnt=0;
        for(i=0;i<tmp.size();i++){
            if(now+tmp[i]<=S){
                cnt++;
                now+=tmp[i];
            }
            else break;
        }
        an1=cnt;an2=now;
    }
    {
        int mi=MAX;
        long long cc=0;
        vector<int>tmp;
        for(i=0;i<n;i++){
            if(a[i].c){
                cc+=a[i].c;
                if(a[i].l>=d){
                    mi=min(mi,a[i].f);
                }
            }
            else{
                if(a[i].l>=d)tmp.pb(a[i].f);
            }
        }
        bool flag=0;
        for(i=0;i<n;i++){
            if(a[i].c&&a[i].l>=d){
                if(a[i].f==mi){
                    if(!flag)flag=1;
                    else tmp.pb(a[i].f);
                }
                else{
                    tmp.pb(a[i].f);
                }
            }
        }
        sort(tmp.begin(),tmp.end());
        if(mi<=S){
            if(cc+1>=n){
                if(n>an1||(n==an1&&mi<an2)){
                    an1=n;
                    an2=mi;
                }
            }
            else{
                int need=mi;
                for(i=0;i+cc+1<n&&i<tmp.size();i++){
                    if(need+tmp[i]<=S){
                        need+=tmp[i];
                    }
                    else break;
                }
                if(i+cc+1>an1||(i+cc+1==an1&&need<an2)){
                    an1=i+cc+1;
                    an2=need;
                }
            }
        }
    }
    printf("%d %d\n",an1,an2);
    return 0;
}