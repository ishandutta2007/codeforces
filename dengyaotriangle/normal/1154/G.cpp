#include<bits/stdc++.h>

using namespace std;

const int maxn=1000006;
const int maxr=10000007;

int a[maxn];
int n;
int id[2][maxr];
int cn[maxr];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(cn[a[i]]==0){
            cn[a[i]]++;
            id[0][a[i]]=i;
        }else if(cn[a[i]]==1){
            cn[a[i]]++;
            id[1][a[i]]=i;
        }
    }
    long long ans=0x3fff3fff3fff3fff;
    int c1,c2;
    for(int l=1;l<maxr;l++){
        long long a1=-1,a2=-1;
        for(int i=l;i<maxr;i+=l){
            if(cn[i]==1){
                if(a1==-1){
                    a1=i;
                }else if(a2==-1){
                    a2=i;
                    break;
                }
            }else if(cn[i]>1){
                if(a1==-1){
                    a1=a2=i;
                    break;
                }else{
                    a2=i;
                    break;
                }
            }
        }
        if(a2!=-1){
            long long c=(a1*a2)/l;
            if(c<ans){
                ans=c;
                c1=id[0][a1],c2=id[a1==a2][a2];
            }
            ans=min(ans,(a1*a2)/l);
        }
    }
    if(c1>c2) swap(c1,c2);
    cout<<c1<<' '<<c2;
    return 0;
}