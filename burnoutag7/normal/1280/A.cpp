#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;

ll t,x;
ll len;
char s[1000006];

void mkstr(){
    ll cl,cr=len,clen;
    for(int i=1;i<=x;i++){
        cl=i+1;
        clen=cr-cl+1;
        for(char ct='2';ct<=s[i];ct++){
            for(int j=cl;j<=cr;j++){
                if(j+clen<=x){
                    s[j+clen]=s[j];
                }else{
                    return;
                }
            }
            cr+=clen;
            cl+=clen;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>x;
        cin>>s+1;
        len=strlen(s+1);
        mkstr();
        for(int i=1;i<=x;i++){
            ll cl=i+1,cr=len;
            ll clen=cr-cl+1;
            len=((len+clen*(s[i]-'1'))%mod+mod)%mod;
        }
        cout<<len<<endl;
    }

    return 0;
}