#include<bits/stdc++.h>
using namespace std;

string s,t;
int Z[15005];
int ans;

void Zalgo(const string & S){
    int l=-1,r=-1;
    Z[0]=S.size();
    for(int i=1;i<S.size();i++){
        Z[i]=0;
        if(i>r){
            l=i;
            r=i;
            while(r<S.size()&&S[r-i]==S[r])r++;
            r--;
            Z[i]=r-l+1;
        }else{
            int k=i-l;
            if(Z[k]<r-i+1){
                Z[i]=Z[k];
            }else{
                Z[i]=Z[k];
                l=i;
                while(r<S.size()&&S[r-i]==S[r])r++;
                r--;
                Z[i]=r-l+1;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ans=1e9;
    cin>>s;
    cin>>t;
    for(int i=0;i<s.size();i++){
        string str=s.substr(i,s.size()-i)+'$'+s+'#'+t;
        Zalgo(str);
        Z[s.size()+1]=0;
        int big=0;
        int sBig=0;
        bool good=false;
        int pos=-1;
        for(int i=1;i<str.size();i++){
            if(Z[i]>big){
                sBig=big;
                big=Z[i];
                pos=i;
                good=1;
            }else if(Z[i]==big){
                good=0;
            }else if(Z[i]>sBig){
                sBig=Z[i];
            }
        }
        if(good&&pos>2*s.size()-i+1){
            ans=min(ans,sBig+1);
        }
    }
    if(ans==1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

    return 0;
}