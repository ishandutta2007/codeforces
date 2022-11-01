#include<bits/stdc++.h>
using namespace std;

int n;
int d[25][25];
string a,b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        bool f=false;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                f=true;
                break;
            }else{
                if(a[i]!=b[i])d[a[i]-'a'][b[i]-'a']=1;
            }
        }
        if(f){
            cout<<-1<<'\n';
            continue;
        }
        int ans=0;
        for(int i=0;i<20;i++){
            for(int j=i+1;j<20;j++){
                if(d[i][j]){
                    ans++;
                    for(int k=j+1;k<20;k++)d[j][k]|=d[i][k];
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}