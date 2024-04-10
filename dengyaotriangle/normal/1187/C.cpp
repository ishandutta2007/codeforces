#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

struct seg{
    int t,l,r;
};

int n,m;
seg s[maxn];
bool inc[maxn];
int r[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>s[i].t>>s[i].l>>s[i].r;
        if(s[i].t){
            for(int j=s[i].l+1;j<=s[i].r;j++) inc[j]=1;
        }
    }   
    for(int i=1;i<=m;i++){
        if(s[i].t==0){
            bool ok=1;
            for(int j=s[i].l+1;j<=s[i].r;j++)if(!inc[j]) ok=0;
            if(ok){
                cout<<"NO";
                return 0;
            }
        }
    }
    r[1]=10000;     
    for(int i=2;i<=n;i++){
        if(inc[i]){
            r[i]=r[i-1];
        }else r[i]=r[i-1]-1;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<r[i]<<' ';
    return 0;
}//lmy//ak//ioi//