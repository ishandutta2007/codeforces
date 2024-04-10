#include<bits/stdc++.h>
using namespace std;

int n,l[100005],r[100005],c[100005],li,ri,mi;

void mian(){
    cin>>n;
    li=ri=mi=1;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i]>>c[i];
        if(l[i]<l[li]||l[i]==l[li]&&c[i]<c[li])li=i;
        if(r[i]>r[ri]||r[i]==r[ri]&&c[i]<c[ri])ri=i;
        if(l[i]==l[li]&&r[i]==r[ri]){
            if(!(l[mi]==l[li]&&r[mi]==r[ri])||c[i]<c[mi])mi=i;
        }
        if(l[mi]==l[li]&&r[mi]==r[ri])cout<<min(c[li]+c[ri],c[mi])<<'\n';
        else cout<<c[li]+c[ri]<<'\n';
    }
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