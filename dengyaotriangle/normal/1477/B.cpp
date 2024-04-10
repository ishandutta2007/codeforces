#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

struct node{
    int l,r,v;
    bool operator<(const node& a)const{
        return l<a.l;
    }
};
set<node> st;

set<node>::iterator spk(int f){
    auto it=st.lower_bound(node({f,0,0}));
    if(it!=st.end()&&it->l==f)return it;
    --it;
    int v=it->v,l=it->l,r=it->r;
    st.erase(it);
    st.insert(node({l,f,v}));
    return st.insert(node({f,r,v})).first;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        st.clear();
        string s,f;cin>>s>>f;
        for(int i=1;i<=n;i++)st.insert(node({i,i+1,f[i-1]-'0'}));
        vector<pair<int,int> >op(q);
        for(int i=0;i<q;i++){
            cin>>op[i].first>>op[i].second;
        }
        bool ok=1;
        for(int i=q-1;i>=0;i--){
            int l=op[i].first,r=op[i].second;
            spk(l);
            if(r!=n)spk(r+1);
            auto itl=spk(l),itr=r==n?st.end():spk(r+1);
            int c[2]={0,0};
            for(auto it=itl;it!=itr;it++){
                c[it->v]+=it->r-it->l;
            }
            st.erase(itl,itr);
            if(c[0]==c[1]){ok=0;break;}
            else st.insert(node({l,r+1,(int)(max_element(c,c+2)-c)}));
        }
        for(auto it=st.begin();it!=st.end();it++){
            for(int j=it->l;j<it->r;j++){
                if(it->v!=s[j-1]-'0'){ok=0;}
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}