#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;
const int maxl=20;

int n;
int a[maxn<<2];
int st[maxn<<2][maxl];
int lg2[maxn<<2];

inline int qry(int l,int r){
    //cerr<<l<<r;
    int sz=lg2[r-l+1];
    return max(st[l][sz],st[r-(1<<sz)+1][sz]);
}

int main(){
    lg2[1]=0;
    for(int i=2;i<maxn+maxn+maxn+maxn;i++)lg2[i]=lg2[i>>1]+1;
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i+n]=a[i+n+n]=a[i+n+n+n]=a[i];
    for(int i=1;i<=n+n+n+n;i++)st[i][0]=a[i];
    for(int i=1;i<maxl;i++){
        for(int j=1;j<=n+n+n+n;j++){
            if(j+(1<<i)-1<=n+n+n+n)st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
        }
    }
    int cp=1;
    for(int i=1;i<=n;i++){
        while((cp<i)||(cp<=n+n+n+n&&qry(i,cp)<=a[cp+1]+a[cp+1]))cp++;
        if(cp>n+n+n)cout<<-1<<' ';
        else cout<<cp-i+1<<' ';
    }
    return 0;
}