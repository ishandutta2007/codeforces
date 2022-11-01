#include<bits/stdc++.h>
using namespace std;

string s,ans;
int l,r;
char pr;

bool cmp(char a,char b){
    return a>b;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    l=0;r=s.size();
    pr=0;
    while(l<r){
        char t[15];
        int cnt=0;
        for(int i=0;i<r;i++){
            t[cnt++]=s[i];
        }
        sort(t,t+cnt,cmp);
        bool f=false;
        for(int i=0;i<cnt;i++){
            int occ=0,fst=-1,snd=-1;
            for(int j=l;j<r;j++){
                if(s[j]==t[i]){
                    occ++;
                }
            }
            for(int j=l;j<r;j++){
                if(s[j]==t[i]&&fst==-1){
                    fst=j;
                }
                if(s[j]==t[i]){
                    snd=j;
                }
            }
            if(occ>=2&&s[fst]>=pr){
                l=fst+1;
                r=snd;
                ans+=s[fst];
                pr=s[fst];
                f=true;
                break;
            }else{
                if(occ==1&&s[fst]>=pr){
                    cout<<ans;
                    reverse(ans.begin(),ans.end());
                    cout<<s[fst];
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
        if(!f){
            break;
        }
    }
    cout<<ans;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;

    return 0;
}