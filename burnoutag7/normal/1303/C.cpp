#include<bits/stdc++.h>
using namespace std;

int T,n;
char s[205];
char li[205];
bool u[256];
int l,r,p;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        memset(u,0,sizeof(u));
        cin>>s+1;
        n=strlen(s+1);

        l=r=p=100;
        li[p]=s[1];
        u[s[1]]=1;
        bool good=true;

        for(int i=2;i<=n;i++){
            if(p<r&&s[i]==li[p+1]){
                p++;
                continue;
            }
            if(p>l&&s[i]==li[p-1]){
                p--;
                continue;
            }
            if(p==l){
                if(!u[s[i]]){
                    u[s[i]]=1;
                    li[--l]=s[i];
                    p--;
                }else{
                    good=false;
                    break;
                }
                continue;
            }
            if(p==r){
                if(!u[s[i]]){
                    u[s[i]]=1;
                    li[++r]=s[i];
                    p++;
                }else{
                    good=false;
                    break;
                }
                continue;
            }
            good=false;
            break;
        }

        if(!good){
            cout<<"NO\n";
            continue;
        }

        char res[30];
        int cnt=0;
        for(int i=l;i<=r;i++){
            res[cnt++]=li[i];
        }
        for(char i='a';i<='z';i++){
            if(!u[i])res[cnt++]=i;
        }
        res[cnt]='\0';
        cout<<"YES\n";
        cout<<res<<'\n';

    }

    return 0;
}