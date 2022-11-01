#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mx2=17;

int gcd(int x,int y){
    int t;
    while(y!=0){
        t=x;
        x=y;
        y=t%y;
    }
    return x;
}

int n,q;
int a[100005];
int st[100005][mx2];
int lg2[100005];
int pw2[mx2];
map<int,int> ans;

int qry(int l,int r){
    int lg=lg2[r-l+1];
    return gcd(st[l][lg],st[r-pw2[lg]+1][lg]);
}

int find(int cl,int l,int g){
    int r=n-1,res=0,m;
    while(l<=r){
        m=(l+r)>>1;
        if(qry(cl,m)==g){
            res=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return res;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lg2[1]=0;
    for(int i=2;i<=100000;i++){
        lg2[i]=lg2[i>>1]+1;
    }
    pw2[0]=1;
    for(int i=1;i<mx2;i++){
        pw2[i]=pw2[i-1]<<1;
    }

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        st[i][0]=a[i];
    }
    for(int j=1;j<mx2;j++){
        for(int i=0;i+pw2[j]-1<n;i++){
            st[i][j]=gcd(st[i][j-1],st[i+pw2[j-1]][j-1]);
        }
    }
    for(int i=0;i<n;i++){
        int l,r=i,t=a[i];
        while(r<n){
            l=r;
            r=find(i,r,t);
            ans[t]+=r-l+1;
            r++;
            t=qry(i,r);
        }
    }
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        cout<<ans[t]<<endl;
    }

    return 0;
}