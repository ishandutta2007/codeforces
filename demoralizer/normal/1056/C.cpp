#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,t;
    cin>>n>>m;
    pair<int,int> p[m];
    map<int,int> z;
    int q[2*n+1];
    set< pair<int,int> > s;
    for(int i=0;i<2*n;i++){
        cin>>t;
        q[i+1]=t;
        s.insert({-t,i+1});
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        z[a]=b;
        z[b]=a;
        if(q[a]>q[b]){
            p[i]={a,b};
        }
        else{
            p[i]={b,a};
        }
    }
    cin>>t;
    if(t==1){
        int k=0;
        for(int i=0;i<n;i++){
            if(k){
                s.erase({-q[k],k});
            }
            if(m>0){
                m--;
                int a=p[m].fr;
                cout<<a<<"\n";
                s.erase({-q[a],a});
            }
            else{
                int a=(*s.begin()).sc;
                cout<<a<<"\n";
                s.erase({-q[a],a});
            }
            cout.flush();
            cin>>k;
        }
    }
    else{
        int k=0;
        for(int i=0;i<n;i++){
            cin>>k;
            s.erase({-q[k],k});
            if(m>0){
                m--;
                if(z.find(k)!=z.end()){
                    int a=z[k];
                    z.erase(k);
                    z.erase(a);
                    cout<<a<<"\n";
                    s.erase({-q[a],a});
                }
                else{
                    int a= (z.begin())->fr,b=(z.begin())->sc;
                    if(q[a]<q[b]){a=a+b;b=a-b;a=a-b;}
                    z.erase(a);
                    z.erase(b);
                    cout<<a<<"\n";
                    s.erase({-q[a],a});
                }
            }
            else{
                int a=(*s.begin()).sc;
                cout<<a<<"\n";
                s.erase({-q[a],a});
            }
            cout.flush();
        }
    }
}