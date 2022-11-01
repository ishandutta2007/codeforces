#include<bits/stdc++.h>
using namespace std;

int n;
int z[2000005];
string ans,t,s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        t.clear();
        cin>>t;
        s.clear();
        s=t+'$'+ans.substr(ans.size()-min(ans.size(),t.size()));
        int l=-1,r=-1;
        z[0]=s.size();
        for(int i=1;i<s.size();i++){
            z[i]=0;
            if(i>r){
                l=i;
                r=i;
                while(r<s.size()&&s[r-i]==s[r])r++;
                r--;
                z[i]=r-l+1;
            }else{
                int k=i-l;
                if(z[k]<r-i+1){
                    z[i]=z[k];
                }else{
                    z[i]=z[k];
                    l=i;
                    while(r<s.size()&&s[r-i]==s[r])r++;
                    r--;
                    z[i]=r-l+1;
                }
            }
        }
        int mx=0;
        for(int i=t.size()+1;i<s.size();i++){
            if(i+z[i]==s.size()){
                mx=z[i];
                break;
            }
        }
        ans+=t.substr(mx);
    }
    cout<<ans<<endl;

    return 0;
}