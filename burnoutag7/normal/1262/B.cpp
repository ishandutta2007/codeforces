#include<bits/stdc++.h>
using namespace std;

int t,n,cnt;
bool kimo;
bool u[100005];
int p[100005];
int q[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        memset(u,false,n+1);
        cnt=1;kimo=false;
        for(int i=1;i<=n;i++){
            cin>>q[i];
            if(q[i]>q[i-1]){
                if(u[q[i]])kimo=true;
                u[q[i]]=true;
                p[i]=q[i];
            }else{
                while(u[cnt]&&cnt<=q[i])cnt++;
                u[cnt]=true;
                p[i]=cnt++;
                if(cnt>q[i]+1)kimo=true;
            }
        }
        if(!kimo){
            for(int i=1;i<=n;i++){
                cout<<p[i]<<' ';
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}