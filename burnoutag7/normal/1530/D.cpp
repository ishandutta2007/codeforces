#include<bits/stdc++.h>
using namespace std;

int n,a[200005],b[200005],c[200005];

void mian(){
    cin>>n;
    fill(b+1,b+1+n,0);
    fill(c+1,c+1+n,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]=i;
    }
    int k=0;
    set<int> s;
    for(int i=1;i<=n;i++)if(c[i]){
        b[c[i]]=i;
        k++;
    }else s.emplace(i);
    cout<<k<<'\n';
    int p=0;
    for(int i=1;i<=n;i++)if(!b[i]){
        p=i;
        if(s.upper_bound(i)!=s.end()){
            b[i]=*s.upper_bound(i);
            s.erase(s.upper_bound(i));
        }else{
            b[i]=*s.begin();
            s.erase(s.begin());
        }
    }
    if(p&&b[p]==p){
        for(int i=1;i<=n;i++)if(i!=p&&a[i]==a[p]){
            swap(b[i],b[p]);
            break;
        }
    }
    for(int i=1;i<=n;i++)assert(b[i]!=i);
    for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}