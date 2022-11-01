#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005];
vector<int> d[10];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    for(int i=0;i<=9;i++)d[i].clear();
    for(int i=1;i<=n;i++){
        d[s[i]-'0'].emplace_back(i);
    }
    int ans=n;
    for(int i=0;i<=9;i++){
        ans=min(ans,n-(int)d[i].size());
    }
    for(int a=0;a<=9;a++){
        for(int b=a+1;b<=9;b++){
            int prv=-1,l=0,r=0,cnt=0;
            while(l<d[a].size()&&r<d[b].size()){
                if(d[a][l]<d[b][r]){
                    cnt+=prv!=a;
                    prv=a;
                    l++;
                }else{
                    cnt+=prv!=b;
                    prv=b;
                    r++;
                }
            }
            if(l<d[a].size()){
                cnt+=prv!=a;
            }
            if(r<d[b].size()){
                cnt+=prv!=b;
            }
            ans=min(ans,n-(cnt-(cnt&1)));
        }
    }
    cout<<ans<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}