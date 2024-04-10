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
const double eps=1e-9;
int used[2][110],tt;
struct data{
    double ll,rr;
    int p;
    data(double _ll,double _rr,int _p){ll=_ll,rr=_rr;p=_p;}
    bool operator<(const data& b)const{return ll<b.ll;}
};
vector<data>T,F;
int kk;
int find(vector<data>&X,double v,int uu[]){
    int id=lower_bound(X.begin(),X.end(),data(v+1e-9,0,0))-X.begin();
    id--;
    if(id>=0&&id<X.size()&&uu[id]!=tt&&X[id].ll<=v+eps&&X[id].rr+eps>=v){
        uu[id]=tt;
        return X[id].p;
    }
    return -1;
}
int main(){
    int i,j,k,n,hl,hr;
    scanf("%d%d%d",&hl,&hr,&n);
    for(i=0;i<n;i++){
        int p,ll,rr;
        char c[4];
        scanf("%d%s%d%d",&p,c,&ll,&rr);
        if(c[0]=='T')T.pb(data(ll,rr,p));
        else F.pb(data(ll,rr,p));
    }
    sort(T.begin(),T.end());
    sort(F.begin(),F.end());
    int an=0;
    for(k=-205;k<=205;k++){
        if(!k)continue;
        tt++;
        if(k<0){
            int yr,now=0;
            if(k%2==0)yr=k*100+hr;
            else yr=k*100+100-hr;
            for(i=0;i<-k;i++){
                double xx=100000.*(hl+i*100)/(hl-yr);
                kk=k;
                //if(k==-3)printf("[%d,%.4lf]\n",yr,xx);
                int tmp;
                if(i&1)tmp=find(T,xx,used[0]);
                else tmp=find(F,xx,used[1]);
                //if(k==-3)printf("{%d}\n",tmp);
                if(tmp<0)break;
                now+=tmp;
            }
            if(i>=-k)an=max(an,now);
        }
        else{
            int yr,now=0;
            if(k%2==0)yr=k*100+hr;
            else yr=k*100+100-hr;
            for(i=1;i<=k;i++){
                double xx=100000.*(i*100-hl)/(yr-hl);
                int tmp;
                if(i&1)tmp=find(T,xx,used[0]);
                else tmp=find(F,xx,used[1]);
                if(tmp<0)break;
                now+=tmp;
            }
            if(i>k)an=max(an,now);
        }
    }
    printf("%d\n",an);
    return 0;
}