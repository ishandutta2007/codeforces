#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=105;

int n;
int a,b,c;
char q[maxn];
char d[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b>>c;
        cin>>q;
        int cnt=0;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            if(q[i]=='R'&&b>0){
                d[i]='P';b--;
            }else if(q[i]=='P'&&c>0){
                d[i]='S';c--;
            }else if(q[i]=='S'&&a>0){
                d[i]='R';a--;
            }
        }
        if(n-a-b-c>=(n+1)/2){
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                if(d[i])cout<<d[i];
                else if(a)cout<<'R',a--;
                else if(b)cout<<'P',b--;
                else if(c)cout<<'S',c--;
            }
            cout<<'\n';
        }else cout<<"NO\n";
    }
    return 0;
}