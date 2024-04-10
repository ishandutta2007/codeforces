#include<bits/stdc++.h>
using namespace std;

int n;
long long mn;
int q[200005];
long long p[200005];
bool b[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    mn=0;
    for(int i=1;i<n;i++){
        cin>>q[i];
        p[i+1]=p[i]+q[i];
        mn=min(p[i+1],mn);
    }
    for(int i=1;i<=n;i++){
        if(p[i]+1-mn>0&&p[i]+1-mn<=n)b[p[i]+1-mn]=true;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<p[i]+1-mn<<' ';
    }
    
    return 0;
}