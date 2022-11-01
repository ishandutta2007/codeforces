#include<bits/stdc++.h>
using namespace std;

int n,m;
int l[100005];
int r[100005];
int q[100005];
int add[100005][32];
int cur[32];
int pre[100005][32];
int val[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i]>>q[i];
        for(int j=0;j<31;j++){
            if(q[i]>>j&1){
                add[l[i]][j]++;
                add[r[i]+1][j]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<31;j++){
            cur[j]+=add[i][j];
            if(cur[j])val[i]|=1<<j;
            pre[i][j]=pre[i-1][j]+(cur[j]>0);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<31;j++){
            if(pre[r[i]][j]-pre[l[i]-1][j]==r[i]-l[i]+1&&!(q[i]>>j&1)){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        cout<<val[i]<<' ';
    }
    cout<<endl;

    return 0;
}