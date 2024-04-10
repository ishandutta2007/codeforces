#include <bits/stdc++.h>
#define int long long
constexpr int MAXN=500;
int left[MAXN],right[MAXN];
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin>>tc;
    for(int ct=0;ct<tc;++ct){
        std::string s,t;
        std::cin>>s>>t;
        for(int i=0;i<s.size();++i){
            left[i]=0;
            for(int j=i;j<s.size()&&left[i]<t.size();++j){
                if(s[j]==t[left[i]])++left[i];
                else break;
            }
            right[i]=0;
            for(int j=i;j<s.size()&&right[i]<t.size();++j){
                if(s[j]==t[t.size()-1-right[i]])++right[i];
                else break;
            }
        }
        int i;
        for(i=0;i<s.size();++i){
            int j;
            for(j=0;j<t.size()&&i+j<s.size();++j){
                int eff=i+1-static_cast<int>(t.size())+2*j;
                if(eff<0)continue;
                if(left[i]>j&&right[eff]>static_cast<int>(t.size())-1-j){
                    std::cout<<"YES\n";
                    break;
                }
            }
            if(j<t.size()&&i+j<s.size())break;
        }
        if(i>=s.size()){
            std::cout<<"NO\n";
        }
    }
}