#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[100005];
int dq[300005];
int pos,hd,tl,cnt;
int qs[200005][2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    hd=1;tl=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[pos])pos=i;
        dq[i]=a[i];
    }
    while(dq[hd]!=a[pos]){
        qs[++cnt][0]=dq[hd];
        qs[cnt][1]=dq[hd+1];
        if(dq[hd]>dq[hd+1]){
            dq[++tl]=dq[hd+1];
            dq[hd+1]=dq[hd];
            hd++;
        }else{
            dq[++tl]=dq[hd];
            hd++;
        }
    }
    for(int i=1;i<=q;i++){
        long long cq;//CQCQCQ
        cin>>cq;
        if(cq<=cnt){
            cout<<qs[cq][0]<<' '<<qs[cq][1]<<endl;
        }else{
            long long r=(cq-cnt-1)%(n-1)+1;
            cout<<a[pos]<<' '<<dq[hd+r]<<endl;
        }
    }

    return 0;
}