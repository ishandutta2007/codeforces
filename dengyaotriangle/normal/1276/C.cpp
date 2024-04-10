#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=400005;

int n,m;
int a[maxn];
int cnt[maxn];
pair<int,int> dsc[maxn];
int mp[maxn];
pair<int,int> cs[maxn];
int sfx[maxn];
vector<int> g[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];dsc[i].first=a[i];dsc[i].second=i;}
    sort(dsc+1,dsc+1+n);
    for(int i=1;i<=n;i++){
        if(i==1||dsc[i].first!=dsc[i-1].first)m++;
        mp[m]=dsc[i].first;
        cnt[m]++;
    }
    for(int i=1;i<=m;i++){cs[i].first=cnt[i];cs[i].second=i;}
    sort(cs+1,cs+1+m);
    for(int i=1;i<=m;i++){sfx[i]=sfx[i-1]+cs[i].first;}
    int cp=0;
    int mx=0,mxi=-1;
    for(int i=1;i<=n;i++){
        while(cp+1<=m&&cs[cp+1].first<i)cp++;
        int cs=sfx[cp]/i+(m-cp);
        if(i*cs>mx&&cs>=i){
            mx=i*cs;mxi=i;
        }
    }
    int len=0;cp=mxi;int hd=mx/mxi;
    for(int i=m;i>=1;i--){
        cs[i].first=min(cs[i].first,mxi);
        while(cs[i].first){
            if(cp==mxi){
                len++;cp=0;
            }
            g[len].push_back(mp[cs[i].second]);
            cp++;
            cs[i].first--;
        }
    }
    cout<<mx<<endl;
    cout<<mxi<<' '<<hd<<endl;/*
    for(int i=0;i<mxi;i++){
        for(int j=0;j<hd;j++){
            cout<<g[j+1][i]<<' ';
        }
        cout<<'\n';
    }*/
    for(int i=0;i<mxi;i++){
        for(int j=0;j<hd;j++){
            cout<<g[((j-i)%hd+hd)%hd+1][i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}