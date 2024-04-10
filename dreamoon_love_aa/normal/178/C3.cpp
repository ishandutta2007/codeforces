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
#define SIZE 200001
map<int,int>H;
bool used[SIZE];
int real[SIZE],d[SIZE],h;
void insert(int x,int v){
    while(x<=h){
        d[x]+=v;
        x+=x&-x;
    }
}
int qq(int x){
    int res=0;
    while(x>0){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
int main(){
    int i,j,k,n,m,gg;
    long long an=0;
    scanf("%d%d%d",&h,&m,&n);
    gg=h/__gcd(m,h);
    for(i=0,k=1;i<h;i++){
        if(!used[i]){
            j=i;
            while(!used[j]){
                used[j]=1;
                real[j]=k++;
                j=(j+m)%h;
            }
        }
    }
    //for(i=0;i<h;i++)printf("%d ",real[i]);
    //puts("");
    while(n--){
        int id,hh;
        char c[4];
        scanf("%s",c);
        if(c[0]=='+'){
            scanf("%d%d",&id,&hh);
            hh=real[hh];
            int bb,uu;
            bb=(hh-1)/gg*gg+1;
            uu=bb+gg-1;
            if(qq(uu)-qq(hh-1)==uu-hh+1){
                an+=uu-hh;
                int mm,ll=bb,rr=hh-1,base=qq(bb-1);
                while(ll<rr){
                    mm=(ll+rr)>>1;
                    if(qq(mm)-base!=mm-bb+1)rr=mm;
                    else ll=mm+1;
                }
                hh=ll;
                an+=hh-bb+1;
            }
            else{
                int mm,ll=hh,rr=uu,base=qq(hh-1);
                while(ll<rr){
                    mm=(ll+rr)>>1;
                    if(qq(mm)-base!=mm-hh+1)rr=mm;
                    else ll=mm+1;
                }
                an+=ll-hh;
                hh=ll;
            }
            insert(hh,1);
            H[id]=hh;
        }
        else{
            scanf("%d",&id);
            insert(H[id],-1);
            H.erase(id);
        }
    }
    cout<<an<<endl;
    return 0;
}