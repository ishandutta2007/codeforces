#include<bits/stdc++.h>
using namespace std;

int n,mxa,s,a[2005],mf[2005],mg[2005];

int dis(int x,int y){
    return min(abs(x-y),n-abs(x-y));
}

int cdis(int x,int y){
    static int tmp;
    if((tmp=y-x)<0)tmp+=n;
    return tmp;
}

int g(int x);

int f(int x){
    int &res=mf[x];
    if(res!=0x3f3f3f3f)return res;
    for(int d=-1;d<=1;d+=2){
        int y=-1;
        for(int i=1;y==-1&&i<n;i++){
            int nx=(x+i*d+n)%n;
            if(a[nx]==a[x])y=nx;
        }
        if(y==-1)res=min(res,g(x));
        else res=min(res,g(y)+(d==1?cdis(y,x):cdis(x,y)));
    }
    return res;
}

int g(int x){
    int &res=mg[x];
    if(res!=0x3f3f3f3f)return res;
    if(a[x]==mxa)return res=0;
    for(int i=0;i<n;i++)if(a[i]==a[x]+1)res=min(res,f(i)+dis(x,i));
    return res;
}

void pg(int x);

void pf(int x){
    int &res=mf[x];
    for(int d=-1;d<=1;d+=2){
        int y=-1;
        for(int i=1;y==-1&&i<n;i++){
            int nx=(x+i*d+n)%n;
            if(a[nx]==a[x])y=nx;
        }
        if(y==-1){
            if(res==g(x))return pg(x);
        }else if(res==g(y)+(d==1?cdis(y,x):cdis(x,y))){
            int pd=0;
            for(int i=1;i<n;i++){
                int nx=(x-i*d+n)%n;
                pd++;
                if(a[nx]==a[x]){
                    cout<<(d==1?'-':'+')<<pd<<'\n';
                    pd=0;
                }
            }
            return pg(y);
        }
    }
}

void pg(int x){
    int &res=mg[x];
    if(a[x]==mxa)return;
    for(int i=0;i<n;i++)if(a[i]==a[x]+1&&res==f(i)+dis(x,i)){
        int d=cdis(x,i);
        cout<<(d<=n-d?'+':'-')<<dis(x,i)<<'\n';
        return pf(i);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(mf,0x3f,sizeof(mf));
    memset(mg,0x3f,sizeof(mg));
    cin>>n>>s;
    s--;
    vector<int> dsc;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dsc.emplace_back(a[i]);
    }
    sort(dsc.begin(),dsc.end());
    dsc.erase(unique(dsc.begin(),dsc.end()),dsc.end());
    mxa=dsc.size()-1;
    for(int i=0;i<n;i++){
        a[i]=lower_bound(dsc.begin(),dsc.end(),a[i])-dsc.begin();
    }
    int ans=1e9;
    for(int i=0;i<n;i++)if(!a[i]){
        ans=min(ans,f(i)+dis(s,i));
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++)if(!a[i]&&ans==f(i)+dis(s,i)){
        int d=cdis(s,i);
        cout<<(d<=n-d?'+':'-')<<dis(s,i)<<'\n';
        pf(i);
        break;
    }

    return 0;
}