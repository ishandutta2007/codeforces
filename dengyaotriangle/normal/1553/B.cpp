#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        string h=s;
        reverse(h.begin(),h.end());
        bool ok=0;
        for(int i=0;i<(int)s.size();i++){
            for(int j=0;i+j<(int)s.size();j++){
                if(j>=t.size()||s[i+j]!=t[j]){
                    break;
                }
                int tl=t.size()-j-1;
                string t1=t.substr(j+1);
                string s1=h.substr(s.size()-i-j,tl);
                if(s1==t1){
                    ok=1;break;
                }
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}