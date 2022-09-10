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
#define SIZE 1024
int used_c[SIZE],used_r[SIZE],pos_r[SIZE],now_r[SIZE],pos_c[SIZE],now_c[SIZE],rn[SIZE],n;
vector<int>row[SIZE];
vector<int>an;
void add(int x,int y,int z){
    an.pb(x);
    an.pb(y);
    an.pb(z);
}
void erase(int x){
    int i,j;
    used_c[x]=1;
    for(i=1;i<=n;i++){
        if(used_r[i])continue;
        for(j=0;j<row[i].size();j++)
            if(row[i][j]==x)rn[i]--;
    }
}
int main(){
    int i,j,k,now;
    cin>>n;
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        row[x].pb(y);
        rn[x]++;
    }
    for(i=1;i<=n;i++){
        now_r[i]=now_c[i]=i;
        pos_r[i]=pos_c[i]=i;
    }
    for(i=1,now=1;i<=n;i++){
        int mi=1024,No;
        for(j=1;j<=n;j++){
            if(used_r[j])continue;
            if(rn[j]<mi){
                mi=rn[j];
                No=j;
            }
        }
        used_r[No]=1;
        if(i!=pos_r[No]){
            add(1,pos_r[No],i);
            pos_r[now_r[i]]=pos_r[No];
            now_r[pos_r[No]]=now_r[i];
        }
        for(j=0;j<row[No].size();j++){
            if(used_c[row[No][j]])continue;
            erase(row[No][j]);
            if(pos_c[row[No][j]]!=now){
                add(2,now,pos_c[row[No][j]]);
                pos_c[now_c[now]]=pos_c[row[No][j]];
                now_c[pos_c[row[No][j]]]=now_c[now];
            }
            now++;
        }
    }
    printf("%d\n",(int)an.size()/3);
    for(i=0;i<an.size();i+=3){
        printf("%d %d %d\n",an[i],an[i+1],an[i+2]);
    }
    return 0;
}