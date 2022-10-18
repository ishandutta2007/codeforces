#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

struct s{
    int i,v;
};

int n;
s c[maxn];
int a[maxn];
int dif[maxn];
int pfx[maxn],sfx[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i].v;
    for(int i=1;i<=n;i++)c[i].i=i;
    sort(c+1,c+1+n,[](s a,s b){return a.v<b.v;});
    for(int i=1;i<=n;i++) a[i]=c[i].v;
    pfx[2]=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]==pfx[i-1]) pfx[i]=pfx[i-1];
        else pfx[i]=-1;
    }
    sfx[n-1]=a[n]-a[n-1];
    for(int i=n-2;i>=1;i--){
        if(a[i+1]-a[i]==sfx[i+1]) sfx[i]=sfx[i+1];
        else sfx[i]=-1;
    }
    if(sfx[2]!=-1){
        cout<<c[1].i;
        return 0;
    }
    if(pfx[n-1]!=-1){
        cout<<c[n].i;
        return 0;
    }
    if(sfx[3]!=-1&&a[3]-a[1]==sfx[3]){
        cout<<c[2].i;
        return 0;
    }
    if(pfx[n-2]!=-1&&a[n]-a[n-2]==pfx[n-2]){
        cout<<c[n-1].i;
        return 0;
    }
    for(int i=3;i<=n-2;i++){
        if(pfx[i-1]==sfx[i+1]&&pfx[i-1]!=-1&&a[i+1]-a[i-1]==pfx[i-1]){
            cout<<c[i].i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}