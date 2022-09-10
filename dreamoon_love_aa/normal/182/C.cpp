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
struct data{
    int v,pos;
    data(int _v,int _pos){v=_v,pos=_pos;}
    bool operator<(const data& b)const{return v<b.v||(v==b.v&&pos<b.pos);}
};
set<data>low,high;
int n,len,k,a[100010];
void go(){
    long long now=0;
    int i;
    high.clear();
    low.clear();
    for(i=0;i<len;i++){
        now+=a[i];
        if(a[i]<0){
            if(high.size()<k){
                now-=a[i]*2;
                high.insert(data(-a[i],i));
            }
            else{
                set<data>::iterator it=high.begin();
                if(-a[i]>it->v){
                    low.insert(*it);
                    now-=it->v*2;
                    high.erase(it);
                    high.insert(data(-a[i],i));
                    now-=a[i]*2;
                }
                else{
                    low.insert(data(-a[i],i));
                }
            }
        }
    }
    an=max(an,now);
    for(i=len;i<n;i++){
        now+=a[i];
        if(a[i]<0){
            if(high.size()<k){
                now-=a[i]*2;
                high.insert(data(-a[i],i));
            }
            else{
                set<data>::iterator it=high.begin();
                if(-a[i]>it->v){
                    low.insert(*it);
                    now-=it->v*2;
                    high.erase(it);
                    high.insert(data(-a[i],i));
                    now-=a[i]*2;
                }
                else{
                    low.insert(data(-a[i],i));
                }
            }
        }
        if(a[i-len]>=0){
            now-=a[i-len];
        }
        else{
            if(high.count(data(-a[i-len],i-len))){
                high.erase(data(-a[i-len],i-len));
                now+=a[i-len];
                if(low.size()>0){
                    set<data>::iterator it=low.end();
                    it--;
                    high.insert(*it);
                    now+=it->v*2;
                    low.erase(it);
                }
            }
            else{
                low.erase(data(-a[i-len],i-len));
                now-=a[i-len];
            }
        }
        an=max(an,now);
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&len);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    if(k==0){
        long long now=0;
        for(i=0;i<len;i++){
            now+=a[i];
        }
        an=max(an,abs(now));
        for(i=len;i<n;i++){
            now+=a[i]-a[i-len];
            an=max(an,abs(now));
        }
        cout<<an<<endl;
        return 0;
    }
    go();
    for(i=0;i<n;i++)a[i]=-a[i];
    go();
    cout<<an<<endl;
    return 0;
}