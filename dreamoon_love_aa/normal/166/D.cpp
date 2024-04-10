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
long long an;
int n;
struct data{
    int c,s,No;
    bool operator<(const data& b)const{return s<b.s;}
}a[100001];
bool used[100001];
int pp[100001];
bool match(int x,int l,int d){
    if(x>=n)return 0;
    if(a[x].s!=l&&l!=a[x].s-1)return 0;
    return a[x].c<=d;
}
int search(int n,int l){
    int ll=-1,rr=n;
    while(ll<rr){
        int mid=(ll+rr)>>1;
        if(a[mid].s==l)return mid;
        if(a[mid].s<l)ll=mid+1;
        else rr=mid;
    }
    return ll;
}
vector<int>res;
void ff(int x,int y){
    an+=a[y].c;
    res.pb(x);
    res.pb(a[y].No);
    used[y]=1;
    if(pp[y]){
        int tmp=pp[y];
        pp[y]=0;
        ff(tmp,y+1);
    }
    if(y>0&&pp[y-1]){
        int tmp=pp[y-1];
        pp[y-1]=0;
        ff(tmp,y-1);
    }
}
int main(){
    int i,j,k,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].c,&a[i].s);
        a[i].No=i+1;
    }
    sort(a,a+n);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int d,l;
        scanf("%d%d",&d,&l);
        int now=search(n,l);
        //printf("[%d]\n",now);
        if(match(now,l,d)&&match(now+1,l,d)){
            if(pp[now])ff(i,now);
            else if(!used[now]&&!used[now+1])pp[now]=i;
            else if(!used[now])ff(i,now);
            else if(!used[now+1])ff(i,now+1);
        }
        else if(match(now,l,d)&&!used[now])ff(i,now);
        else if(match(now+1,l,d)&&!used[now+1])ff(i,now+1);
    }
    //printf("[%I64d]\n",an);
    for(i=0;i<n;i=j){
        int mi=1111111111,ha=0;
        for(j=i;j<n&&pp[j];j++){
            an+=a[j].c;
            if(mi>a[j].c){
                mi=a[j].c;
                ha=j;
            }
        }
        if(j==i){
            j=i+1;
            continue;
        }
        an+=a[j].c;
        if(mi>a[j].c){
            mi=a[j].c;
            ha=j;
        }
        an-=mi;
        for(k=i;k<=j;k++){
            if(k<ha){
                res.pb(pp[k]);
                res.pb(a[k].No);
            }
            else if(k>ha){
                res.pb(pp[k-1]);
                res.pb(a[k].No);
            }
        }
    }
    cout<<an<<endl;
    printf("%d\n",(int)res.size()/2);
    for(i=0;i<(int)res.size();i+=2){
        printf("%d %d\n",res[i],res[i+1]);
    }
    return 0;
}