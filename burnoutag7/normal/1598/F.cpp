#include<bits/stdc++.h>
using namespace std;

struct node{
    int n,h,mn,cnt;
    string s;
    vector<int> pmn,pcnt;
    node(string st=""){
        s=st;
        n=s.size();
        h=mn=cnt=0;
        pmn.resize(n,0);
        pcnt.resize(n,0);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            h+=(c=='(')-(c==')');
            if(mn>h)mn=h,cnt=1;
            else if(mn==h)cnt++;
            pmn[i]=mn;
            pcnt[i]=cnt;
        }
    }
    int preh(int ph){
        int l=0,r=n-1,m,res=-1;
        while(l<=r){
            m=(l+r)/2;
            if(pmn[m]+ph>=0){
                res=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        if(res==-1)return -1;
        return pcnt[res];
    }
};

int n,f[1<<20],g[1<<20];
node a[25];

int geth(int s){
    int h=0;
    for(int i=0;i<n;i++)if(s>>i&1)h+=a[i].h;
    return h;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i]=node(s);
    }
    for(int s=1;s<1<<n;s++){
        f[s]=g[s]=-1e9;
        for(int i=0;i<n;i++)if(s>>i&1){
            int t=s^1<<i,th=geth(t);
            if(a[i].mn+th>=0)f[s]=max(f[s],(a[i].mn+th==0?a[i].cnt:0)+f[t]);
            else g[s]=max(g[s],a[i].preh(th)+f[t]);
        }
    }
    cout<<max(*max_element(f,f+(1<<n)),*max_element(g,g+(1<<n)));

    return 0;
}