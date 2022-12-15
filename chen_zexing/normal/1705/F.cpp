#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
char t[1005],tf[1005],temp[1005];
char ans[1005];
int baset,basetf,n;
int query(int type){
    if(type==0) for(int i=1;i<=n;i++) printf("%c",t[i]);
    else if(type==1) for(int i=1;i<=n;i++) printf("%c",tf[i]);
    else for(int i=1;i<=n;i++) printf("%c",temp[i]);
    puts("");
    fflush(stdout);
    int t;
    scanf("%d",&t);
    if(t==n) exit(0);
    return t;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) t[i]='T',tf[i]=i%2?'T':'F',ans[i]='?';
        baset=query(0),basetf=query(1);
        for(int i=1;i<=n/3;i++){
            for(int j=1;j<=n;j++){
                if(j==i*2-1||j==i*2) temp[j]='F';
                else temp[j]='T';
            }
            int t=query(2);
            if(t==baset-2) ans[i*2-1]=ans[i*2]='T';
            else if(t==baset+2) ans[i*2-1]=ans[i*2]='F';
            else{
                for(int j=1;j<=n;j++){
                    if(j<=n/3*2){
                        if(j==i*2-1) temp[j]='F';
                        else if(j==i*2) temp[j]='T';
                        else temp[j]=tf[j];
                    }
                    else{
                        if(j==i+n/3*2) temp[j]=tf[j]=='T'?'F':'T';
                        else temp[j]=tf[j];
                    }
                }
                t=query(2);
                if(t-basetf==-3) ans[i*2-1]='T',ans[i*2]='F',ans[i+n/3*2]=tf[i+n/3*2];
                else if(t-basetf==-1) ans[i*2-1]='T',ans[i*2]='F',ans[i+n/3*2]=tf[i+n/3*2]=='T'?'F':'T';
                else if(t-basetf==1) ans[i*2-1]='F',ans[i*2]='T',ans[i+n/3*2]=tf[i+n/3*2];
                else ans[i*2-1]='F',ans[i*2]='T',ans[i+n/3*2]=tf[i+n/3*2]=='T'?'F':'T';
            }
        }
        for(int i=1;i<=n;i++) if(ans[i]=='?'){
                for(int j=1;j<=n;j++) temp[j]=i==j?'F':'T';
                int t=query(2);
                if(t-baset<0) ans[i]='T';
                else ans[i]='F';
            }
        for(int i=1;i<=n;i++) printf("%c",ans[i]);
        puts("");
    }
    return 0;
}
//unordered_map
//cf