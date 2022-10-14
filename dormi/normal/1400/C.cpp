#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        string ans;
        int x;
        cin>>s>>x;
        ans.resize(sz(s),'2');
        int le=min(x-1,sz(s)-x-1);
        int ri=max(sz(s)-x,x);
        assert(le<ri);
        for(int i=0;i<=le;i++)ans[i+x]=s[i];
        bool imp=false;
        for(int i=sz(s)-1;i>=ri;i--){
            if(ans[i-x]!=s[i]&&ans[i-x]!='2'){
                printf("-1\n");
                imp=true;
                break;
            }
            ans[i-x]=s[i];
        }
        if(imp)continue;
        for(int i=le+1;i<ri;i++){
            if(i-x<0){
                if(s[i]!='0'){
                    printf("-1\n");
                    imp=true;
                    break;
                }
            }
            else{
                if(s[i]=='0'){
                    if(ans[i-x]=='1'||ans[i+x]=='1'){
                        printf("-1\n");
                        imp=true;
                        break;
                    }
                    ans[i-x]='0',ans[i+x]='0';
                }
                else{
                    if(ans[i-x]!='0'){
                        ans[i-x]='1';
                    }
                    else if(ans[i+x]!='0'){
                        ans[i+x]='1';
                    }
                    else{
                        printf("-1\n");
                        imp=true;
                        break;
                    }
                }
            }
        }
        if(imp)continue;
        for(int i=0;i<sz(s);i++){
            if(ans[i]=='2')printf("0");
            else printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}