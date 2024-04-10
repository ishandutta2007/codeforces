#include<bits/stdc++.h>
using namespace std;

int t,n,x;
char s[100005];
int f[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>x;
        cin>>s+1;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]+(s[i]=='0')-(s[i]=='1');
        }
        cerr<<"ans: ";
        if(f[n]!=0){
            int ans=0;
            for(int i=1;i<=n;i++){
                ans+=((x-f[i])/f[n]>=0)&&((f[i]-x)%f[n]==0);
            }
            cout<<ans+(x==0)<<endl;
        }else{
            bool fl=false;
            for(int i=1;i<=n;i++){
                if(f[i]==x){
                    fl=true;
                    break;
                }
            }
            if(fl){
                cout<<-1<<endl;
            }else{
                cout<<0+(x==0)<<endl;
            }
        }
    }

    return 0;
}