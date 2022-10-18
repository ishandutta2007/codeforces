#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n,q;
int a[maxn];
int foc[maxn],loc[maxn];
int v[maxn];
vector<int> ocr[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=q;i++){
        foc[i]=n+1;loc[i]=0;
    }
    for(int i=1;i<=n;i++){
        foc[a[i]]=min(foc[a[i]],i);
        loc[a[i]]=max(loc[a[i]],i);
        ocr[a[i]].push_back(i);
    }
    set<int> st;
    for(int i=1;i<=n;i++)st.insert(i);
    if(!loc[q]){
        bool t=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                st.erase(i);
                t=0;v[i]=q;break;
            }
        }
        if(t){cout<<"NO";return 0;}
    }
    for(int i=q;i>=1;i--){
        if(loc[i]){
            for(int j=0;j<ocr[i].size();j++){
                if(v[ocr[i][j]]){cout<<"NO";return 0;}
            }
            auto its=st.lower_bound(foc[i]),ite=st.upper_bound(loc[i]);
            for(auto it=its;it!=ite;it++){
                v[*it]=i;
            }
            st.erase(its,ite);
        }
    }
    for(int i=1;i<=n;i++)if(!v[i])v[i]=v[i-1];
    for(int i=n;i>=1;i--)if(!v[i])v[i]=v[i+1];
    cout<<"YES\n";
    for(int i=1;i<=n;i++)cout<<v[i]<<' ';
    return 0;
}