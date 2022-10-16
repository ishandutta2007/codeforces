#include<bits/stdc++.h>
using namespace std;
vector<int>v[200003];
long long sum[200003];
int T,n,a,m,fa[200003],l[200003],r[200003],pt[200003],nn,mp[200003],bn[200003];
int fnd(int x){if(fa[x]!=x)fa[x]=fnd(fa[x]);return fa[x];}
int main(){
    cin>>T;
    while(T--){scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)
            sum[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            sum[i]+=a;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            sum[i]-=a;
        }
        for(int i=1;i<=n;i++)
            sum[i]+=sum[i-1];
        set<int>st,_st;
        nn=0;
        for(int i=0;i<=n;i++)
            if(sum[i]==0){
                st.insert(i);
                _st.insert(-i);
                mp[i]=nn;
                pt[nn++]=i;
            }pt[nn]=-1;
        for(int i=0;i<=n;i++)
            v[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",l+i,r+i);
            bn[i]=2;
            int L=mp[*st.lower_bound(l[i]-1)],R=mp[-(*_st.lower_bound(-r[i]))];
            if(pt[L]==l[i]-1)
                bn[i]--;
            else
                v[L-1].push_back(i);
            if(pt[R]==r[i])
                bn[i]--;
            else
                v[R].push_back(i);
            l[i]=L;r[i]=R-1;
        }
        if(sum[n]){cout<<"No\n";continue;}
        for(int i=0;i<nn;i++){
            fa[i]=i;
            if(pt[i]==pt[i+1]-1)
                fa[i]=i+1;
        }
        vector<int>q;
        for(int i=0;i<m;i++)
            if(bn[i]==0)
                q.push_back(i);
        while(q.size()){
            int i=q.back(),nw=l[i];
            q.pop_back();
            while(nw<=r[i]){
                if(fnd(nw)==nw){
                    for(int j=0;j<v[nw].size();j++){
                        bn[v[nw][j]]--;
                        if(!bn[v[nw][j]])
                            q.push_back(v[nw][j]);
                    }
                    fa[nw]=nw+1;
                }else
                    nw=fnd(nw);
            }
        }
        if(fnd(0)==nn-1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}