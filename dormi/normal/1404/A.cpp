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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool work=true;
        for(int i=0;i<k;i++){
            set<char> stff;
            for(int j=i;j<n;j+=k){
                if(s[j]!='?')stff.insert(s[j]);
            }
            if(sz(stff)==2){
                printf("NO\n");
                work=false;
                break;
            }
            else if(sz(stff)==1){
                for(int j=i;j<n;j+=k){
                    s[j]=*stff.begin();
                }
            }
        }
        if(!work)continue;
        int zeros=0,ones=0,questions=0;
        for(int i=0;i<k;i++){
            if(s[i]=='?')questions++;
            else if(s[i]=='0')zeros++;
            else ones++;
        }
        if(abs(zeros-ones)>questions){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}